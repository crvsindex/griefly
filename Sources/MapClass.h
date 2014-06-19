#pragma once

#include <stdlib.h>

#include "Mob.h"

class CubeTile;

struct point
{
    int posx;
    int posy;
    int posz;
};

struct square
{
    bool inOpenList;
    bool inCloseList;
    int cost;
    int realcost;
    int posx;
    int posy;
    square* before;
};

class CPathFinder
{
public:
    std::list<Dir> calculatePath(int fromPosx, int fromPosy, int toPosx, int toPosy, int toPosz = 0);
    MapMaster* map;
private:
    std::list<square*> openList;
    square squares[sizeHmap][sizeWmap];
    void clearPathfinding();
    void addNear(int posx, int posy, int toPosx, int toPosy);
    int calcCost(int posx, int posy, int toPosx, int toPosy);
    bool removeFromOpen(int posx, int posy);
    void addToOpen(int posx, int posy);
    int numOfPathfind;
};



class LOSfinder
{
public:
    std::list<point>* calculateVisisble(std::list<point>* retval, int posx, int posy, int posz = 0);
    MapMaster* map;
private:
    //bool LOSSquare[sizeHsq * 2 + 1][sizeWsq * 2 + 1];
    void clearLOS();
    std::list<point> worklist;

};

struct idpoint
{
    int posx;
    int posy;
    int find_hash;
};

class MapMaster
{
public:
    MapMaster();
    typedef id_ptr_on<CubeTile> SqType;
    SqType squares[sizeHmap][sizeWmap][sizeDmap];

    void Draw();
    bool isVisible(int posx, int posy, int posz = 0);
   

    template<typename T>
    id_ptr_on<T> getItem(int posx, int posy, int posz = 0)
    {
        return squares[posx][posy][posz]->GetItem<T>();
    }
    
    void splashLiquid(std::list<HashAmount> ha, int posx, int posy, int posz = 0);

    void makeTiles();
    void makeMap();
    void centerFromTo(int nowPosx, int nowPosy, int nowPosz = 0);
    bool isPassable(int posx, int posy, int posz = 0);
    bool fastisPassable(int posx, int posy);
    static void switchDir(int& posx, int& posy, Dir direct, int num = 1, bool back = false);
    static bool checkOutBorder(int posx, int posy);
    //
    static bool checkOutBorder(int posx, int posy, Dir direct);
    //pathfinding

    size_t ms_last_draw;
    bool canDraw();
    
    id_ptr_on<IOnMapItem> click(int x, int y);
    
    int numOfPathfind;
    CPathFinder pathf;
    LOSfinder losf;
    void checkZeroId();
};

MapMaster* GetMapMaster();
void SetMapMaster(MapMaster* map_master);