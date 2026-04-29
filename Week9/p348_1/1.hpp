#include <iostream>
#include <iomanip> // setw, setfill
class MyTime {
    private:
        int hour, min, sec, msec;

    public:
        //1. 멤버 초기화 리스트 하지 않은 경우(생성자 내 대입 방식)
        /*MyTime(double duration= 0.0){
            convert(duration); 
        }*/

        
        //2. 멤버 초기화 리스트 한 경우
        //read함수에서 초단위 실수형으로 입력받고 convert함수에서 매개변수 hour,min,sec,msec을 할당?하는 과정을 유지하기 위해 가독성이 떨어지지만 작성. 
        MyTime(double duration = 0.0) : hour(int(duration) / 3600), min((int(duration) % 3600) / 60), sec(int(duration) % 60), msec((duration - int(duration)) * 1000) {}
        //긴 문자열과 대용량 배열 같은 경우 대입 방식에서 임시 객체가 생성되거나 중복된 메모리 쓰기 작업이 발생할 수 있어 중간에 거쳐가는 단계가 없는 초기화 리스트가 적절하고. const멤버나 참조자 멤버는 대입이 아예 불가능한 변수기 때문에 메모리 효율 면이나 반드시 써야 되는 점에서 멤버 초기화 리스트가 유리.
        void convert(double duration);
        void print();                        
        MyTime add(MyTime t2);
        void reset();
        void read();
};