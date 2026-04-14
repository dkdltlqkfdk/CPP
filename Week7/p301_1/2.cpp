#include "1.hpp"


inline void MyTime::convert(double duration){
    int d=int(duration);
    hour=(d/3600);
    min=(d%3600)/60;
    sec=(d%3600)%60;
    msec=(duration-d)*1000;
}
            
inline void MyTime::print(){
    std::cout<<hour<<":"<<min<<":"<<sec<<":"<<msec;
}
inline MyTime MyTime::add(MyTime t2){
    MyTime t3;
    t3.hour=hour+t2.hour;
    t3.min=min+t2.min;
    t3.sec=sec+t2.sec;
    t3.msec=msec+t2.msec;

    if (t3.msec >= 1000) {
        t3.sec += (t3.msec / 1000); // 1000ms당 1초 올림
        t3.msec %= 1000;            // 남은 밀리초 저장
    }
    if (t3.sec >= 60) {
        t3.min += (t3.sec / 60);    // 60초당 1분 올림
        t3.sec %= 60;
    }
    if (t3.min >= 60) {
        t3.hour += (t3.min / 60);   // 60분당 1시간 올림
        t3.min %= 60;
    }

    return t3;
}

inline void MyTime::reset() { 
    hour = min = sec = msec = 0; 
}


int main(){
    MyTime t1,t2,t3;
    double duration,d2;

    std::cout<<"초 단위의 실수형 시간을 입력하시오: ";
    std::cin>>duration;
    t1.convert(duration);
    t1.print();
    std::cout<<"\n\n";

    std::cout<<"더하고 싶은 초 단위 실수형으로 입력하시오: ";
    std::cin>>d2;
    t2.convert(d2);
    std::cout<<"\n\n";

    t3=t1.add(t2);
    std::cout<<"더한 시간은? ";
    t3.print();
    std::cout<<"\n\n";

    t1.reset();t2.reset();t3.reset();
    return 0;
}