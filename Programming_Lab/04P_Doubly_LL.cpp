#include <iostream>
using namespace std;

class node {
public:
    int prn;
    string name;
    int marks;
    node *next;
    node *prev;

    node() {
        next = NULL;
        prev = NULL;
    }
};

class marklist {
    node *head;

public:
    marklist() {
        head = NULL;
    }

    int create();
    void display();
    void sort(int n);
    marklist merge(marklist l2);
};

int marklist::create() {
    int cnt = 0;
    char ch;
    do {
        node *temp, *p;
        temp = new node;
        cout << "Enter the data (PRN, Name, Marks):" << endl;
        cin >> temp->prn >> temp->name >> temp->marks;
        cnt++;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout << "Do you want to add more nodes? (Y/N): ";
        cin >> ch;
    } while (ch != 'N');
    return cnt;
}

void marklist::display() {
    node *p = head;
    cout << "\nPRN \t Name \t Marks" << endl;
    if (p == NULL) {
        cout << "List is empty";
    } else {
        while (p != NULL) {
            cout << p->prn << "\t" << p->name << "\t" << p->marks << endl;
            p = p->next;
        }
        cout << endl;
    }
}

void marklist::sort(int n) {
    node *q, *ptr1, *ptr2, *temp;
    for (int i = 0; i < n - 1; i++) {
        q = head;
        while (q->next != NULL) {
            if (q->marks < q->next->marks) {
                ptr1 = q;
                ptr2 = q->next;
                temp = ptr2->next;

                ptr2->next = ptr1;
                ptr2->prev = ptr1->prev;
                ptr1->next = temp;
                ptr1->prev = ptr2;

                if (ptr2->prev != NULL) {
                    ptr2->prev->next = ptr2;
                } else {
                    head = ptr2;
                }

                if (temp != NULL) {
                    temp->prev = ptr1;
                }
                q = ptr2;
            }
            q = q->next;
        }
    }
}

marklist marklist::merge(marklist l2) {
    marklist l3;
    node *p = head;
    node *q = l2.head;
    node *r = NULL;

    if (p == NULL && q == NULL) {
        return l3;
    }
    if (p == NULL) {
        l3.head = q;
        return l3;
    }
    if (q == NULL) {
        l3.head = p;
        return l3;
    }

    if (p->marks > q->marks) {
        l3.head = r = p;
        p = p->next;
    } else {
        l3.head = r = q;
        q = q->next;
    }

    while (p != NULL && q != NULL) {
        if (p->marks > q->marks) {
            r->next = p;
            p->prev = r;
            r = p;
            p = p->next;
        } else {
            r->next = q;
            q->prev = r;
            r = q;
            q = q->next;
        }
    }

    if (p == NULL) {
        r->next = q;
        if (q != NULL) q->prev = r;
    } else {
        r->next = p;
        if (p != NULL) p->prev = r;
    }

    return l3;
}

int main() {
    marklist l1, l2, l3;

    cout << "Entering List 1:" << endl; 
    int cnt1 = l1.create();
    cout << "Entering List 2:" << endl; 
    int cnt2 = l2.create();

    cout << "List 1:" << endl;
    l1.display();
    cout << "List 2:" << endl;
    l2.display();

    l1.sort(cnt1);
    l2.sort(cnt2);

    cout << "Sorted List 1:" << endl;
    l1.display();
    cout << "Sorted List 2:" << endl;
    l2.display();

    l3 = l1.merge(l2);
    cout << "Merged and Sorted List:" << endl;
    l3.display();

    return 0;
}
