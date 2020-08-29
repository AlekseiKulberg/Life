#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template<class T>
class matrix : public vector<vector<T>>
{
public:
    matrix() = default;
    ~matrix() = default;

    matrix(int vs, int hs)
    {
        resize(vs, hs);
    }

    void resize(int vs, int hs)
    {
        vector<vector<T>>::resize(vs);

        for (int i = 0; i < vs; ++i)
        {
            vector<vector<T>>::at(i).resize(hs, 0);
        }
    }

};

#endif // MATRIX_H
