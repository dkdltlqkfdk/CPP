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

//page 97, 1-4 (절차적, 객체지향)
/*#include<stdio.h>
int main(){
    int i,j,h,k;
    for(i=0;i<5;i++){
        for(j=4-i;j>0;j--){
            printf("  ");
        }
        for(h=i+1;h>=1;h--){
            printf("%d ",h);
        }
        for(k=2;k<=i+1;k++){
            printf("%d ",k);
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
            int i,h,j,k;
            for(i=0;i<row;i++){
                for(h=row-1-i;h>0;h--){
                    printf("  ");
                }
                for(j=1+i;j>=1;j--){
                    printf("%d ",j);
                }
                for(k=2;k<=i+1;k++){
                    printf("%d ",k);
                }
                printf("\n");
            }
        }
};
int main(){
    pattenprint fourth;
    fourth.print();
}