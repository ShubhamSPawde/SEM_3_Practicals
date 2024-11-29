#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    // int prn;
    string name;
    int marks;
    node *next;
    node *prev;

    node(){
        next = NULL;
        prev = NULL;
    }
};

class marklist{
    node *head;
    public:
    marklist(){
        head = NULL;
    }
    int create();
    void display();
    void sort(int n);
    marklist merge(marklist l3);
};

int marklist :: create(){
    node *temp, *p;
    int cnt = 0;
    char ch;
    do{
        temp = new node;
        cout<<"Enter marks and name : ";
        cin>> temp->marks >> temp->name;
        cnt++;
        if(head == NULL){
            head = temp;
        }else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout<<"Do u want to add more(Y/N) ?";
        cin>>ch;
    }while(ch != 'N');
    return cnt;
}

void marklist::display() {
    node *p = head;
    cout << " \t Name \t Marks" << endl;
    if (p == NULL) {
        cout << "List is empty";
    } else {
        while (p != NULL) {
            cout <<"\t" << p->name << "\t" << p->marks << endl;
            p = p->next;
        }
        cout << endl;
    }
}

marklist marklist::merge(marklist l2){
    marklist l3;
    node *p = head;
    node *q = l2.head;
    node *r = NULL;

    if(p == NULL && q == NULL){
        return l3;
    }
    if(p == NULL){
        l3.head = q;
        return l3;
    }
    if(q == NULL){
        l3.head = p;
        return l3;
    }
    if(p->marks > q->marks){
        l3.head = r = p;
        p = p -> next;
    }else{
        l3.head = r = q;
        q = q -> next;
    }
    while(p!=NULL && q!=NULL){
        if(p->marks > q->marks){
            r->next = p;
            p->prev = r;
            r = p;
            p = p->next;
        }else{
            r->next = q;
            q->prev = r;
            r = q;
            q = q->next;
        }
    }

    if(p == NULL){
        r->next = q;
        if(q!=NULL){
            q->prev = r;
        }
    }
    else{
        r->next = p;
        if(p!=NULL){
            p->prev = r;
        }
        
    }
    return l3;
}

void marklist::sort(int n){
    node *q, *ptr1, *ptr2, *temp; 
    for(int i = 0; i<n-1; i++){
        q = head;
        while(q->next!=NULL){
            if(q->marks < q->next->marks){
                ptr1 = q;
                ptr2 = q->next;
                temp = ptr2->next;



                if(ptr2->prev != NULL){
                    ptr2->prev->next =ptr2;
                }else{
                    head = ptr2;
                }

                if(temp != NULL){
                    temp->prev = ptr1;
                }
                q= ptr2;
            }
            q = q->next;
        }
    }
}


int main(){

}