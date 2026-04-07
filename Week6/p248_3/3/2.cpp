#include "1.hpp"
void addTime(MyTime t1, MyTime t2, MyTime* pt){
    int i=(t1.m+t2.m)/60;

    if((t1.m+t2.m)>=60){
        
        pt->h=t1.h+t2.h+i;
        (*pt).m=(t1.m+t2.m)-(60*i);
    }
    else{
        (*pt).h=t1.h+t2.h;
        pt->m=(t1.m+t2.m);
    }
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

    std::cout<<"\n----------------------------\n(add) ";
    addTime(t1,t2,&result);
    std::cout<< result.h<<"h "<< result.m<<"m\n"<<std::endl;
    return 0;
}