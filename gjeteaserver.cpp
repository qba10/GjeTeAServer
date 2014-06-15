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
        this->jsonToSend[_J(_delete)];
        Json::Value arraySynchronize;
        Json::Value arrayDelete;
        vector <Object*> toDelete;
        //DataContainer::GarbageCollect();
        for(int i = 0 ; i <  DataContainer::ObjectLists.size(); i++){
//            cout << i << " " << DataContainer::ObjectLists.at(i) << endl;
            if(DataContainer::ObjectLists.at(i)->isActive()){
               DataContainer::ObjectLists.at(i)->update();
               DataContainer::ObjectLists.at(i)->appendBlockSyncTime(DataContainer::DeltaTime);
               if( DataContainer::ObjectLists.at(i)->isSyncEventActive()){
                   if(DataContainer::ObjectLists.at(i)->isSyncNow())
                        arraySynchronize.append(DataContainer::ObjectLists.at(i)->serialize());
               }else{
                   if(DataContainer::ObjectLists.at(i)->getBlockSyncTime() > DataContainer::ObjectLists.at(i)->getSyncPeriod() ){
                       arraySynchronize.append(DataContainer::ObjectLists.at(i)->serialize());
                       DataContainer::ObjectLists.at(i)->setBlockSyncTime(sf::milliseconds(0));
                   }
               }
            }else{
                arraySynchronize.append(Json::nullValue);
                arrayDelete.append(i);
                //cout << "add to delete: " << i << " %"<< DataContainer::ObjectLists.at(i)  <<  endl;
                toDelete.push_back(DataContainer::ObjectLists.at(i) );
            }
        }
        //  /**Delete pointers eqaul null*/
        for(vector<Object*>::iterator it=toDelete.begin(); it!=toDelete.end(); it++ )
        {
           // cout << *it << endl;
            for(vector<Object*>::iterator it2= DataContainer::ObjectLists.begin(); it2!= DataContainer::ObjectLists.end(); ++it2 ){
                if(*it2 == *it ){
                    DataContainer::ObjectLists.erase(it2);
                    break;
                }
            }
           delete *it;
       }

        this->jsonToSend[_J(_synchronize)] = arraySynchronize;
        this->jsonToSend[_J(_delete)] = arrayDelete;
    }



    sf::Packet GjeTeAServer::getPacketToSend()
    {

        if(this->jsonToSend[_J(_synchronize)] != Json::nullValue){
        Json::FastWriter writer;
      // cout << this->jsonToSend << endl;
        this->packetToSend.clear();
        this->packetToSend << writer.write(this->jsonToSend);
        }

        return this->packetToSend;
    }
}
