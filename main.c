#include "vector.h"

int main() {
    Vector vec = createVectorFromFile("example1.vec");
    printVector(vec);
    destroyVector(vec);
}