#ifndef CLIENTLISTENER_H
#define CLIENTLISTENER_H
#include "datacontainer.h"
using namespace std;
namespace SSJServer {

    class ClientListener
    {
    private:
        int port;
        sf::TcpListener listener;
        sf::SocketSelector selector;
        std::vector<sf::TcpSocket*> clients;
        sf::Packet sendPacket;
    private:
        void setPort(int);

    public:
        ClientListener();
        void setPacketToSend(sf::Packet);
        void Listener();
        void SenderToClients();
        void CleanConnections();
    }; 
}
#endif // CLIENTLISTENER_H
