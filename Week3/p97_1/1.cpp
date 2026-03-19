//page 97, 1-1 (절차적, 객체지향)
/*#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            printf("%d ",j);
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
        ~pattenprint(){}
        void print(){
            int i,j;
            for(i=1;i<=row;i++){
                for(j=1;j<=i;j++){
                    printf("%d ",j);
                }
                printf("\n");
            }
        }

};
int main(){
    pattenprint first;
    first.print();
    return 0;
}