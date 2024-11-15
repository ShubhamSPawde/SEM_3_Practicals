#include <bits/stdc++.h>
using namespace std;
#define SIZE 11

class MangoVariety
{
public:
    int quantity;
    string category_name;

    MangoVariety()
    {
        quantity = -1;
    }
};

class HashTable
{
public:
    MangoVariety ht[SIZE];

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            ht[i].quantity = -1;
        }
    }

    void insert(int quantity, string category_name)
    {
        int h = quantity % SIZE;
        int i = 0;

        while ((ht[(h + i * i) % SIZE].quantity != -1) && (i < SIZE))
        {
            i++;
        }

        if (i == SIZE)
        {
            cout << "Hash table is Full!" << endl;
            return;
        }

        ht[(h + i * i) % SIZE].quantity = quantity;
        ht[(h + i * i) % SIZE].category_name = category_name;
        cout << "Inserted (" << quantity << ", " << category_name << ")\n";
    }

    bool search(int quantity)
    {
        int h = quantity % SIZE;
        int i = 0;

        while (i < SIZE){

            int pos = (h + i * i) % SIZE;
            
            if (ht[pos].quantity == quantity){
                return true;
            }

            if (ht[pos].quantity == -1){
                return false;
            }
            i++;
        }
        return false;
    }

    void display(){
        cout << "Quantity\tCategory Name\n";
            
        for (int i = 0; i < SIZE; i++){
            if (ht[i].quantity != -1)
            {
                cout << ht[i].quantity << "\t\t" << ht[i].category_name << endl;
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
    HashTable h1;
    int n;

    cout << "Enter the number of mango varieties (up to " << SIZE << "): ";
    cin >> n;

    if (n > SIZE) {
        cout << "Error: The maximum number of varieties is " << SIZE << ".\n";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int quantity;
        string category_name;
        
        cout << "Enter quantity for variety " << i + 1 << ": ";
        cin >> quantity;
        cout << "Enter category name for variety " << i + 1 << ": ";
        cin >> category_name;
        
        h1.insert(quantity, category_name);
    }

    int quantity;
    cout << "\nEnter quantity to search for: ";
    cin >> quantity;

    if (h1.search(quantity))
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
