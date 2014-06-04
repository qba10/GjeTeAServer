#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include "dynamicobject.h"
namespace SSJServer{
    class MainPlayer : public DynamicObject
    {
    private:
		bool isFiring;
        string playerId;
	protected:

    public:
        MainPlayer();
        void update();
        Json::Value serialize();
        void SynchronizeWithClientOwner(Json::Value jsonObject);


        string getPlayerId() const;
        void setPlayerId(const string &value);
    };
}

#endif // MAINPLAYER_H
