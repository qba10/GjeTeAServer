#ifndef BULLET_H
#define BULLET_H
#include "dynamicobject.h"

namespace SSJServer{
    class Bullet : public DynamicObject{
    public:
		
		Bullet();
		~Bullet();
		void update();
		void Blast();
		void Hit();
		Point CalcNewPosition();

		Point ownerPosition;
		Point bulletPosition;
		string name;
        WeaponType type;
		Degrees angle;
		int range;
		int damage;
		bool blastFire;
		int blastRange;
		Json::Value serialize(); 
        Degrees getAngle() const;
        void setAngle(const Degrees &value);
        WeaponType getType() const;
        void setType(const WeaponType &value);
    };
}
#endif
