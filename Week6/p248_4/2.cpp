#include "1.hpp"

int getBombCount() {
    int count = 0;
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Flag) count++;
        }
    }
    return count;
}

int countNbrBombs(int x, int y) {
    int count = 0;
    for (int j = y - 1; j <= y + 1; j++) {
        for (int i = x - 1; i <= x + 1; i++) {
            if (isValid(i, j) && label(i, j) == Bomb) {
                count++;
            }
        }
    }
    return count;
}

void init(int total) {
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            label(x, y) = Empty;
            mask(x, y) = Hide;
        }
    }

    srand((unsigned)time(NULL));
    int t = total;
    while (t > 0) {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(x, y) != Empty);
        label(x, y) = Bomb;
        t--;
    }

    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (label(x, y) == Empty) {
                label(x, y) = countNbrBombs(x, y);
            }
        }
    }
}

void print() {
    system("clear"); // Windows 환경이면 "cls"
    std::cout << " 발견: " << getBombCount() << " / 전체: " << nBomb << std::endl;

    // 1. 열 번호 (가로축) 출력
    std::cout << "   ";
    for (int x = 0; x < nx; x++) {
        int num = x + 1;
        if (num < 10) std::cout << " " << num ; // 한 자리 숫자는 앞뒤 공백
        else std::cout << num ;               // 두 자리 숫자는 뒤에만 공백
    }
    std::cout << "\n";

    // 2. 행 번호 (세로축) 및 맵 출력
    for (int y = 0; y < ny; y++) {
        int rowNum = y + 1;
        if (rowNum < 10) std::cout << " " << rowNum << " "; // 한 자리 행 번호 정렬
        else std::cout << rowNum << " ";                  // 두 자리 행 번호 정렬
        
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Hide) {
                std::cout << " ■";
            }
            else if (mask(x, y) == Open) {
                if (label(x, y) == Bomb) std::cout << " *";
                else if (label(x, y) == 0) std::cout << " .";
                else std::cout << " " << label(x, y);
            }
            else {
                std::cout << " ▣";
            }
        }
        std::cout << "\n";
    }
}

int getPos() {
    int x, y;
    char cmd;
    std::cout << "\n입력 (열 행 명령[P:깃발, D:파기]): ";
    std::cin >> x >> y >> cmd;
    x--; y--;

    if (!isValid(x, y)) return 0;

    if (cmd == 'P' || cmd == 'p') {
        if (mask(x, y) == Hide) mask(x, y) = Flag;
        else if (mask(x, y) == Flag) mask(x, y) = Hide;
        return 0;
    }
    else {
        mask(x, y) = Open;
        // ★ 교재 핵심: 파낸 자리가 지뢰인지 isBomb으로 확인
        if (isBomb(x, y)) return -1; 

        int hiddenCount = 0;
        for (int i = 0; i < ny; i++) {
            for (int j = 0; j < nx; j++) {
                if (mask(j, i) != Open) hiddenCount++;
            }
        }
        if (hiddenCount == nBomb) return 1;
    }
    return 0;
}

void playMineSweeper(int total) {
    int status = 0;
    init(total);
    do {
        print();
        status = getPos(); // getPos 내부에서 isBomb 판정 후 결과 리턴
    } while (status == 0);

    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) mask(x, y) = Open;
    }
    print();

    if (status == 1) std::cout << "\n축하합니다! 성공!" << std::endl;
    else std::cout << "\n펑! 지뢰를 밟았습니다. 게임 오버!" << std::endl;
}
int main() {
    int total, w, h;
    std::cout << " <Mine Sweeper>\n" << std::endl;

    std::cout << "지뢰 맵 가로 설정: ";
    std::cin >> w;
    if (w > Max_Width) {
        std::cout << "최대 크기를 초과하여 80으로 설정합니다.\n";
        w = Max_Width;
    }
    nx = w;

    std::cout << "지뢰 맵 세로 설정: ";
    std::cin >> h;
    if (h > Max_height) {
        std::cout << "최대 크기를 초과하여 40으로 설정합니다.\n";
        h = Max_height;
    }
    ny = h;

    std::cout << "매설할 총 지뢰의 개수 입력: ";
    std::cin >> total;
    if (total >= w * h) {
        total = (w * h) / 2;
    }
    nBomb = total;

    playMineSweeper(total);
    return 0;
}