#include<stdio.h>

class approximation {
    private:
        int number;
    public:
        void input(){
            scanf("%d",&number);
        }
        void calculate(){
            int temp=number;
            double result=4.0 * (1.0 - (1.0 / (2 * temp + 1)));
            printf("파이의 근사값: %lf",result);
        }
};
int main(){
    approximation number;
    number.input();
    number.calculate();
    return 0;
}