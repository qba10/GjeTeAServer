#include "gjeteaserver.h"

namespace SSJServer {
    GjeTeAServer::GjeTeAServer()
    {
       // ObjectManager::CreatePlayer();
    }

    void GjeTeAServer::Update(){
        this->CreatePacketToSend();
    }

    void GjeTeAServer::CreatePacketToSend()
    {
        ostringstream ss;
        this->jsonToSend["objectNumber"] = (int)DataContainer::ObjectLists.size();
        this->jsonToSend["synchronize"];
        Json::Value array;
        for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){
            ss << i;
           DataContainer::ObjectLists.at(i)->update();
           array.append(DataContainer::ObjectLists.at(i)->serialize());
        }
        this->jsonToSend["synchronize"] =array;
    }
	 


    sf::Packet GjeTeAServer::getPacketToSend()
    {
        Json::StyledWriter writer;
        this->packetToSend.clear();
        this->packetToSend << writer.write(this->jsonToSend);
        return this->packetToSend;
    }
}
