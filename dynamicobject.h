#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include "interactiveobject.h"
namespace SSJServer {


    class DynamicObject : public InteractiveObject
    {
	protected:
        /*for synchronization by server*/
		size_t velocity; // px per second
		Degrees angle;
		Degrees targetAngle;
    public:
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void RotateLeft();
        void RotateRight();
        Point CalcNewPosition( SSJServer::Degrees);
		Degrees getAngle();
        DynamicObject();
        Json::Value serialize();


    };
}
#endif // DYNAMICOBJECT_H
 