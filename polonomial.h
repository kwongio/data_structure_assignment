#include <iostream>
#include "node.h"
using namespace std;

class polynomial {

public:
    node *head = nullptr;
    int size = 0;

    polynomial() {
        head = nullptr;
        size = 0;
    };

    polynomial(double a0) {
        head = new node(a0, 0);
        size = 1;

    };

    polynomial(polynomial &source) {
        list_copy(source);
    };

    ~polynomial() {
        cout << "poly deconstructr" << endl;
        size = 0;
        if (head != nullptr) {

            delete head;
        }

    }


    void list_head_insert(node *newItem);

    node *list_search(node *item);

    int list_length() const;

    node *list_locate(int index);

    void list_insert(node *newItem, int index);

    void list_head_remove();

    void list_remove(int index);

    void list_clear();

    void list_copy(polynomial &copy);

    bool isEmpty();

    void show_content();

    double eval(int x);

    int getMaxExponent(node *p1, node *p2);

    double *ploySort(node *p1, node *p2, char sign);

    void getSortedPoly(double *sortArray, int exponent);

    void polynomial::getPoly(double *sortArray, int maxExponent, polynomial &p);


    polynomial &operator+(polynomial &p);

    polynomial &operator-(polynomial &p);

    polynomial &operator*(polynomial &p);

    polynomial &operator*=(polynomial &p);

    void operator-=(polynomial &p);

    void operator+=(polynomial &p);

    void operator=(polynomial &p);
};


//TODO 에러 발생 맥에서
void polynomial::operator-=(polynomial &p) {
    double *sortArray = ploySort(head, p.head, '-');
    int maxExponent = getMaxExponent(p.head, head);
    getSortedPoly(sortArray, maxExponent);
}


void polynomial::operator+=(polynomial &p) {
    double *sortArray = ploySort(head, p.head, '+');

    int maxExponent = getMaxExponent(p.head, head);
    getSortedPoly(sortArray, maxExponent);
    delete[] sortArray;
}


void polynomial::operator=(polynomial &p) {
    if(this == &p){
        return;
    }
    list_clear();
    node *temp = p.head;
    list_head_insert(new node(p.head->coefficients, p.head->exponents));
    temp = temp->next;

    while (temp != nullptr) {
        list_insert(new node(temp->coefficients, temp->exponents), size);
        temp = temp->next;
    }
}


polynomial &polynomial::operator+(polynomial &p) {
    double *sortArray = ploySort(head, p.head, '+');
    int maxExponent = getMaxExponent(p.head, head);
    static polynomial copy;
    getPoly(sortArray, maxExponent, copy);
    return copy;

}


polynomial &polynomial::operator-(polynomial &p) {
    double *sortArray = ploySort(head, p.head, '-');
    int maxExponent = getMaxExponent(p.head, head);
    static polynomial copy;
    getPoly(sortArray, maxExponent, copy);
    return copy;

}

polynomial &polynomial::operator*(polynomial &p) {

    return *this;
}


polynomial &polynomial::operator*=(polynomial &p) {
    return *this;
}


void polynomial::list_head_insert(node *newItem) {
    head = newItem;
    size++;
}

int polynomial::list_length() const {
    return size;
}


bool polynomial::isEmpty() {
    return size == 0;
}

void polynomial::list_clear() {
    size = 0;
    head = nullptr;


}

void polynomial::list_head_remove() {
    node *removeNode = head;
    head = head->next;
    size--;
    delete removeNode;
}

void polynomial::list_remove(int index) {

    if (!isEmpty() && index >= 0 && index <= size - 1) {
        node *preNode = list_locate(index - 1);
        node *removeNode = preNode->next;
        preNode->next = removeNode->next;
        size--;
        delete removeNode;
    }
}

void polynomial::list_insert(node *newItem, int index) {
    if (index >= 0 && index <= size) {
        node *preNode = list_locate(index - 1);
        newItem->next = preNode->next;
        preNode->next = newItem;
        size++;
    }
}

void polynomial::list_copy(polynomial &copy) {
    if (copy.isEmpty()) {
        return;
    }
    list_clear();
    node *temp = copy.head;
    list_head_insert(new node(copy.head->coefficients, copy.head->exponents));
    temp = temp->next;

    while (temp != nullptr) {
        list_insert(new node(temp->coefficients, temp->exponents), size);
        temp = temp->next;
    }
}

node *polynomial::list_locate(int index) {
    if (isEmpty() || index < 0 || index >= size) {
        return nullptr;
    }
    node *currNode = head;
    for (int i = 0; i < index; i++) {
        currNode = currNode->next;
    }
    return currNode;
}

node *polynomial::list_search(node *item) {
    node *currNode = head;
    for (int i = 0; i < size; ++i) {
        if (currNode == item) {
            return currNode;
        }
        currNode = currNode->next;

    }
    return nullptr;
}

void polynomial::getSortedPoly(double *sortArray, int maxExponent) {
    list_clear();
    for (int i = maxExponent; i >= 0; --i) {
        if (sortArray[i] != 0) {
            if (head == nullptr) {
                list_head_insert(new node(sortArray[i], i));
            } else {

                list_insert(new node(sortArray[i], i), size);
            }
            cout << i << ": " << sortArray[i] << endl;

        }
    }
}


void polynomial::getPoly(double *sortArray, int maxExponent, polynomial &p) {
    p.list_clear();
    for (int i = maxExponent; i >= 0; --i) {
        if (sortArray[i] != 0) {
            if (p.head == nullptr) {
                p.list_head_insert(new node(sortArray[i], i));
            } else {

                p.list_insert(new node(sortArray[i], i), p.size);
            }
            cout << i << ": " << sortArray[i] << endl;

        }
    }
}


double *polynomial::ploySort(node *p1, node *p2, char sign) {
    int maxExponent = getMaxExponent(p1, p2);
    cout << "max:" << maxExponent << endl;

    auto *arr = new double[maxExponent + 1]();

    node *first = p1;
    node *second = p2;
    if (sign == '+') {
        while (first != nullptr) {
            arr[first->exponents] += first->coefficients;
            first = first->next;
        }

        while (second != nullptr) {
            arr[second->exponents] += second->coefficients;
            second = second->next;
        }

    } else if (sign == '-') {
        while (first != nullptr) {
            arr[first->exponents] += first->coefficients;
            first = first->next;
        }

        while (second != nullptr) {
            arr[second->exponents] -= second->coefficients;
            second = second->next;
        }
    }
    return arr;
}


double polynomial::eval(int x) {
    node *curr = head;
    double sum = 0;
    while (curr != nullptr) {
        if (curr->coefficients == 0) {
            sum += 1;
        } else {
            double result = 1.0;
            for (int i = 0; i < curr->exponents; ++i) {
                result *= curr->coefficients * x;
            }
            sum += result;
            curr = curr->next;
        }
    }
    return sum;
}

void polynomial::show_content() {
    node *curr = head;
    for (int i = 0; i < list_length(); ++i) {
        cout << curr->coefficients << "x^" << curr->exponents;
        if (curr->next != nullptr) {
            if (curr->next->coefficients >= 0) {
                cout << "+";
            }
        }
        curr = curr->next;
    }
    cout << "" << endl;
}


int polynomial::getMaxExponent(node *p1, node *p2) {
    return max(p1->exponents, p2->exponents);
}
