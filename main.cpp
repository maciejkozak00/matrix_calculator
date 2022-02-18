#include <iostream>
#include "Matrix.h"

int main() {
    std::vector<std::vector<int>> a
            {
                    {1,2,3},
                    {4,5,6},
                    {7,8,9}
            };

    std::vector<std::vector<int>> b
            {
                    {1,0,0},
                    {0,1,0},
                    {0,0,1}
            };

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

    //2 matrix for addition and subtraction tests
    Matrix m1;
    Matrix m2;
    //filling with vector
    m1.fillMatrix(a);
    m2.fillMatrix(b);
    Matrix w;
    std::cout << "ADDITION" << std::endl;
    w = m1 + m2;
    w.info();
    std::cout << "SUBTRACTION" << std::endl;
    w = m1 - m2;
    w.info();
    std::cout << "MULTIPLICATION WITH NUMBER" << std::endl;
    m1.fillMatrix(c);
    m2.fillMatrix(d);
    w = m1 * 3;
    w.info();
    std::cout << "MULTIPLICATION" << std::endl;
    w = m1*m2;
    w.info();
}
