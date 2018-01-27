#include "LA.h"

int main() {
    std::vector<std::vector<double>>  m1 = {{1,2,3},
        {4,5,6}};

    std::vector<std::vector<double>> m2 = {{7,8,9,10},
        {11,12,13,14},
        {15,16,17,19}};

    std::vector<std::vector<double>> result = LA::multiply(m1, m2);
    LA::print(result);

    LA::print(m1);
    std::vector<std::vector<double>> newM1 = LA::transpose(m1);
    LA::print(newM1);
}
