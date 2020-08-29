#include "GameEngine.h"
#include <cstdlib>
#include <ctime>


GameEngine::GameEngine(int in_cols, int in_rows, int in_density)
{
    cols = in_cols;
    rows = in_rows;
    density = in_density;
    field.resize(cols,rows);
    currentGeneration = 0;

    for (int x = 0; x < cols; ++x)
    {
        //srand();
        for (int y = 0; y < rows; ++y)
        {
            field[x][y] = rand() % 2;
        }
    }
}

void GameEngine:: NextGeneration(bool BreedingAlgorithm)
{

    matrix<bool> newField;
    newField.resize(cols, rows);

    /* Заполнение нового массива */
    for (int x = 0; x < cols; ++x)
    {
        for (int y = 0; y < rows; ++y)
        {
            auto neighboursCount = CountNeighbours(x, y);
            auto hasLife = field[x][y];
            bool Breeding = BreedingAlgorithm;


            int random = rand() % 1000;

            if (!hasLife && neighboursCount == 3)
            {
                newField[x][ y] = true;
            }
            else if (!hasLife && neighboursCount == 2 && random == 1 && Breeding)
            {
                newField[x][ y] = true;
            }
            else if (!hasLife && neighboursCount == 1 && random == 2 && Breeding)
            {
                newField[x][y] = false;
            }
            else if (hasLife && random == 3 && Breeding)
            {
                newField[x][ y] = true;
            }
            else if (hasLife && (neighboursCount < 2 || neighboursCount > 3))
            {
                newField[x][ y] = false;
            }
            else
            {
                newField[x][ y] = field[x][ y];
            }



        }
    }
    currentGeneration++;
    field = newField;

}

int GameEngine::CountNeighbours(int x, int y)
{
    /*Счетчик соседей клетки*/
    int count = 0;

    /*Подсчет соседей клетки*/
    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        {
            /* контроль нахождения координат в пределах размеря поля*/
            auto col = (x + i + cols) % cols;
            auto row = (y + j + rows) % rows;

            bool isSelfCheking = col == x && row == y;
            bool hasLife = field[col][row];

            /* Если у клетки есть сосед, и этот сосед не сама клетка*/
            if (hasLife && !isSelfCheking)
                count++;
        }
    }

    return count;
}

matrix<bool> GameEngine::GetCurrentGeneration()
{
    matrix<bool> result;
    result.resize(cols, rows);
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            result[i][ j] = field[i][ j];
        }
    }

    return result;
}

