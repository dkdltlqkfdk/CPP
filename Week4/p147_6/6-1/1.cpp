//p147 6번-1. 
#include "1.h"
bool additionstep(){  //playGuguOnce() 3참고.       bool형, true나 false 리턴.
    int result;
    int a=rand() %999 +1; int b=rand()%999 +1;  //범위 1~999,      랜덤 최솟값=1, 0~998 ---->(+1) 1~999
    printf("%d + %d = ",a,b);
    scanf("%d",&result);
    return (result==(a+b)); //true=1, false=0       bool형은 연산식을 리턴할 경우 값이 반환되는 것이 아닌 ==기준 왼오를 비교, true나 false를 반환.
}
void addition(){
    if(false==additionstep()){
        printf("\n틀렸습니다.\n\n");
    }
    else {
        printf("\n정답입니다.\n\n");
    }
}
int main(){
    srand((unsigned)time(NULL)); //랜덤이 랜덤이 아니기 때문에 난수 생성치 초기화 필요.
    printf("[여러 자리의 덧셈 문제를 맞추세요.]\n");
    addition();
    return 0;
}