#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
#include <thread> 
#include <chrono> 

#define MAXLINES 100
#define DIM 40
#define MAXMONS 20

//Canvas
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

//Monster
class Monster {
protected:
    std::string name, icon;
    int x, y, nItem;

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }  

    void eat(int map[DIM][DIM]) { 
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
        }
    }
public:
    Monster(std::string n = "나괴물", std::string i = "@ ", int px = 0, int py = 0) 
        : name(n), icon(i), x(px), y(py), nItem(0) {}
    
    virtual ~Monster() {
        std::cout << "\t" << name << icon << " 물러갑니다~~~\n"; 
    }
    
    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
    
    virtual void move(int map[DIM][DIM], int maxx, int maxy) {
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
        std::cout << "\t" << name << icon << ":" << nItem << std::endl;
    }
};

//
class Zombie : public Monster {
public:
    Zombie(std::string n = "허접 좀비", std::string i = "$ ", int x = 0, int y = 0) : Monster(n, i, x, y) {}
    ~Zombie() override { std::cout << " Zombie"; }
};

class Vampire : public Monster {
public:
    Vampire(std::string n = "뱀파이어", std::string i = "%#", int x = 0, int y = 0) : Monster(n, i, x, y) {}
    ~Vampire() override { std::cout << " Vampire"; }
 
    void move(int map[DIM][DIM], int maxx, int maxy) override {
        int dir = rand() % 4;
        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;
        clip(maxx, maxy);
        eat(map);
    }
};

class KGhost : public Monster {
public:
    KGhost(std::string n = "처녀귀신", std::string i = "^ ", int x = 0, int y = 0) : Monster(n, i, x, y) {}
    ~KGhost() override { std::cout << " KGhost"; }
  
    void move(int map[DIM][DIM], int maxx, int maxy) override {
        x = rand() % maxx;
        y = rand() % maxy;
        clip(maxx, maxy);
        eat(map);
    }
};

class Jiangshi : public Monster {
protected: 
    bool bHori;
public:
    Jiangshi(std::string n = "대륙강시", std::string i = "##", int x = 0, int y = 0, bool bH = true) 
        : Monster(n, i, x, y), bHori(bH) {}
    ~Jiangshi() override { std::cout << " Jiangshi"; }
    
    void move(int map[DIM][DIM], int maxx, int maxy) override {
        int dir = rand() % 2;
        int jump = rand() % 2 + 1;
        if (bHori) x += ((dir == 0) ? -jump : jump);
        else y += ((dir == 0) ? -jump : jump);
        clip(maxx, maxy);
        eat(map);
    }
}; 

//(1). 스몸비
class Smombi : public Monster {
public:
    Smombi(std::string n = "스몸비", std::string i = "& ", int x = 0, int y = 0) : Monster(n, i, x, y) {}
    ~Smombi() override { std::cout << " Smombi"; }

    void move(int map[DIM][DIM], int maxx, int maxy) override {
        int dir = rand() % 4; 
        if (dir == 0) { x--; y--; }      
        else if (dir == 1) { x++; y--; } 
        else if (dir == 2) { x--; y++; }
        else { x++; y++; }        
        clip(maxx, maxy);
        eat(map);
    }
};

//(2). 샹시
class Siangshi : public Jiangshi {
public:
    Siangshi(std::string n = "수퍼샹시", std::string i = "X#", int x = 0, int y = 0, bool bH = true) 
        : Jiangshi(n, i, x, y, bH) {}
    ~Siangshi() override { std::cout << " Siangshi"; }

    void move(int map[DIM][DIM], int maxx, int maxy) override {
        if (rand() % 5 == 0) {
            bHori = !bHori; 
        }
        Jiangshi::move(map, maxx, maxy);
    }
};

//(3) 독창 몬스터
class GhostVampire : public Vampire {
public:
    GhostVampire(std::string n = "유령백작", std::string i = "?+", int x = 0, int y = 0) : Vampire(n, i, x, y) {}
    ~GhostVampire() override { std::cout << " GhostVampire"; }

    void move(int map[DIM][DIM], int maxx, int maxy) override {
        // 확률로 맵의 무작위 위치로 워프(텔레포트)함
        if (rand() % 10 == 0) {
            x = rand() % maxx;
            y = rand() % maxy;
            clip(maxx, maxy);
            eat(map);
        } else {
            // 평소에는 부모(흡혈귀) 이동 방식을 따름
            Vampire::move(map, maxx, maxy);
        }
    }
};


// MonsterWorld
class MonsterWorld {
private:
    int map[DIM][DIM];   
    int xMax, yMax, nMon, nMove;     
    Monster* mon[MAXMONS];
    Canvas canvas;      

    int& Map(int x, int y) { return map[y][x]; }
    bool isDone() { return countItems() == 0; } 

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
            mon[i]->draw(canvas);
        }
        canvas.print("[Monster World (Polymorphism & Inheritance)]");
        std::cout << " 전체 이동 횟수: " << nMove << std::endl;
        std::cout << " 남은 아이템 수: " << countItems() << std::endl;
        for (int i = 0; i < nMon; i++) {
            mon[i]->print(); 
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
    
    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++) {
            delete mon[i];
        }
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
            print();
            if (isDone()) break;
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));
        }
    }
};