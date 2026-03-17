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

//page 97, 2-2
//1. 입력을 받는다. 2. 10,100,1000,10000으로 나눌지 판단한다. 3. 나눈다, 동시에 2번에서 단위는 10을 계속 나눠주고 number을 재정의해준다.
#include<stdio.h>
class print {
    private:
        int number;
    public:
        void numinput(){
            scanf("%d",&number);
        } //1
        int unitcentury(){
            int unit=1;
            int temp=number; 
            /*입력 받은 수를 보호하기 위해 다른 변수값에 똑같이 저장할때 numinput()을 이퀄 뒤에 해야하는가, number을 그대로 써도 되는 건가.
            number은 지금 지역 변수개념이 아닌 생성자에 의해 private에 저장된 값이니 함수를 안해도 될 것 같긴함.*/
            while(temp >=10){
                unit*=10;
                temp/=10;
            }
            return unit; //2
        }
        void numoutput(){  //3
            int unit=unitcentury();
            int temp=number;
            while(unit>=1){
                if(temp/unit > 0){
                    printf("%d",temp/unit);
                    if(unit==10000){
                        printf("만 ");
                    }
                    else if (unit==1000){
                        printf("천 ");
                    }
                    else if (unit==100){
                        printf("백 ");
                    }
                    else if (unit==10){
                        printf("십 ");
                    }
                }
                temp%=unit;
                unit/=10;
            }

        }

};

int main(){
    print num;
    num.numinput(); //1
    num.unitcentury(); //2
    num.numoutput(); //3
    return 0;
}

//page 97, 2-3 
#include<stdio.h>
class print {
    private:
        int number;
    public:
        void numberinput(){
            scanf("%d",&number);
        }
        int unitcentury(){
            int unit=1,temp=number;
            while(temp >=10){
                unit*=10;
                temp/=10;
            }
            return unit;
        }
        void numberoutput(){
            int unit=unitcentury();
            int temp=number;
            while(unit>=1){
                if(temp/unit>1){
                    printf("%d",temp/unit);
                    if(unit==10000){
                        printf("만 ");
                    }
                    else if (unit==1000){
                        printf("천 ");
                    }
                    else if (unit==100){
                        printf("백 ");
                    }
                    else if (unit==10){
                        printf("십 ");
                    }
                }
                
                if (temp/unit==1){
                    if(unit==10000){
                        printf("만 ");
                    }
                    else if (unit==1000){
                        printf("천 ");
                    }
                    else if (unit==100){
                        printf("백 ");
                    }
                    else if (unit==10){
                        printf("십 ");   //한글 단위 출력 구조가 2번이나 반복되는데 함수로 만드는 방법도 괜찮겠다
                    }
                    else{
                        printf("%d",temp/unit);
                    }
                }
                temp%=unit;
                unit/=10;
            }
        }
};
int main(){
    print num;
    num.numberinput();
    num.unitcentury();
    num.numberoutput();
}