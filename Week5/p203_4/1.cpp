#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 리눅스용 getch() 구현 (교재 style 유지를 위해 최소화)
#include <termios.h>
#include <unistd.h>
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// 1. 구조체 정의 (교재 185p 참고)
struct PlayInfo {
    char name[200];
    int nMove;
    double tElapsed;
};

// 전역 변수 (교재 192p 참고)
int DIM = 4;                // (1) 맵 크기 확장
int map[10][10];
int initialMap[10][10];     // (2) 리플레이용 초기 맵
int history[1000];          // (2) 리플레이용 이동 기록
int x, y, nMove = 0;
clock_t tStart;
struct PlayInfo MVP[10];    // (6) 상위 10개 랭킹

// 2. 랭킹 처리 (이진 모드 - 교재 189p 참고)
void loadRanking() {
    FILE* fp = fopen("ranking.bin", "rb");
    if (fp == NULL) return;
    fread(MVP, sizeof(struct PlayInfo), 10, fp);
    fclose(fp);
}

void storeRanking() {
    FILE* fp = fopen("ranking.bin", "wb");
    if (fp != NULL) {
        fwrite(MVP, sizeof(struct PlayInfo), 10, fp);
        fclose(fp);
    }
}

// 3. 게임 로직
void init() {
    int i, j, count = 1;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) map[i][j] = count++;
    }
    map[DIM-1][DIM-1] = 0; x = DIM-1; y = DIM-1;
}

int move(int key) {
    int nx = x, ny = y;
    if (key == 'w') ny--;      // 상
    else if (key == 's') ny++; // 하
    else if (key == 'a') nx--; // 좌
    else if (key == 'd') nx++; // 우
    else return 0;

    if (nx < 0 || nx >= DIM || ny < 0 || ny >= DIM) return 0;
    map[y][x] = map[ny][nx];
    map[ny][nx] = 0;
    x = nx; y = ny;
    return 1;
}

void display() {
    system("clear"); // 리눅스 화면 지우기
    printf(" [%d x %d 퍼즐]\n", DIM, DIM);
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (map[i][j]) printf("%3d", map[i][j]);
            else printf("   ");
        }
        printf("\n");
    }
    printf("이동: %d | 시간: %.1f\n", nMove, (double)(clock()-tStart)/CLOCKS_PER_SEC);
}

int main() {
    printf("맵 크기(3~5): "); scanf("%d", &DIM);
    loadRanking();
    init();
    
    // 셔플 (간략화)
    srand(time(NULL));
    for(int i=0; i<50; ) if(move("wasd"[rand()%4])) i++;
    
    // 초기 상태 복사 (리플레이용)
    for(int i=0; i<DIM; i++) for(int j=0; j<DIM; j++) initialMap[i][j] = map[i][j];

    nMove = 0; tStart = clock();
    while (1) {
        display();
        int key = getch();
        if (move(key)) history[nMove++] = key;
        
        // 종료 조건 검사 (생략 가능하나 교재 흐름상 추가)
        int win = 1, c = 1;
        for(int i=0; i<DIM; i++) for(int j=0; j<DIM; j++) {
            if(i==DIM-1 && j==DIM-1) { if(map[i][j]!=0) win=0; }
            else if(map[i][j] != c++) win=0;
        }
        if (win) break;
    }

    printf("\n성공! 이름 입력: ");
    scanf("%s", MVP[0].name); // 예시로 1등에 저장
    MVP[0].nMove = nMove;
    storeRanking();

    printf("리플레이 보려면 'y' 누르세요: ");
    if (getch() == 'y') {
        init(); // 맵 초기화
        for(int i=0; i<DIM; i++) for(int j=0; j<DIM; j++) map[i][j] = initialMap[i][j];
        for(int i=0; i<nMove; i++) {
            move(history[i]); display(); usleep(200000);
        }
    }
    return 0;
}