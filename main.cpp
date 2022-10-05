#include <iostream>
#include "polonomial.h"

using namespace std;


int main() {
    // TODO 구현한 모든 함수 생성자 및 연산자 올바르게 작동하는지 확인하기 호출 전후 현재 다항식의 내용 표시
    polynomial p1;

    node *first = new node(4.0, 0);
    node *second = new node(4.0, 1);
    node *third = new node(4.0, 2);
    node *forth = new node(4.0, 3);
    p1.list_head_insert(forth);
    p1.list_insert(third, 1);
    p1.list_insert(second, 2);
    p1.list_insert(first, 3);


    polynomial p2;
    node *first1 = new node(1.0, 0);
    node *second2 = new node(1.0, 1);
    node *third3 = new node(1.0, 2);
    node *forth4 = new node(1.0, 3);
    p2.list_head_insert(forth4);
    p2.list_insert(third3, 1);
    p2.list_insert(second2, 2);
    p2.list_insert(first1, 3);

    polynomial p3;

    p3 = (p2 - p1);
    p3 = (p2 - p1);
    p3 = (p2 - p1);


    cout << "====================" << endl;
    p1.show_content(p1.head);
    p2.show_content(p2.head);
    p3.show_content(p3.head);

    return 0;

}

