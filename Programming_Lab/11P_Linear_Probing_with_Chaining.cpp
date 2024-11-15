#include <bits/stdc++.h>
using namespace std;

#define SIZE 20

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class HashTable
{
public:
    Node *table[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(int marks)
    {
        int h = marks % SIZE;
        Node *newNode = new Node(marks);

        if (table[h] == NULL)
        {
            table[h] = newNode;
        }
        else
        {
            Node *temp = table[h];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool search(int marks)
    {
        int h = marks % SIZE;
        Node *temp = table[h];

        while (temp != NULL)
        {
            if (temp->data == marks)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        cout << "Hash Table Content (Marks stored by index):\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    HashTable h1;
    int marks[20];

    cout << "Enter marks for 20 students:\n";
    for (int i = 0; i < 20; i++)
    {
        cin >> marks[i];
        h1.insert(marks[i]);
    }

    cout<<endl;
    
    int searchMarks;
    cout << "Enter marks to search for: ";
    cin >> searchMarks;

    if (h1.search(searchMarks))
    {
        cout << "Marks " << searchMarks << " found in the hash table.\n";
    }
    else
    {
        cout << "Marks " << searchMarks << " not found in the hash table.\n";
    }
    cout<<endl;

    h1.display();

    return 0;
}
