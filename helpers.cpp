#include "helpers.h"

namespace SSJServer {

    template <typename T>
    char * compressData(T data)
    {
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
    T decompressData(char * data)
    {
        T *result = new T;
        char * pointerType = (char*) result;
        for(int i = 0; i < sizeof(T); i++){
            *(pointerType+i) = data[i] ;
        }
        result = (T*) pointerType;
        return *result;

    }

}
