
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