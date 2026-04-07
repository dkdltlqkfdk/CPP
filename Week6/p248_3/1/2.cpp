//1. MyTime addtime (MyTime t1, MyTime t2)
#include "1.hpp"


MyTime addtime(MyTime t1,MyTime t2){
    MyTime result;
    int i=(t1.minute+t2.minute)/60;
    if((t1.minute+t2.minute)>=60){
        
        result.hour=t1.hour+t2.hour+i;
        result.minute=(t1.minute+t2.minute)-(60*i);
    }
    else{
        result.hour=t1.hour+t2.hour;
        result.minute=(t1.minute+t2.minute);
    }
    return result;
}

int main(){
    MyTime t1,t2,result;

    std::cout<<"(t1)\nh: ";
    std::cin>>t1.hour;
    std::cout<<"m: ";
    std::cin>>t1.minute;

    std::cout<<"\n";

    std::cout<<"(t2)\nh: ";
    std::cin>>t2.hour;
    std::cout<<"m: ";
    std::cin>>t2.minute;

    result=addtime(t1,t2);
    std::cout<<"\n----------------------------\n(add) ";
    std::cout<< result.hour<<"h "<< result.minute<<"m\n"<<std::endl;
    return 0;
}