#include "gjeteaserver.h"

namespace SSJServer {
    GjeTeAServer::GjeTeAServer()
    {
       // ObjectManager::CreatePlayer();
       this->clock.restart();
    }

    void GjeTeAServer::Update(){
        DataContainer::DeltaTime = this->clock.getElapsedTime();
        this->clock.restart();
        this->CreatePacketToSend();
    }

    void GjeTeAServer::CreatePacketToSend()
    {
        ostringstream ss;
        this->jsonToSend[_J(_objectAmount)] = (int)DataContainer::ObjectLists.size();
        this->jsonToSend[_J(_synchronize)];
        Json::Value array;
        for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){
            ss << i;
           DataContainer::ObjectLists.at(i)->update();
           array.append(DataContainer::ObjectLists.at(i)->serialize());
        }
        this->jsonToSend[_J(_synchronize)] = array;
    }



    sf::Packet GjeTeAServer::getPacketToSend()
    {

        Json::FastWriter writer;
        this->packetToSend.clear();
        this->packetToSend << writer.write(this->jsonToSend);
        return this->packetToSend;
    }
}
