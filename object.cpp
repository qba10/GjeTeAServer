#include "object.h"
namespace SSJServer {
	

    Object::Object(float x, float y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
        this->setDefaultVar();


    }

    Object::Object(Point position){
        this->mapPosition = position;
        this->setDefaultVar();

    }


    bool Object::isSyncNow() const
    {
        return syncNow;
    }

    void Object::setSyncNow(bool value)
    {
        syncNow = value;
    }

    bool Object::isSyncEventActive() const
    {
        return syncEventActive;
    }

    void Object::setSyncEventActive(bool value)
    {
        syncEventActive = value;
    }

    void Object::appendBlockSyncTime(sf::Time delta)
    {
        this->blockSyncTime += delta;
    }

    sf::Time Object::getBlockSyncTime() const
    {
        return blockSyncTime;
    }

    sf::Time Object::getSyncPeriod() const
    {
        return this->syncPeriod;
    }

    void Object::setBlockSyncTime(const sf::Time &value)
    {
        blockSyncTime = value;
    }

    void Object::setSyncNow()
    {
        this->syncNow = true;
    }
    void Object::setDefaultVar()
    {
        this->syncPeriod = sf::milliseconds(15);
        this->syncEventActive = false;
        this->syncNow = false;
        this->blockSyncTime = sf::milliseconds(0);
    }

    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;
        this->setDefaultVar();

    }

    Point Object::getMapPosition(){
        return mapPosition;
    }

    void Object::setMapPosition(float x, float y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
    }

    void Object::setMapPosition(Point position){
        this->mapPosition = position;
    }

    Json::Value Object::serialize()
    {
		return Json::nullValue;
	}


	void DataContainer::GarbageCollect()
	{
        for(int i = 0 ; i < DataContainer::ObjectLists.size() ; ++i)
		{
            if(DataContainer::ObjectLists.at(i) != NULL){
                if (!DataContainer::ObjectLists.at(i)->isActive() )
                {
                    delete DataContainer::ObjectLists.at(i);
                    DataContainer::ObjectLists.at(i) = NULL;
                }
            }
        }
	}

    void Object::setActivity(bool activity){
        this->activity = activity;
    }

    bool Object::isActive(){
        return activity;
    }


}

