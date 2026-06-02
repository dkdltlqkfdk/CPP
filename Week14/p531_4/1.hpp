#include<iostream>
#include<ctime>
class SampleList{
    int list[100];
    public:
        SampleList();
        int& operator[](int index); //(1)
        int& operator()(int index); //(2)
        int& operator()(int x, int y); //(3)
};