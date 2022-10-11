#include <iostream>
#include "polonomial.h"
#include "conio.h"
using namespace std;

int main() {

    polynomial p1;
    node *n1 = new node(-4.0, 0);
    node *n2 = new node(-4.0, 1);
    node *n3 = new node(-4.0, 2);
    node *n4 = new node(-4.0, 3);
    p1.list_head_insert(n4);
    p1.list_insert(n3, 1);
    p1.list_insert(n2, 2);
    p1.list_insert(n1, 3);


    polynomial p2;
    node *n5 = new node(3.0, 0);
    node *n6 = new node(3.0, 1);
    node *n7 = new node(3.0, 2);
    node *n8 = new node(3.0, 3);
    p2.list_head_insert(n8);
    p2.list_insert(n7, 1);
    p2.list_insert(n6, 2);
    p2.list_insert(n5, 3);

    cout << "Data Structure " << endl;
    cout << "Student Id: 2019203058" << endl;
    cout << "name: Kwon gio" << endl;
    cout << "" << endl;
    cout << "p1: ";
    p1.show_content();
    cout << "p2: ";
    p2.show_content();
    cout << "" << endl;

    cout << "p1.list_length(): " << p1.list_length() << endl;
    cout << "p2.list_length(): " << p2.list_length() << endl;
    cout << "" << endl;

    cout << "p1.list_search(n1): " << p1.list_search(n1) << endl;
    cout << "p1.list_search(n1)->coefficients: " << p1.list_search(n1)->coefficients << endl;
    cout << "p1.list_search(n1)->exponents: " << p1.list_search(n1)->exponents << endl;
    cout << "" << endl;

    for (int i = 0; i < p1.list_length(); ++i) {
        cout << "p1.list_locate(" << i << "): " << p1.list_locate(i) << endl;
        cout << "p1.list_locate(" << i << ")->coefficients: " << p1.list_locate(i)->coefficients << endl;
        cout << "p1.list_locate(" << i << ")->exponents: "<< p1.list_locate(i)->exponents << endl;
        cout << "" << endl;
    }

    polynomial p3(p2);
    polynomial p4(4.0);
    cout << "polynomial p3(p2) copy constructor:  ";
    p3.show_content();
    cout << "" << endl;

    cout << "polynomial p4(4.0):  ";
    p4.show_content();
    cout << "" <<endl;

    p3.list_copy(p1);

    cout << "p3.list_copy(p1):  ";
    p3.show_content();
    cout << "" << endl;


    p3.list_remove(1);
    cout << "p3.list_remove(1): ";
    p3.show_content();
    cout << "" << endl;

    p3.list_head_remove();
    cout << "p3.list_head_remove(): ";
    p3.show_content();
    cout << "" << endl;

    cout << "p3.list_length(): " << p3.list_length() << endl;
    cout << "" << endl;


    cout << "p3.list_clear(): ";
    p3.list_clear();
    p3.show_content();
    cout << "" << endl;


    cout << "p3 = p1 + p2: ";
    p3 = p1 + p2;
    p3.show_content();


    cout << "p3 = p1 - p2: ";
    p3 = (p1 - p2);
    p3.show_content();


    cout << "p3 = p1 * p2: ";
    p3 = p1 * p2;
    p3.show_content();

    cout << "p3 += p1: ";
    p3 += p1;
    p3.show_content();

    cout << "p3 -= p1;: ";
    p3 -= p1;
    p3.show_content();

    cout << "p3 *= p1: ";
    p3 *= p1;
    p3.show_content();

    system("pause");
    return 0;

}

