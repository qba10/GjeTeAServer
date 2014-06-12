#include "Bullet.h"
namespace SSJServer{



	Bullet::Bullet(){
		this->bulletPosition = ownerPosition;
	}

	Bullet::~Bullet(){

	}



	void Bullet::update(){
        if( (pow(this->getMapPosition().x - ownerPosition.x, 2) + pow(this->getMapPosition().y - ownerPosition.y, 2)) <= pow(this->range, 2)){

            this->setMapPosition(CalcNewPosition());

            this->activity = true;
        }
        else{
            if(this->blastFire){
                this->blastFire = false;
            }
            this->activity = false;
            this->setSyncNow();

        }
	}

	void Bullet::Blast(){

	}

	void Bullet::Hit(){

	}

    Point Bullet::CalcNewPosition(){

        Point newPosition = this->getMapPosition();
        Degrees tempDegrees = this->angle;
        float s = this->velocity *100 * DataContainer::DeltaTime.asSeconds();
        float px = sin(tempDegrees.getRadians()) * s;
        float py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
    }
    WeaponType Bullet::getType() const
    {
        return type;
    }

    void Bullet::setType(const WeaponType &value)
    {
        type = value;
    }

    Degrees Bullet::getAngle() const
    {
        return angle;
    }

    void Bullet::setAngle(const Degrees &value)
    {
        angle = value;
    }

    Json::Value Bullet::serialize()
    {
        Json::Value object;
        object[_J(_objectName)] = _Bullet;
        object[_J(_mapPositionX)] =  this->getMapPosition().x;
        object[_J(_mapPositionY)] =  this->getMapPosition().y;
        object[_J(_activity)] = this->activity;
        object[_J(_angle)] = this->getAngle().getDegrees();
        object[_J(_targetAngle)] = this->targetAngle.getDegrees();
        object[_J(_name)] = this->name;
        object[_J(_weaponType)] = this->getType();
        object[_J(_syncId)] = this->syncId;
        if(this->syncEventActive)
             this->syncNow = false;
        return object;
    } 

}
