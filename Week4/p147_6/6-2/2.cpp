
//p147 6번-2. 마찬가지로 두 자리 수 곱셈 문제를 함수로 구현하라.
#include "2.h"
bool m_step(){
    int result;
    int a=rand()%90+10,b =rand()%90+10; //범위 10~99
    printf("%d * %d = ",a,b);
    scanf("%d",&result);
    return (result==(a*b)); 
}
void m(){
    if(false==m_step()){
        printf("\n틀렸습니다.\n\n");
    }
    else {
        printf("\n정답입니다.\n\n");
    }
}
int main(){
    srand((unsigned)time(NULL)); 
    printf("[두 자리 수 곱셈 문제를 맞추세요.]\n");
    m();
    return 0;
}