#include "1.hpp"

void addTime(MyTime t1, MyTime t2, MyTime& t3){

}

int main(){
    MyTime t1,t2,result;

    std::cout<<"(t1)\nh: ";
    std::cin>>t1.h;
    std::cout<<"m: ";
    std::cin>>t1.m;

    std::cout<<"\n";

    std::cout<<"(t2)\nh: ";
    std::cin>>t2.h;
    std::cout<<"m: ";
    std::cin>>t2.m;

    result=addtime(t1,t2);
    std::cout<<"\n----------------------------\n(add) ";
    std::cout<< result.h<<"h "<< result.m<<"m\n"<<std::endl;
    return 0;
}