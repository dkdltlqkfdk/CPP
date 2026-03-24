#include<iostream>
#include "2.h"
void reserve(int num){
    int temp=num;
    while(temp>0){
        printf("%d",temp%10);
        temp/=10;
    }
}
int main(){
    int n;
    std :: cin >> n;
    reserve(n);
    return 0;
}
