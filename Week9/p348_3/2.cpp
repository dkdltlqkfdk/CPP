#include "1.hpp"
#define DIM 40
//canvas
class Canvas{

};


//monster

class Monster{
    private:
        int nEnergy,x,y,nMove;
        void eat(int map[DIM][DIM]){ //교재에선 맵의 좌표에 아이템이 있을 때를 1로 해서 몬스터가 먹고난 후 0을 출력하도록 되어 있는 함수. 그 칸이 빈칸이 되도록.
            if(map[y][x]==1){
                nEnergy+=8;
                map[y][x]=0;
            }
            else{
                nEnergy-=1; 
                if(nEnergy==0){ //에너지 변수는 교재에서 아이템을 다 먹어치우고도 움직이는 몬스터의 움직임을 제한하는 역할을 할거라 생각. 그래서 최솟값인 0이 되면 그 자리에서 멈추도록 설계할 거임.

                }
            }
        }
    public:
        Monster(): nEnergy(100){}
    
};
