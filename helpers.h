#ifndef HELPERS_H
#define HELPERS_H
namespace SSJServer {
    class Helpers
    {
    public:
        Helpers();
        template <typename T>
        char * compressData(T data);
        template <typename T>
        T decompressData(char * data);
    };
}
#endif // HELPERS_H
