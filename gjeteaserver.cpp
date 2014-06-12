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
        this->jsonToSend[_J(_objectAmount)] = (int)DataContainer::ObjectLists.size();
        this->jsonToSend[_J(_synchronize)];
        Json::Value array;
        for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){

           DataContainer::ObjectLists.at(i)->update();
           DataContainer::ObjectLists.at(i)->appendBlockSyncTime(DataContainer::DeltaTime);
           if( DataContainer::ObjectLists.at(i)->isSyncEventActive()){
               if(DataContainer::ObjectLists.at(i)->isSyncNow())
                    array.append(DataContainer::ObjectLists.at(i)->serialize());
           }else{
               if(DataContainer::ObjectLists.at(i)->getBlockSyncTime() > DataContainer::ObjectLists.at(i)->getSyncPeriod() ){
                   array.append(DataContainer::ObjectLists.at(i)->serialize());
                   DataContainer::ObjectLists.at(i)->setBlockSyncTime(sf::milliseconds(0));
               }
           }
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
