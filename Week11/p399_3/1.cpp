#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

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
        system("clear"); 
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
    static int nMonsterCount; 

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) {
            nEnergy += 15; 
            map[y][x] = 0;
            nItem++;
        } else {
            nEnergy -= 5;
            if (nEnergy < 0) nEnergy = 0;
        }
    }

public:
    Monster(std::string n = "나괴물", std::string i = "@ ", int px = 0, int py = 0) 
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {
        nMonsterCount++;
    }


    ~Monster() {
        nMonsterCount--;
    }

    void draw(Canvas &canvas) {
        canvas.draw(x, y, icon);
    }

    void move(int map[DIM][DIM], int maxx, int maxy) {
        if (nEnergy <= 0) return;
        
        switch (rand() % 8) {
            case 0: y--; break; case 1: x++; y--; break;
            case 2: x++; break; case 3: x++; y++; break;
            case 4: y++; break; case 5: x--; y++; break;
            case 6: x--; break; case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    void print() {
        std::cout << "\t[" << icon << name << "]: " << nItem << "  에너지:" << nEnergy << std::endl;
    }
  
    int getEnergy() const { return nEnergy; }

    static void printCount() {
        std::cout << " 현재 전체 몬스터의 수: " << nMonsterCount << std::endl;
    }
};


int Monster::nMonsterCount = 0;

class MonsterWorld {
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster* mon[MAXMONS];
    Canvas canvas;

    int& Map(int x, int y) { return map[y][x]; }

    bool isDone() { return countItems() == 0 || nMon == 0; }

    int countItems() {
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

  
    void checkStarvation() {
        for (int i = 0; i < nMon; ) {
            if (mon[i]->getEnergy() <= 0) {
                delete mon[i]; // 동적 해제
               
                mon[i] = mon[nMon - 1];
                nMon--;
                std::cout << "몬스터 하나가 굶어 죽었습니다..." << std::endl;
                
            } else {
                i++;
            }
        }
    }

    void print() {
        canvas.clear();
        for (int y = 0; y < yMax; y++) {
            for (int x = 0; x < xMax; x++) {
                if (Map(x, y) > 0) canvas.draw(x, y, "o ");
            }
        }
        for (int i = 0; i < nMon; i++) {
            mon[i]->draw(canvas);
        }
        canvas.print("[Monster World (Dynamic World)]");
        std::cout << " 전체 이동 횟수: " << nMove << std::endl;
        std::cout << " 남은 아이템 수: " << countItems() << std::endl;
        
        for (int i = 0; i < nMon; i++) {
            mon[i]->print();
        }
        Monster::printCount();
    }

public:
    MonsterWorld(int w, int h) : xMax(w), yMax(h), canvas(w, h) {
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                Map(x, y) = 1;
    }

    ~MonsterWorld() { 
        for(int i=0; i<nMon; i++) delete mon[i];
    }

    void add(Monster* m) {
        if (nMon < MAXMONS) mon[nMon++] = m;
    }

    void play(int maxWalk, int wait) {
        print();
        std::cout << "엔터를 누르세요...";
        getchar();
        for (int i = 0; i < maxWalk; i++) {
            for (int k = 0; k < nMon; k++) {
                mon[k]->move(map, xMax, yMax);
            }
            nMove++;
            checkStarvation(); 
            print();
            if (isDone()) break;
            usleep(wait * 1000);
        }
    }
};