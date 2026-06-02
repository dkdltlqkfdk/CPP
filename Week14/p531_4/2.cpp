#include "1.hpp"
SampleList::SampleList(){
    for(int x=0; x<100;x++){
        list[x]=rand()%1000;
    }
}
int& SampleList::operator[](int index){ //(1)
    return list[index];
}
int& SampleList::operator()(int index){ //(2)
    return list[index];
}

int& SampleList::operator()(int x, int y){ //(3)
    return list[x*y];
}

int main(){
    srand(time(NULL));
    SampleList ls;
    
    std::cout<<"\n\n인덱스 연산자 중복을 통한 값: "<<ls[6]<<std::endl;
    std::cout<<"인자 1개, 함수 호출 연산자를 통한 값: "<<ls(2)<<std::endl;
    std::cout<<"====================================="<<std::endl;
    std::cout<<"인자 2개, 함수 호출 연산자를 통한 값: "<<ls(6,2)<<"\n\n"<<std::endl;
    return 0;
}