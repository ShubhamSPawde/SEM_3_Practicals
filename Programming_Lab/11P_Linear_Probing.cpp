#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

class Colddrink
{
public:
    int id;
    string colddrink_name;
    int price;

    Colddrink()
    {
        id = -1;
    }
};

class hash_table
{
public:
    Colddrink ht[SIZE];

    hash_table()
    {
        for (int i = 0; i < SIZE; i++)
        {
            ht[i].id = -1;
        }
    }

    void insert(int id, string name, int price)
    {
        int h = id % SIZE;
        int i = 0;

        while ((ht[(h + i) % SIZE].id != -1) && (i < SIZE))
        {
            i++;
        }

        if (i == SIZE)
        {
            cout << "Hash table is Full!" << endl;
            return;
        }

        ht[(h + i) % SIZE].id = id;
        ht[(h + i) % SIZE].colddrink_name = name;
        ht[(h + i) % SIZE].price = price;
        cout << "Inserted (" << id << ", " << name << ", " << price << ")\n";
    }

    bool search(int id)
    {
        int h = id % SIZE;
        int i = 0;

        while (i < SIZE)
        {
            if (ht[(h + i) % SIZE].id == id)
            {
                return true;
            }
            i++;
        }
        return false;
    }

    void display()
    {
        cout << "ID\tColddrink\tPrice\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (ht[i].id != -1)
            {
                cout << ht[i].id << "\t" << ht[i].colddrink_name << "\t" << ht[i].price << endl;
            }
            else
            {
                cout << "Empty Slot" << endl;
            }
        }
    }
};

int main()
{
    hash_table h1;
    int id;
    string name;
    int price;
    int n;

    cout << "How many Entries do you want to insert: ";
    cin >> n;

    cout << "Enter id, name, price for each entry\n";
    for (int i = 0; i < n; i++)
    {
        cin >> id >> name >> price;
        h1.insert(id, name, price);
    }

    cout << "\nEnter id to search for: ";
    cin >> id;

    if (h1.search(id))
    {
        cout << "Found!\n";
    }
    else
    {
        cout << "Not Found!\n";
    }

    cout << "\nHash Table Content:\n";
    h1.display();

    return 0;
}
