#include <iostream>
#include <iomanip> // setw, setfill
class MyTime {
    private:
        int hour, min, sec, msec;

    public:
        //1. 멤버 초기화 리스트 하지 않은 경우(생성자 내 대입 방식)
        /*MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) {
            hour = h; 
            min = m;  
            sec = s;
            msec = ms;
        }*/

        //2. 멤버 초기화 리스트 한 경우
        MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) : hour(h), min(m), sec(s), msec(ms) {}
        //긴 문자열과 대용량 배열 같은 경우 대입 방식에서 임시 객체가 생성되거나 중복된 메모리 쓰기 작업이 발생할 수 있어 중간에 거쳐가는 단계가 없는 초기화 리스트가 적절하고. const멤버나 참조자 멤버는 대입이 아예 불가능한 변수기 때문에 메모리 효율 면이나 반드시 써야 되는 점에서 멤버 초기화 리스트가 유리.
        
        void convert(double duration);
        void print();                        
        MyTime add(MyTime t2);
        void reset();
        void read();
};