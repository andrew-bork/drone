#include <math.h>
#include <logger.h>

int main() {
    math::matrix mat(1,1);
    logger::info("Created Matrix");
    logger::info("Matrix: \n{}", math::matrix::string(mat));
}