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
           object["objectName"] = _Bullet;
           object["mapPositionX"] =  this->getMapPosition().x;
           object["mapPositionY"] =  this->getMapPosition().y;
           object["activity"] = this->activity;
           object["angle"] = this->getAngle().getDegrees();
           object["targetAngle"] = this->targetAngle.getDegrees();
		   object["name"] = this->name;

        return object;
    } 

}