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
    frags = 0;
    this->velocity = 200.0;
		this->setHP(this->getMaxHP());
		this->isFiring = false;

    }  



    void MainPlayer::update(){
        if(this->isDead()){
            this->setMapPosition(640,640);
            this->setHP(100);
            this->frags++;
        }
        if(this->frags == 10)
        {
            for(map<string, Object*>::iterator it = DataContainer::PlayerList.begin() ; it != DataContainer::PlayerList.end() ; it++)
            {
                ((MainPlayer*)it->second)->setMapPosition(640,640);
                ((MainPlayer*)it->second)->setHP(100);
                ((MainPlayer*)it->second)->frags = 0;
            }
        }
    }

    void MainPlayer::SynchronizeWithClientOwner(Json::Value jsonObject){
        if(jsonObject.isMember(_J(_mapPositionX))){
            this->mapPosition.x = jsonObject[_J(_mapPositionX)].asFloat();
        }
        if(jsonObject.isMember(_J(_mapPositionY))){
            this->mapPosition.y = jsonObject[_J(_mapPositionY)].asFloat();
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
            this->angle = jsonObject[_J(_angle)].asFloat();
        }
        if(jsonObject.isMember(_J(_targetAngle))){
            this->targetAngle = jsonObject[_J(_targetAngle)].asFloat();
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
		   object[_J(_syncId)] = this->syncId;
           object[_J(_deaths)] = this->frags;
           if(this->syncEventActive)
                this->syncNow = false;
        return object;
    }



}

