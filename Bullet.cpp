#include "Bullet.h"
namespace SSJServer{



	Bullet::Bullet(){
		this->bulletPosition = ownerPosition;
	}

	Bullet::~Bullet(){

	}



	void Bullet::update(){
	
	}

	void Bullet::Blast(){

	}

	void Bullet::Hit(){

	}

	Point Bullet::CalcNewPosition(){

		Point newPosition = this->getMapPosition();
        Degrees tempDegrees = this->angle;
        double s = this->bulletSpeed * DataContainer::DeltaTime.asSeconds();
        double px = sin(tempDegrees.getRadians()) * s;
        double py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
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

        return object;
    } 

}
