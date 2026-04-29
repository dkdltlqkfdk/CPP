#include "1.hpp"


inline void MyTime::convert(double duration){
    int d=int(duration);
    hour=(d/3600);
    min=(d%3600)/60;
    sec=(d%3600)%60;
    msec=(duration-d)*1000;
}
            
inline void MyTime::print(){   
    /*std::cout<<hour<<":"<<min<<":"<<sec<<":"<<msec;*/       //(1) 표준 출력 객체 cout를 사용해  구현하기 전 멤버 함수 print()
    std::cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << min  << ":" << std::setw(2) << sec  << ":" << std::setw(3) << msec;
}                                                             //(3)

inline MyTime MyTime::add(MyTime t2){
    MyTime t3;
    t3.hour=hour+t2.hour;
    t3.min=min+t2.min;
    t3.sec=sec+t2.sec;
    t3.msec=msec+t2.msec;

    if (t3.msec >= 1000) {
        t3.sec += (t3.msec / 1000); 
        t3.msec %= 1000;           
    }
    if (t3.sec >= 60) {
        t3.min += (t3.sec / 60); 
        t3.sec %= 60;
    }
    if (t3.min >= 60) {
        t3.hour += (t3.min / 60);   
        t3.min %= 60;
    }

    return t3;
}

inline void MyTime::reset() { 
    hour = min = sec = msec = 0; 
}

inline void MyTime::read() {                                     //(4)
    double duration;
    std::cout<<"초 단위의 실수형 시간을 입력하시오: ";
    std::cin>>duration;
    convert(duration);
}

int main(){
    MyTime t1,t2,t3;

    t1.read();
    t1.print();
    std::cout<<"\n\n";

    t2.read();
    std::cout<<"\n\n";

    t3=t1.add(t2);
    std::cout<<"더한 시간은? ";
    t3.print();
    std::cout<<"\n\n";

    t1.reset();t2.reset();t3.reset();
    return 0;
}

//(5). 소스파일 구현