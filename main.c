/*#include "vector.h"*/
#include "matrix.h"

int main() {
    //Vector vec = createVectorFromFile("example1.vec");
    Matrix m = createMatrixFromFile("example1.mat");
    printMatrix(m);
    destroyMatrix(&m);
}