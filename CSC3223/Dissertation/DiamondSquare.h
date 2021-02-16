#pragma once
#include <iostream>
#include <map>
#include "..//..//Common/Vector3.h"

using namespace NCL;
using namespace std;

class DiamondSquare {
public:


    DiamondSquare(int size, float randomValueRange);
    bool checkIfOutofBounds(int x, int y);
    float randomFloat(float range);
    float roundFloat(float var);
    void squareStep(int x, int y, int step);
    void diamondStep(Vector3* c, int step);
    void run();

    map<float, map<float, Vector3*>> getGrid();

    int size;
    int step;
    float randomValueRange;
    map<int, map<int, Vector3*>>grid;
};