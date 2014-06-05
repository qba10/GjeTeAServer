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
        if(jsonObject.isMember(_J(_mapPositionX))){
            this->mapPosition.x = jsonObject[_J(_mapPositionX)].asDouble();
        }
        if(jsonObject.isMember(_J(_mapPositionY))){
            this->mapPosition.y = jsonObject[_J(_mapPositionY)].asDouble();
        }
        if(jsonObject.isMember(_J(_activity))){
            this->activity = jsonObject[_J(_activity)].asBool();
        }
        if(jsonObject.isMember(_J(_hp))){
            this->hp = jsonObject[_J(_hp)].asUInt();
        }
        if(jsonObject.isMember(_J(_maxHP))){
            this->maxHP = jsonObject[_J(_maxHP)].asUInt();
        }
        if(jsonObject.isMember(_J(_velocity))){
            this->velocity = jsonObject[_J(_velocity)].asUInt();
        }
        if(jsonObject.isMember(_J(_angle))){
            this->angle = jsonObject[_J(_angle)].asDouble();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asDouble();
        }
    }

    Json::Value MainPlayer::serialize()
    {
        Json::Value object;
           object[_J(_objectName)] = _MainPlayer;
           object[_J(_playerId)] = this->getPlayerId();
           object[_J(_mapPositionX)] =  this->getMapPosition().x;
           object[_J(_mapPositionY)] =  this->getMapPosition().y;
           object[_J(_activity)] = this->activity;
           object[_J(_hp)] = (unsigned int)this->getHP();
           object[_J(_maxHP)] = (unsigned int)this->getMaxHP();
           object[_J(_velocity)] = (unsigned int)this->velocity;
           object[_J(_angle)] = this->getAngle().getDegrees();
           object[_J(_targetAngle)] = this->targetAngle.getDegrees();

        return object;
    }



}

