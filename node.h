#include <iostream>

using namespace std;

class node {
public:
    double coefficients = 0.0;
    int exponents = 0;
    node *next = nullptr;

    node() {
        coefficients = 0;
        exponents = 0;
        next = nullptr;
    }

    node(double coefficients, int exponents) : coefficients(coefficients), exponents(exponents), next(nullptr) {
    }

    ~node() {
        delete next;
    }


};
