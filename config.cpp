#include "config.h"
namespace SSJServer {
     size_t Config::RotationSpeed = 360;
     string intToString(int value)
     {
         ostringstream ss;
         ss << value;
         return ss.str();
     }


}
