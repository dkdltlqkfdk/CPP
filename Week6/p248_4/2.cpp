#include "1.hpp"
#define Max_Width 80
#define Max_height 40
#define label(x, y) (MineMapLabel[y][x])
#define mask(x, y)  (MineMapMask[y][x])
enum LabelType { Empty=0, Bomb=9}; //지뢰가 있는 지 없는 지, 실제 지뢰 정보
enum MaskType { Hide, Open, Flag}; //사용자가 보는 화면 정보
int MineMapLabel[Max_height][Max_Width]; //정답지
int MineMapMask[Max_height][Max_Width];  //사용자가 푸는? 시험지
int nBomb,nx,ny; //전역변수로 정의한 이유는 무얼까?


int getBombCount(){
    int count=0;
    for(int y=0;y<ny;y++){
        for(int x=0;x<nx;x++){
            if(mask(x,y)==Flag){
                count++;
            }
        }
    }
    return count;
}

void print(){
    system("clear");
    std::cout<<"발견: "<<getBombCount()<<"전체: "<<nBomb<<std::endl;
    for(int i=1;i<=nx;i++){
        std::cout<<"%2d "<<i;
    }
    std::cout << "\n";
    for(int i=0;i<ny;i++){
        std::cout<<"%2d "<<i+1;
        for(){

        }
        std::cout << "\n";
    }
}

void init(int total){
    
    for(int y=0;y<ny;y++){
        for(int x=0;x<nx;x++){
            label(x,y)=Empty;
            mask(x,y)=Hide;
        }
    }
    srand((unsigned)time(NULL));
    while(total>0){
        int x,y;
        do{
            x=rand()%nx;
            y=rand()%ny;
        }while(label(x,y)!=Empty);
        label(x,y)=Bomb;
        total--;
    }
    
}

void playMineSweeper(int total){
    
    int x,y,status;
    init(total);
    do{
        print();
        
    }
}



int main(){
    int total,w,h;

    std::cout<<" <Mine Sweeper>\n"<< std::endl;

    std::cout<<"지뢰 맵 가로 설정: ";
    std::cin>>w;
    if (w > Max_Width){
        std::cout << "최대 크기를 초과하여 80으로 설정합니다.\n";
        w = Max_Width; // 강제로 80
    }
    nx=w;

    std::cout<<"지뢰 맵 세로 설정: ";
    std::cin>>h;
    if (h > Max_height){
        h = Max_height;
    }
    ny=h;

    std::cout<<"매설할 총 지뢰의 개수 입력: "<<std::endl;
    std::cin>>total;
    if (total >= w * h){
        total = (w * h) / 2;
    }
    nBomb=total;

    playMineSweeper(total);
}