#ifndef CONFIG_H
#define CONFIG_H
#include "loader.h"
namespace SSJServer{
	enum WeaponType{	
		Glock,
		Uzi,
		Ak47,
		M16,
		Shotgun,
		SniperRifle,
		Bazooka,
		Grenade,
		Knife
};

enum ObjectType{
        _Object,
        _InteractiveObject,
        _StaticObject,
        _DynamicObject,
        _MainPlayer,
        _Player,
		_Bullet,
		_Weapon

}; 
    class Object;
    class Config
    {
    public:
       static size_t RotationSpeed;
    };
}

#endif // CONFIG_H
