#include "dynamicobject.h"

namespace SSJServer {
    DynamicObject::DynamicObject(): InteractiveObject()
    {
        this->velocity = 0.0;
        this->angle = 0.0;
        this->targetAngle = 0.0;
    }

    
    size_t DynamicObject::getVelocity() const
    {
        return velocity;
    }
    
    void DynamicObject::setVelocity(const size_t &value)
    {
        velocity = value;
    }
    void DynamicObject::MoveForward(){
        this->setMapPosition(CalcNewPosition(this->angle+0));
    }
    
    void DynamicObject::MoveBackward(){
        this->setMapPosition(CalcNewPosition(this->angle+180));
    }

    void DynamicObject::MoveLeft(){
        this->setMapPosition(CalcNewPosition(this->angle+270));
    }

    void DynamicObject::MoveRight(){
        this->setMapPosition(CalcNewPosition(this->angle+90));
    }

    void DynamicObject::RotateLeft(){
        float deltaAngle = Config::RotationSpeed * DataContainer::DeltaTime.asSeconds();
        bool a;
        if(this->targetAngle.getDegrees() - this->angle.getDegrees() < 0)
            a = true;
        else
            a = false;

        /** czy przeszło przez zero by Łysy**/
        if(this->angle.getDegrees() * (this->angle.getDegrees() - deltaAngle) < 0){
            a = !a;
        }

        if(((this->targetAngle.getDegrees() - this->angle.getDegrees()- deltaAngle ) < 0 ) != a)
            this->angle = this->targetAngle;
        else
            this->angle -= deltaAngle;
    }

    void DynamicObject::RotateRight(){
        float deltaAngle = Config::RotationSpeed * DataContainer::DeltaTime.asSeconds();
        bool a;
        if(this->targetAngle.getDegrees() - this->angle.getDegrees() < 0)
            a = true;
        else
            a = false;

        /** czy przeszło przez zero by Łysy**/
        if(this->angle.getDegrees() * (this->angle.getDegrees() + deltaAngle) < 0){
            a = !a;
        }

        if(((this->targetAngle.getDegrees() - this->angle.getDegrees() + deltaAngle ) < 0 ) != a)
            this->angle = this->targetAngle;
        else
            this->angle += deltaAngle;
    }

    Point DynamicObject::CalcNewPosition(SSJServer::Degrees addAngle){

        Point newPosition = this->getMapPosition();
        SSJServer::Degrees tempDegrees = this->angle;
        tempDegrees += addAngle;
        float s = this->velocity * DataContainer::DeltaTime.asSeconds();
        float px = sin(tempDegrees.getRadians()) * s;
        float py = cos(tempDegrees.getRadians()) * s;
        newPosition.x += px;
        newPosition.y -= py;
        return newPosition;
    }




	Degrees DynamicObject::getAngle(){
		return this->angle;
	}

    Json::Value DynamicObject::serialize()
    {

        return Json::nullValue;
	}
}

