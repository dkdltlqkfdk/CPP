#include<iostream>
#include<cstring>
#define size 10
class Sample{
    private:
        static int count;
        char* name;
    public:
        Sample();
        Sample(const char* name); //(2)
        Sample(const Sample& s); //(4)
        ~Sample(); //(3)
        void printCount(); //(1)
};