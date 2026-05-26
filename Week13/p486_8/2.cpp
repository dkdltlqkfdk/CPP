#include "1.hpp"
void Sample1::play(){
    std::cout<<"1번 sample"<<std::endl;
}

void Sample2::play(){
    std::cout<<"2번 sample"<<std::endl;
}

void Sample3::play(){
    std::cout<<"3번 sample"<<std::endl;
}
void Sample4::play(){
    std::cout<<"4번 sample"<<std::endl;
}

int main(){
    Sample1* arr[4]; //포인터 배열은 클래스의 소속된 객체의 주소를 담아 동적 메모리 할당을 구현가능케 함.
    Sample1* a=new Sample1(); //키워드 new를 사용해 런타임 중 가상 공간 heap을 크기만큼 제공. 생성자를 호출해 클래스 Sample1타입의 객체 생성. 이 객체에 동적 메모리가 할당하고 이 주소는 클래스 타입의 포인터 변수 a와 연결됨.
//힙 메모리 공간(heap)과 포인터 변수 메모리 공간(stack)은 엄연히 다른 공간이고 주소만 연결.
    Sample2* b=new Sample2();
    Sample3* c=new Sample3();
    Sample4* d=new Sample4();

    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    arr[3]=d;
    for(int i=0;i<4;i++){
        arr[i]->play();
    }
    return 0;
}

//(3) Sample2타입의 객체 주소만 저장되는 배열이 되어 하나의 반복문으로 실행이 불가능.