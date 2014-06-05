#include "clientlistener.h"
#include "objectmanager.h"
namespace SSJServer {
    void ClientListener::setPort(int port)
    {
        cout << "Selected port: " << port << endl;
        listener.listen(port);
    }

    ClientListener::ClientListener()
    {

        this->setPort(2005);
        selector.add(listener);
    }

    void ClientListener::setPacketToSend(sf::Packet packet)
    {
        this->sendPacket = packet;
    }

    void ClientListener::Listener()
    {
        if(selector.wait(sf::seconds( 0.1 )))

        {
            if(selector.isReady(listener))
            {
                sf::TcpSocket *socket = new sf::TcpSocket;
                listener.accept(*socket);
                sf::Packet packet;
                std::string id;
                if(socket->receive(packet) == sf::Socket::Done)
                    packet >> id;

                std::cout << id << " has connected to server" << std::endl;
                clients.push_back(socket);
                selector.add(*socket);
            }
            else
            {
                for(int i = 0; i < clients.size(); i++)
                {

                    if(selector.isReady(*clients[i]))
                    {
                        sf::Packet packet;

                        if(clients[i]->receive(packet) == sf::Socket::Done)
                        {
                            std::string text;
                            packet >> text;
                           // cout << text << endl;
                            Json::Value root;
                            Json::Reader reader;
                            reader.parse(text, root, false);
                            switch(static_cast<RequestName>(root[_ask].asInt())){
                                case _createMainPlayer:
                                    ObjectManager::CreatePlayer(root[_playerId].asString());
                                break;
                                case _synchronizeMainPlayer:
                                    dynamic_cast<MainPlayer*>(DataContainer::PlayerList[root[_playerId].asString()])->SynchronizeWithClientOwner(root["parametres"]);

                            }
                        }
                    }
                }
            }
        }
    }

    void ClientListener::SenderToClients()
    {

        for(int i = 0; i < clients.size(); i++)
        {


            clients[i]->send(this->sendPacket);
        }

    }

    void ClientListener::CleanConnections()
    {
        for(std::vector<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); it++)
            delete *it;
    }

}
