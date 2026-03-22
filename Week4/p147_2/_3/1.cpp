#include<iostream>

void reserve(int num){
    int temp=num;
    while(temp>0){
        printf("%d",temp%10);
        temp/=10;
    }
}