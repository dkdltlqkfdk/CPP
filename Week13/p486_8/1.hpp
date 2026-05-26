/*#include <iostream>
class Sample1{
    public:
        Sample1(){}
        void play();
};

class Sample2:public Sample1{
    public:
        Sample2(){}
        void play();
};

class Sample3:public Sample1{
    public:
        Sample3(){}
        void play();
};

class Sample4:public Sample1{
    public:
        Sample4(){}
        void play();
};*/

#include <iostream>
class Sample1{
    public:
        Sample1(){}
        virtual void play(); //(2) 4번 반복 실행 안함. 정상 작동.
};

class Sample2:public Sample1{
    public:
        Sample2(){}
        void play() override;
};

class Sample3:public Sample1{
    public:
        Sample3(){}
        void play() override;
};

class Sample4:public Sample1{
    public:
        Sample4(){}
        void play() override;
};

//(1) 1번 sample만 4번 출력