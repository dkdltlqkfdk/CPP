#include "1.hpp"
#include <conio.h>
enum Direction {Left=75, Right=77, Up=72, Down=80};
class Human:public Monster{
    public:
        Human(string n="미래 인류",string i="♀", int px=0, int py=0):Monster(n,i,px,py){}
        ~Human(){std::cout<<"[Human ]";}
        int getDirKey(){
            return getche()==224?getche():0;
        }
};