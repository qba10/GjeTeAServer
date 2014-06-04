#ifndef STATICOBJECT_H
#define STATICOBJECT_H
#include "object.h"
namespace SSJServer{
    class StaticObject : public Object
    {
    public:
        StaticObject();
        void update();
    };
}
#endif // STATICOBJECT_H
