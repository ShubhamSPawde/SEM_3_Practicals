#include<iostream>
using namespace std;
#define SIZE 4

class Queue
{
    public:
    int arr[SIZE];
    int front;
    int rear;
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty();
    void enqueue_at_first(int x);
    void enqueue_at_rear(int x);
    int dequeue_at_first();
    int dequeue_at_end();
    void display();
};
bool Queue::isEmpty(){
   return(front == -1 && rear == -1);

}
void Queue ::enqueue_at_rear(int x){
    if(front == 0 && rear == SIZE - 1){
        cout <<"Full";
        return;
    }else if(isEmpty()){
        front = 0;
        rear = 0;
    }else{
        rear++;
    }
    arr[rear]=x;
}
void Queue::enqueue_at_first(int x){
    if(front == 0 && rear == SIZE - 1){
        cout << "full";
        return;
    }else if(isEmpty()){
        front = 0;
        rear = 0;
    }else{
        front --;
    }
    arr[front] = x;
}
int Queue::dequeue_at_first(){
    int x=arr[front];
    if(isEmpty()){
        cout << "Not possible";
    }else if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front++;
    }
    return x;
}
int Queue::dequeue_at_end(){
    int x=arr[rear];
    if(isEmpty()){
        cout <<"Not possible";
        return 0;
    }else if(front == rear){
        front = -1;
        rear = -1;
    }else{
        rear--;
    }
    return x;
}
void Queue::display(){
    for(int i = front; i <= rear; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int main(){
    Queue q1;
    Queue q2;
    int choice = 0;

    do{
        cout <<"Input restricted Queue"<<endl;
        cout <<"Output restricted Queue" << endl;
        cout <<"enter your choice: "<<endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            int choice1;
            do{
                cout<<"1.Enqueue at rear"<<endl;
                cout<<"2.Dequeue at front"<<endl;
                cout<<"3.Dequeue at rear"<<endl;
                cout<<"4.Display Queue"<<endl;
                cout<<"5.Back menu"<<endl;
                cout<<"enter your choice";
                cin>>choice1;
                switch(choice1)
                {
                    case 1:
                    int x;
                    cout<<"Enter value: ";
                    cin>>x;
                    q1.enqueue_at_first(x);
                    break;
                    case 2:
                    q1.dequeue_at_end();
                    break;
                    case 3:
                    q1.dequeue_at_first();
                    break;
                    case 4:
                    q1.display();
                    break;
                    case 5:
                    break;
                }
                }
                while(choice!=5);
                break;


            case 2:
            int choice2;
            do{
                cout<<"1.Enqueue at rear"<<endl;
                cout<<"2.Enqueue at front"<<endl;
                cout<<"3.Dequeue at front"<<endl;
                cout<<"4.Display Queue"<<endl;
                cout<<"5.Back menu"<<endl;
                cout<<"enter your choice";
                cin>>choice2;
                switch(choice2)
                {
                    case 1:
                    int x;
                    cout<<"Enter value: ";
                    cin>>x;
                    q1.enqueue_at_first(x);
                    break;
                    case 2:
                    q1.enqueue_at_rear();
                    break;
                    case 3:
                    q1.dequeue_at_first();
                    break;
                    case 4:
                    q1.display();
                    break;
                    case 5:
                    break;
                }
                }
                while(choice!=5);
                break;
        }
    }
    while(choice!=10);
}