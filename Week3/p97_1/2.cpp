
//page 97, 1-2 (절차적, 객체지향)
/*#include<stdio.h>
int main(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=5;j >=i+1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}*/

#include<stdio.h>
class pattenprint {
    private:
        int row;
    public:
        pattenprint() {
            row=5;
        }
        void print(){
            int i,j;
            for(i=1;i<=row;i++){
                for(j=row;j>=i;j--){
                    printf("%d ",j);
                }
                printf("\n");
            }
        }
};
int main(){
    pattenprint second;
    second.print();
}
