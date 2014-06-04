#include "mainplayer.h"
namespace SSJServer {



string MainPlayer::getPlayerId() const
{
    return playerId;
}

void MainPlayer::setPlayerId(const string &value)
{
    playerId = value;
}
MainPlayer::MainPlayer(): DynamicObject()
{
    this->setActivity(true);
    this->setMaxHP(100);
    this->velocity = 200.0;
		this->setHP(this->getMaxHP());
		this->isFiring = false;






    }


    void MainPlayer::update(){

    }

    void MainPlayer::SynchronizeWithClientOwner(Json::Value jsonObject){
        if(jsonObject.isMember("mapPositionX")){
            this->mapPosition.x = jsonObject["mapPositionX"].asDouble();
        }
        if(jsonObject.isMember("mapPositionY")){
            this->mapPosition.y = jsonObject["mapPositionY"].asDouble();
        }
        if(jsonObject.isMember("activity")){
            this->activity = jsonObject["activity"].asBool();
        }
        if(jsonObject.isMember("hp")){
            this->hp = jsonObject["hp"].asUInt();
        }
        if(jsonObject.isMember("maxHP")){
            this->maxHP = jsonObject["maxHP"].asUInt();
        }
        if(jsonObject.isMember("velocity")){
            this->velocity = jsonObject["velocity"].asUInt();
        }
        if(jsonObject.isMember("angle")){
            this->angle = jsonObject["angle"].asDouble();
        }
        if(jsonObject.isMember("targetAngle")){
            this->targetAngle = jsonObject["targetAngle"].asDouble();
        }
    }

    Json::Value MainPlayer::serialize()
    {
        Json::Value object;
           object["objectName"] = _MainPlayer;
           object["playerID"] = this->getPlayerId();
           object["mapPositionX"] =  this->getMapPosition().x;
           object["mapPositionY"] =  this->getMapPosition().y;
           object["activity"] = this->activity;
           object["hp"] = (unsigned int)this->getHP();
           object["maxHP"] = (unsigned int)this->getMaxHP();
           object["velocity"] = (unsigned int)this->velocity;
           object["angle"] = this->getAngle().getDegrees();
           object["targetAngle"] = this->targetAngle.getDegrees();

        return object;
    }



}

