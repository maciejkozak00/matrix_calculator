#include <iostream>
#include "Matrix.h"

int main() {
    std::vector<std::vector<int>> a
            {
                    {1,2,3,4},
                    {4,5,6,7},
                    {7,8,9,10},
            };
    std::vector<std::vector<int>> b
            {
                    {1,0,0,0},
                    {0,1,0,0},
                    {0,0,1,0},
            };

    Matrix m1;
    Matrix m2;

    m1.fillMatrix(a);
    m2.fillMatrix(b);

    Matrix w;

    w = 3*m1;
    w.info();
}
