
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
