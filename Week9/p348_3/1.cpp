#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h> // windows.h 대신 리눅스용 헤더 사용

#define MAXLINES 100
#define DIM 40
#define MAXMONS 20


class Canvas {
private:
    std::string line[MAXLINES];
    int xMax, yMax;
public:
    Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
        for (int y = 0; y < yMax; y++) {
            line[y] = std::string(xMax * 2, ' ');
        }
    }
    void draw(int x, int y, std::string val) {
        if (x >= 0 && y >= 0 && x < xMax && y < yMax) {
            line[y].replace(x * 2, 2, val);
        }
    }
    void clear(std::string val = ". ") {
        for (int y = 0; y < yMax; y++) {
            for (int x = 0; x < xMax; x++) {
                draw(x, y, val);
            }
        }
    }
    void print(const char* title = "<My Canvas>") {
        system("clear"); // cls -> clear (리눅스용)
        std::cout << title << std::endl;
        for (int y = 0; y < yMax; y++) {
            std::cout << line[y] << std::endl;
        }
        std::cout << std::endl;
    }
};


class Monster {
private:
    std::string name, icon;
    int nEnergy, x, y, nItem;

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) {
            nEnergy += 8;
            map[y][x] = 0;
            nItem++;
        } else {
            nEnergy -= 1;
            if (nEnergy <= 0) nEnergy = 0;
        }
    }
public:
    Monster(std::string n = "나괴물", std::string i = "@ ", int px = 0, int py = 0) 
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}
    ~Monster() { std::cout << "\t" << name << icon << " 물러갑니다~~~\n"; }
    
    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
    
    void move(int map[DIM][DIM], int maxx, int maxy) {
        if (nEnergy <= 0) return; // 에너지 0일 때 정지 로직 유지
        switch (rand() % 8) {
            case 0: y--; break;
            case 1: x++; y--; break;
            case 2: x++; break;
            case 3: x++; y++; break;
            case 4: y++; break;
            case 5: x--; y++; break;
            case 6: x--; break;
            case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }
    void print() {
        std::cout << "\t" << name << icon << ":" << nItem << " E: " << nEnergy << std::endl;
    }
};

class MonsterWorld {
    int map[DIM][DIM];   
    int xMax, yMax, nMon, nMove;     
    Monster* mon[MAXMONS]; 
    Canvas canvas;      

    int& Map(int x, int y) { return map[y][x]; }
    bool isDone() { return countItems() == 0; } // countItem -> countItems 수정

    int countItems() {  
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

    void print() {
        canvas.clear();
        for (int y = 0; y < yMax; y++) {
            for (int x = 0; x < xMax; x++) {
                if (Map(x, y) > 0) canvas.draw(x, y, "o "); 
            }
        }
        for (int i = 0; i < nMon; i++) {
            mon[i]->draw(canvas); // . -> -> 수정
        }
        canvas.print("[Monster World (Basic)]");
        std::cout << " 전체 이동 횟수: " << nMove << std::endl;
        std::cout << " 남은 아이템 수: " << countItems() << std::endl;
        for (int i = 0; i < nMon; i++) {
            mon[i]->print(); // . -> -> 수정
        }
    }

public:
    MonsterWorld(int w, int h) : xMax(w), yMax(h), canvas(w, h) {
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                Map(x, y) = 1;
    }
    void add(Monster* m) { // Monster m -> Monster* m 수정 (new를 쓰기 때문)
        if (nMon < MAXMONS) mon[nMon++] = m;
    }
    void play(int maxWalk, int wait) {
        print();
        std::cout << "엔터를 누르세요...";
        getchar();
        for (int i = 0; i < maxWalk; i++) { // maxwalk -> maxWalk 수정
            for (int k = 0; k < nMon; k++) {
                mon[k]->move(map, xMax, yMax); // . -> -> 수정
            }
            nMove++;
            print();
            if (isDone()) break;
            usleep(wait * 1000); // Sleep -> usleep (리눅스용)
        }
    }
};