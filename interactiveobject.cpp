#include "interactiveobject.h"


namespace SSJServer {

    InteractiveObject::InteractiveObject() : Object()
    {

        this->maxHP = 100;
        this->hp = 100;
    }

    void InteractiveObject::setHP(size_t hp)
    {
        if(this->maxHP <= hp && hp >= 0)
            this->hp = hp;
    }

    void InteractiveObject::setMaxHP(size_t hp)
    {
        this->maxHP = hp;
    }

    void InteractiveObject::addHP(size_t hp)
    {
     if(this->maxHP <= this->hp+hp && this->hp+hp >= 0)
         this->hp += hp;
    }

    void InteractiveObject::subHP(size_t hp)
    {
        if(this->maxHP <= this->hp-hp && this->hp-hp >= 0)
            this->hp -= hp;
    }

    size_t InteractiveObject::getHP()
    {
        return this->hp;
    }

    size_t InteractiveObject::getMaxHP()
    {
        return this->maxHP;
    }

    bool InteractiveObject::isDead(){
        if(this->hp == 0)
            return true;
        else
            return false;
    }
    Json::Value InteractiveObject::serialize()
    {
		return Json::nullValue;
    }

}
 