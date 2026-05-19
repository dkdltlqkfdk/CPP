#include "1.hpp"
#include <time.h>

int main(){
    srand((unsigned int)time(NULL));
    int w = 20, h = 10;
    MonsterWorld game(w, h);

    game.add(new Zombie("좀비", "$ ", rand() % w, rand() % h));
    game.add(new Vampire("뱀파이어", "%#", rand() % w, rand() % h)); 
    game.add(new KGhost("처녀귀신", "^ ", rand() % w, rand() % h));
    game.add(new Jiangshi("강시", "##", rand() % w, rand() % h, true)); 
    
    //(4)
    game.add(new Smombi("스몸비", "& ", rand() % w, rand() % h)); //(1)
    game.add(new Siangshi("샹시", "X#", rand() % w, rand() % h, true)); //(2)
    game.add(new GhostVampire("유령백작", "?+", rand() % w, rand() % h)); //(3)

    game.play(500, 150); 
    
    printf("---------- 게임 종료 ----------\n");
    return 0;
}
