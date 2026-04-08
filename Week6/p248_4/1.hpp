#include <iostream>
#include <cstdlib>
#include <ctime>

#define Max_Width 80
#define Max_height 40
#define label(x, y) (MineMapLabel[y][x])
#define mask(x, y)  (MineMapMask[y][x])

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide, Open, Flag };

int MineMapLabel[Max_height][Max_Width];
int MineMapMask[Max_height][Max_Width];
int nBomb, nx, ny;

inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }