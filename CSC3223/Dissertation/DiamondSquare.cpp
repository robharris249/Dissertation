#include "../../Common/Window.h"
#include "../../Common/TextureLoader.h"
#include "../../Common/Vector3.h"
#include "../../Common/Vector4.h"
#include "../../Common/MeshGeometry.h"
#include "../../Common/Maths.h"

#include "../../Plugins/OpenGLRendering/OGLRenderer.h"
#include "../../Plugins/OpenGLRendering/OGLMesh.h"
#include "../../Plugins/OpenGLRendering/OGLShader.h"
#include "../../Plugins/OpenGLRendering/OGLTexture.h"

#include "Renderer.h"
#include "RasterisationMesh.h"
#include <vector>
#include "DiamondSquare.h"
#include "Node2D.h"
#include <iostream>
#include <map>
#include <ctime>

using namespace std;



bool DiamondSquare::checkIfOutofBounds(int x, int y) {

    if (x > 1024 || x < 0 || y > 1024 || y < 0) {
        return true;
    } else {
        return false;
    }
}

DiamondSquare::DiamondSquare(int size, float randomValueRange) {

    //srand(time(NULL));

    /* Randomly set corners */
    grid[0][0] = new Vector3(0.0f,0.0f, randomFloat(size / 10));
    grid[size][0] = new Vector3((float)size, 0, randomFloat(size / 10));
    grid[0][size] = new Vector3(0,(float)size, randomFloat(size / 10));
    grid[size][size] = new Vector3((float)size, (float)size, randomFloat(size / 10));


    /* Manually set corners */
    /*grid[0][0] = new Vector3(0.0f, 0.0f, 10);
    grid[size][0] = new Vector3((float)size, 0, 20);
    grid[0][size] = new Vector3(0, (float)size, -5);
    grid[size][size] = new Vector3((float)size, (float)size, 10);*/

    this->size = size;
    this->randomValueRange = randomValueRange;
}

float DiamondSquare::randomFloat(float range) {
    int tempRange = range * 10;
    tempRange = (rand() % ((tempRange + 1) * 2)) - tempRange;
    return (float)tempRange / 10;
}

float DiamondSquare::roundFloat(float var) {

    var += 0.5;
    var *= 100;
    int round = var;
    float value = (float)var / 100.0f;

    return value;
}

void DiamondSquare::squareStep(int x, int y, int step) {

    int centreX = x + step / 2;
    int centreY = y + step / 2;
    float centreZ = ((grid[x][y]->z + grid[x + step][y]->z + grid[x][y + step]->z + 
        grid[x + step][y + step]->z) / 4) + randomFloat(randomValueRange);
    grid[centreX][centreY] = new Vector3((float)centreX, (float)centreY, centreZ);
}

void DiamondSquare::diamondStep(Vector3* c, int step) {

    vector<Vector3*> nodes;
    nodes.push_back(new Vector3((int)c->x, (int)c->y - step, 0.0f));
    nodes.push_back(new Vector3((int)c->x - step, (int)c->y, 0.0f));
    nodes.push_back(new Vector3((int)c->x, (int)c->y + step, 0.0f));
    nodes.push_back(new Vector3((int)c->x + step, (int)c->y, 0.0f));

    for (int i = 0; i < nodes.size(); i++) {
        float tempZ = 0.0f;
        bool edgepiece = false;

        if (!checkIfOutofBounds(nodes.at(i)->x, nodes.at(i)->y - step)) {
            tempZ += grid[nodes.at(i)->x][nodes.at(i)->y - step]->z;
        }
        else {
            edgepiece = true;
        }

        if (!checkIfOutofBounds(nodes.at(i)->x - step, nodes.at(i)->y)) {
            tempZ += grid[nodes.at(i)->x - step][nodes.at(i)->y]->z;
        }
        else {
            edgepiece = true;
        }

        if (!checkIfOutofBounds(nodes.at(i)->x, nodes.at(i)->y + step)) {
            tempZ += grid[nodes.at(i)->x][nodes.at(i)->y + step]->z;
        }
        else {
            edgepiece = true;
        }

        if (!checkIfOutofBounds(nodes.at(i)->x + step, nodes.at(i)->y)) {
            tempZ += grid[nodes.at(i)->x + step][nodes.at(i)->y]->z;
        }
        else {
            edgepiece = true;
        }

        if (edgepiece) {
            tempZ = tempZ / 3;
        } else {
            tempZ = tempZ / 4;
        }

        nodes.at(i)->z = tempZ + randomFloat(randomValueRange);
        grid[nodes.at(i)->x][nodes.at(i)->y] = nodes.at(i);
    }

    nodes.clear();

}

void DiamondSquare::run() {

    step = size / (grid.size() - 1);
    randomValueRange = 0.5 * step / 10;

    for (int i = 0; i < size; i += step) {
        for (int j = 0; j < size; j += step) {
            squareStep(i, j, step);
        }
    }

    for (int i = 0; i < size; i += step) {
        for (int j = 0; j < size; j += step) {
            diamondStep(grid[i + step / 2][j + step / 2], step / 2);
        }
    }
}