#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "matrix.h"

class GameEngine
{
public:
    GameEngine(int in_cols, int in_rows, int in_density);

    void NextGeneration(bool BreedingAlgorithm);
    matrix<bool> GetCurrentGeneration();

    int currentGeneration;
    int CountNeighbours(int x, int y);


private:
    int cols;
    int rows;
    int density;
    matrix<bool> field;

};

#endif // GAMEENGINE_H
