//p147_6번 3. 구구단, 곱셈, 덧셈 게임 선택 프로그램 생성.
#include "3.h"
void gugudan(){
    int number,result,count=0;
    std::cout<<"구구단 몇 단을 입력하시겠습니까?: ";
    std::cin>>number;
    for(int i=1;i<10;i++){
        std::cout << number << " x " << i << " = ";
        std::cin >> result;
        if(result == number*i){
            count++;
        }
    }
    std::cout << std::endl;
    std::cout<<"총 9개에서 "<<count<<"개 맞추셨습니다!";
}

bool m_step(){
    int result;
    int a=rand()%90+10, b=rand()%90+10;
    std::cout << a << " x " << b << " = ";
    std::cin >> result;
    return (result==(a*b)); 
}
void multiplication(){
    if(false==m_step()){
        std::cout<<std::endl<<"틀렸습니다."<<std::endl<<std::endl;
    }
    else {
        std::cout<<std::endl<<"맞았습니다."<<std::endl<<std::endl;
    }
    
}
bool a_step(){  
    int result;

    //시드 설정 및 엔진 준비
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(100, 999999999);  //std::uniform_int_distribution<int>      정수 형태의 균등 분포 필터를 만들겠다는 의미.

    int a = dis(gen); //gen=진짜 무작위의 수, dis(min,max)= 설정해놓은 100~9억 사이의 숫자들만 할 수 있게 일종의 필터.
    int b = dis(gen);

    std::cout << a << " + " << b << " = ";
    std::cin >> result;
    return (result==(a+b)); 
}
void addition(){
    if(false==a_step()){
        std::cout<< std::endl<<"틀렸습니다."<<std::endl<<std::endl;
    }
    else {
        std::cout<< std::endl<<"맞았습니다."<<std::endl<<std::endl;
    }
}
//함수 정의


int main(){
    int n;
    std::cout << "[게임을 선택해주세요.]" <<std::endl << std::endl;
    std::cout << "1: 구구단\t2: 두 자리 수 곱셈\t3: 3~9자리 수 덧셈" << std::endl;
    std::cin>>n;
    system("clear");

    if(n==1){
        gugudan(); //함수 호출
    }
    else if(n==2){
        srand((unsigned)time(NULL));
        multiplication(); //함수 호출
    }
    else {
        srand((unsigned)time(NULL));
        addition(); //함수 호출
    }

    return 0;
}