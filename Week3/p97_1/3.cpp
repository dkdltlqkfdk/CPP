
//page 97, 1-3 (절차적, 객체지향)
/*#include<stdio.h>
int main(){
    int i,j,h;
    for(i=0;i<5;i++){
        for(j=4-i;j>0;j--){
            printf("  ");
        }
        for(h=i+1;h>=1;h--){
            printf("%d ",h);
        }
        printf("\n");
    }
    return 0;
}*/

#include<stdio.h>
class pattenprint{
    private:
        int row;
    public:
        pattenprint(){
            row=5;
        }
        void print(){
            int i,h,j;
            for(i=0;i<row;i++){
                for(h=row-1-i;h>0;h--){
                    printf("  ");
                }
                for(j=1+i;j>=1;j--){
                    printf("%d ",j);
                }
                printf("\n");
            }
        }
};
int main(){
    pattenprint third;
    third.print();
}
