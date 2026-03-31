#include "1.hpp"
void randomMap(int map[5][5]){  //1. 2차원 배열을 0과 1로 무작위 채우기
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int num=rand()%2;
            map[i][j]=num;
        }
    }
}
void printMap(int map[5][5]){  //2. 체커 보드 출력
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

void checkMap(int map[5][5]){  //3. 가로, 세로, 대각선이 모두 0이거나 1인 부분 화면에 출력
    int i=0,j=0;
    while(i<5){
        while(j<4){
            if(map[i][j]!=map[i][j+1]){ 
                break;
            }
            else{
                j++;
                if(j==4){
                    printf("%d행의 숫자가 같습니다.\n",i+1);
                }
            }
        }
        j=0;
        i++;
    } //가로.

    i=0; j=0;
    while(j<5){
        while(i<4){
            if(map[i][j]!=map[i+1][j]){
                break;
            }
            else{
                i++;
                if(i==4){
                    printf("%d열의 숫자가 같습니다.\n",j+1);
                }
            }
        }
        i=0;j++;
    } //세로. 가로와 같은 방식이되 j를 고정시켜성 반복.

    i=0;
    int left=1; /*  \  */
    int right=1; /*  /  */
    while(i<4){
        if(map[i][i]!=map[i+1][i+1]){
            left=0;
        }
        if(map[i][4-i]!=map[i+1][4-(i+1)]){
            right=0;
        }
        i++;
    }
    if(left==1){
        printf("\\대각선의 숫자가 같습니다.\n");
    }
    if(right==1){
        printf("/대각선의 숫자가 같습니다.\n");
    }  //대각선.
}

int main(){
    int map[5][5];
    srand((unsigned)time(NULL)); 
    randomMap(map);

    printMap(map); 

    checkMap(map); 
    return 0;
}