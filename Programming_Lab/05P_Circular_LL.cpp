#include <bits/stdc++.h>
using namespace std;

class Pizza
{
public:
    int order_id;
    string pizza_name;
    float price;
    Pizza *next;

    Pizza()
    {
        next = NULL;
    }
};

class PizzaShop
{
public:
    Pizza *head;

    PizzaShop()
    {
        head = NULL;
    }

    void order();
    void display();
    void deliver();
    void search(int x);
    void update(int x);
    void cancel(int x);
    void count_orders();
    void calculate_revenue();
    void find_most_expensive();
};

void PizzaShop::order()
{
    Pizza *temp;
    char ch;
    temp = new Pizza();
    cout << "Enter Order Id, Pizza Name, Price: " << endl;
    cin >> temp->order_id >> temp->pizza_name >> temp->price;

    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Pizza *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
}

void PizzaShop::display()
{
    if (head == NULL)
    {
        cout << "Order is Empty!" << endl;
    }
    else
    {
        Pizza *p = head;
        cout << "\n"
             << "Order Id" << "\t" << "Pizza Name" << "\t" << "Price" << endl;
        do
        {
            cout << p->order_id << "\t";
            cout << p->pizza_name << "\t";
            cout << p->price << "\t";
            p = p->next;
            cout << endl;
        } while (p != head);
    }
}

void PizzaShop::deliver()
{
    Pizza *p;
    if (head == NULL)
    {
        cout << "No Order Left" << endl;
    }
    else if (head->next == head)
    {
        p = head;
        head = NULL;
        p->next = NULL;
        delete p;
    }
    else
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        p = head;
        head = head->next;
        p->next = NULL;
        cout << "Order Delivered!" << endl;
        delete p;
    }
}

void PizzaShop::search(int x)
{
    bool flag = false;
    Pizza *p = head;
    do
    {
        if (p->order_id == x)
        {
            flag = true;
            break;
        }
        p = p->next;
    } while (p != head);
    if (flag == false)
    {
        cout << "Order ID not found!" << endl;
    }
    else
    {
        cout << "Order ID found!" << endl;
    }
}

void PizzaShop::update(int x)
{
    Pizza *p = head;
    do
    {
        if (p->order_id == x)
        {
            cout << "Enter Order Id, Pizza Name, Price: " << endl;
            cin >> p->order_id;
            cin >> p->pizza_name;
            cin >> p->price;
            cout << "Order Updated!" << endl;
            return;
        }
        p = p->next;
    } while (p != head);
    cout << "Order not found!" << endl;
}

void PizzaShop::cancel(int x)
{
    Pizza *prev, *p = head;
    if (head == NULL)
    {
        cout << "No Order to cancel" << endl;
        return;
    }
    if (head->next == head && head->order_id == x)
    {
        p = head;
        head = NULL;
        p->next = NULL;
        delete p;
        return;
    }
    if (head->order_id == x)
    {
        p = head;
        do
        {
            p = p->next;
        } while (p->next != head);
        p->next = head->next;

        p = head;
        head = head->next;
        p->next = NULL;
        delete p;
        cout << "Order Cancelled!" << endl;
        return;
    }

    p = head;
    prev = NULL;
    do
    {
        if (p->order_id == x)
        {
            prev->next = p->next;
            p->next = NULL;
            delete p;
            cout << "Order Cancelled!" << endl;
            break;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    } while (p != head);
}

void PizzaShop::count_orders()
{
    if (head == NULL)
    {
        cout << "No orders available." << endl;
        return;
    }

    int count = 0;
    Pizza *p = head;
    do
    {
        count++;
        p = p->next;
    } while (p != head);

    cout << "Total orders: " << count << endl;
}

void PizzaShop::calculate_revenue()
{
    if (head == NULL)
    {
        cout << "No orders to calculate revenue." << endl;
        return;
    }

    float total_revenue = 0;
    Pizza *p = head;
    do
    {
        total_revenue += p->price;
        p = p->next;
    } while (p != head);

    cout << "Total revenue: $" << total_revenue << endl;
}

void PizzaShop::find_most_expensive()
{
    if (head == NULL)
    {
        cout << "No orders available." << endl;
        return;
    }

    Pizza *p = head;
    Pizza *most_expensive = head;

    do
    {
        if (p->price > most_expensive->price)
        {
            most_expensive = p;
        }
        p = p->next;
    } while (p != head);

    cout << "Most expensive order:\n";
    cout << "Order Id: " << most_expensive->order_id << endl;
    cout << "Pizza Name: " << most_expensive->pizza_name << endl;
    cout << "Price: $" << most_expensive->price << endl;
}

int main()
{
    int choice, x;
    PizzaShop s1;

    do
    {
        cout << endl;
        cout << "1. Order" << endl;
        cout << "2. Display" << endl;
        cout << "3. Deliver" << endl;
        cout << "4. Cancel Order" << endl;
        cout << "5. Search" << endl;
        cout << "6. Update" << endl;
        cout << "7. Count Total Orders" << endl;
        cout << "8. Calculate Total Revenue" << endl;
        cout << "9. Find Most Expensive Order" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.order();
            break;
        case 2:
            s1.display();
            break;
        case 3:
            s1.deliver();
            break;
        case 4:
            cout << "Enter the Order Id which you want to cancel: ";
            cin >> x;
            s1.cancel(x);
            break;
        case 5:
            cout << "Enter the Order Id which you want to search: ";
            cin >> x;
            s1.search(x);
            break;
        case 6:
            cout << "Enter the Order Id which you want to update: ";
            cin >> x;
            s1.update(x);
            break;
        case 7:
            s1.count_orders();
            break;
        case 8:
            s1.calculate_revenue();
            break;
        case 9:
            s1.find_most_expensive();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);
}
