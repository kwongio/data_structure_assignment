#include <ostream>
using namespace std;

class node {
public:
    double coefficients = 0.0;
    unsigned exponents = 0 ;
    node *next = nullptr;

    node() {
        coefficients = 0;
        exponents = 0;
        next = nullptr;
    }

    node(double coefficients, int exponents) : coefficients(coefficients), exponents(exponents), next(nullptr) {
    }

     ~node() {
        cout << "node" << endl;
         delete next;

    }


    void print() {
        cout << "coefficients" << coefficients << endl;
        cout << "exponents" << exponents << endl;
    }


};
