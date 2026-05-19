#include "1.hpp"

void Point::draw(){
    std::cout<<x<<","<<y<<"에 점을 그려라.\n"; //(3)
}

void Rectangle::draw(){
    std::cout<<x<<","<<y<<"에 가로 "<<width<<" 세로 "<<height<<" 사각형을 그려라.\n";
}

int main(){
    Point a(2,4);
    a.draw();
    Rectangle b(2,3,100,200);
    b.draw();
    return 0;
}