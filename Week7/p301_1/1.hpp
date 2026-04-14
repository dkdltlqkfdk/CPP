#include <iostream>
#include <iomanip> // setw, setfill
class MyTime {
    private:
        int hour, min, sec, msec;

    public:
        void convert(double duration);
        void print();                        
        MyTime add(MyTime t2);
        void reset();
        void read();
};

/* (2).
+------------------------------------------+
|                 MyTime                   |  <-- 클래스 이름
+------------------------------------------+
| - hour : int                             |  <-- 멤버 변수 (Attributes)
| - min  : int                             |      ('-'는 private을 의미)
| - sec  : int                             |
| - msec : int                             |
+------------------------------------------+
| + convert(duration : double) : void      |  <-- 멤버 함수 (Operations)
| + print() : void                         |      ('+'는 public을 의미)
| + add(t2 : MyTime) : MyTime              |
| + reset() : void                         |
+------------------------------------------+

멤버 함수는 클래스 안에 이미 변수들이 들어있기에 덜 가져와도 되고 결과물을 객체 통째로 넘겨줄 수 있어서 사용. */



//(5). 헤더파일 구현