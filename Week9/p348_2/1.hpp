#include <iostream>
#include <iomanip> // setw, setfill
class MyTime {
    private:
        int hour, min, sec, msec;

    public:
        //함수 중복을 이용해서 생성자 구현
        MyTime(double duration= 0.0){
            convert(duration); 
        }
        void convert(double duration);
        void print();                        
        MyTime add(MyTime t2);
        void reset();
        void read();
};