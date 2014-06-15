#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
namespace SSJServer {

        template <typename T>
      const char * compressData(T data)   {
            char * result = new char[sizeof(T)+1];
            result[sizeof(T)] = '\0';
            T* pointerTyep = &data;
            char * charPointer =  (char*) pointerTyep;
            for(int i = 0; i < sizeof(T); i++){
                result[i] += *(charPointer+i);
            }
            return result;

        }
        template <typename T>
         T decompressData(const char * data)    {
            T *result = new T;
            char * pointerType = (char*) result;
            for(int i = 0; i < sizeof(T); i++){
                *(pointerType+i) = data[i] ;
            }
            result = (T*) pointerType;
            cout <<"d: " <<*result << endl;
            return *result;

        }
        class Helpers{
        public:
          static  bool valueInRange(int value, int min, int max)
            { return (value >= min) && (value <= max); }

          static  bool checkCollision(sf::Rect<float> A, sf::Rect<float> B)
            {
                bool xOverlap = valueInRange(A.left, B.left, B.left + B.width) ||
                                valueInRange(B.left, A.left, A.left + A.width);

                bool yOverlap = valueInRange(A.top, B.top, B.top + B.height) ||
                                valueInRange(B.top, A.top, A.top + A.height);

                return xOverlap && yOverlap;
            }

        };
    }

#endif // HELPERS_H
