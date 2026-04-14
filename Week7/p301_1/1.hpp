#include <iostream>
class MyTime {
    private:
        int hour, min, sec, msec;

    public:
        void convert(double duration);
        void print();
        MyTime add(MyTime t2);
        void reset();
};
