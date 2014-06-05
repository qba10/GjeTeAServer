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
		Degrees angle;
		int range;
		int bulletSpeed;
		int damage;
		bool blastFire;
		int blastRange;
		Json::Value serialize(); 
	};
}
#endif
