#include <iostream>
#include "node.h"
#include "polonomial.h"

using namespace std;


int main() {
    // TODO ������ ��� �Լ� ������ �� ������ �ùٸ��� �۵��ϴ��� Ȯ���ϱ� ȣ�� ���� ���� ���׽��� ���� ǥ��
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


    p1 -= p2;


//    cout << p1.eval(1) << endl;
//    copy.show_content(copy.head);
//    copy.show_content(copy.head);
//



    return 0;

}

