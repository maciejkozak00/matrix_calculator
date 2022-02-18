#include <iostream>
#include "Matrix.h"

int main() {
    std::vector<std::vector<int>> c
            {
                    {-2,-3,1},
                    {-1,4,0}
            };
    std::vector<std::vector<int>> d
            {
                    {-2,-1,2},
                    {3,0,1},
                    {2,2,-1},
            };

    Matrix m1;
    Matrix m2;

    m1.fillMatrix(c);
    m2.fillMatrix(d);

    Matrix w;



    w = m1*m2;
    w.info();
}
