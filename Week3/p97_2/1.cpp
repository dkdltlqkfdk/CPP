//page 97, 2-1, (10000미만 정수라면서 예시는 10000이상을 들고 있네) 10000 이상의 정수를 입력. 단위가 private에 저장되어야 할 듯?
/*일단 입력을 받고(입력 받는 것 조차 클래스 함수를 이용.) 클래스에서 그럼 그 숫자의 단위를 센다. 만약 5보다 적으면 다시 입력하라 퇴자, 5 이상 시 그대로 단위 입력.
그 단위를 세는 함수는 이후 클래스 안 print함수 안에 변수로 작용?해서 한글 출력 시 영향을 준다..*/

//제일 베스트는 10을 계속 나누는 것 보다 100, 1000을 나누는 게 중요할 것 같긴 한디..
//10을 곱한다? 조건 충족 시 계속 곱하고 이후 그걸로 입력 숫자와 나눠서 몫을 구한다? count++을 그때마다 하는 것보다 걍 그때마다 곱해버ㄹ..

//어렵다 다시 도전할 것.

#include<stdio.h>
class output {
    private:
        int number;
    public:
        void takeinput() {
            scanf("%d",&number);
        }
        int unitcentury(){
            int n=number;
            int unit=1;
            while(n >=10){
                n/=10;
                unit*=10;
            }
            return unit;
        }
        void print() {
            int u=unitcentury();
            while(u>=1){
                printf("%d",number/u);
                if(u==10000){
                    printf("만 ");
                }
                else if (u==1000){
                    printf("천 ");
                }
                else if (u==100){
                    printf("백 ");
                }
                else if (u==10){
                    printf("십 ");
                }
                number%=u;
                u/=10;
            }
        }
        
};
int main(){
    output num;
    num.takeinput();
    num.unitcentury();
    num.print();
}
