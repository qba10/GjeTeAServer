#include "object.h"
namespace SSJServer {
	

    Object::Object(double x, double y){
        this->mapPosition.x = x;
        this->mapPosition.y = y;
    }

    Object::Object(Point position){
        this->mapPosition = position;
    }

    Object::Object(){
        this->mapPosition.x = 0;
        this->mapPosition.y = 0;

    }

    Point Object::getMapPosition(){
        return mapPosition;
    }

    void Object::setMapPosition(double x, double y){
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



    void Object::setActivity(bool activity){
        this->activity = activity;
    }

    bool Object::isActive(){
        return activity;
    }


}
