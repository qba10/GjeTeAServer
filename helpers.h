#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
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
    }

#endif // HELPERS_H
