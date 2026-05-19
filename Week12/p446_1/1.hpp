#include <iostream>
class Point{ //부모 클래스
    protected: //(4).부모 클래스 protected 제한 접근자에 선언된 멤버 변수는 자식 클래스에 상속할 수 있게 한다. privated의 경우 자식 클래스 접근을 제한된다.
        int x,y;
    public:
        Point(int x, int y): x(x),y(y){}
        virtual void draw() ; //가상 함수
};
class Rectangle:public Point{ //(1).자식 클래스
    private:
        int width, height;
    public:
        Rectangle(int x, int y,int w,int h): Point(x,y), width(w),height(h){} //(2)
        void draw() override; //(3).재정의 명시
};