#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int prn;
    string name;
    float cgpa;
    Student *next;
    Student()
    {
        next = NULL;
    }
};

class StudentList
{
public:
    Student *head;
    StudentList()
    {
        head = NULL;
    }
    void create();
    void display();
    void append();
    void insert_head();
    void insert_after();
    void search();
    void update();
    void delete_by_prn();   
    void count_students();  
    void sort_by_cgpa();    
    void reverse_list();    
};

void StudentList::display()
{
    if (head == NULL)
    {
        cout << "LinkedList is Empty!" << endl;
    }
    else
    {
        Student *p = head;
        while (p != NULL)
        {
            cout << p->prn << endl;
            cout << p->name << endl;
            cout << p->cgpa << endl;
            p = p->next;
        }
    }
}

void StudentList::create()
{
    Student *temp, *p;
    char ch;

    do
    {
        temp = new Student();
        cout << "\nEnter PRN, Name, CGPA : " << endl;
        cin >> temp->prn >> temp->name >> temp->cgpa;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
            cout << "Do you want to add more? (Y/N)" << endl;
            cin >> ch;
        }
    } while (ch != 'N');
}

void StudentList::append()
{
    Student *temp, *p;
    temp = new Student();
    cout << "Enter PRN,Name,CGPA : " << endl;
    cin >> temp->prn >> temp->name >> temp->cgpa;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void StudentList::insert_head()
{
    Student *temp, *p;
    temp = new Student();
    cout << "Enter PRN,Name,CGPA : " << endl;
    cin >> temp->prn >> temp->name >> temp->cgpa;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void StudentList::insert_after()
{
    int x;
    Student *temp, *p = head;
    temp = new Student();
    cout << "After which PRN you want to insert?" << endl;
    cin >> x;
    cout << "Enter PRN, Name, CGPA : " << endl;
    cin >> temp->prn >> temp->name >> temp->cgpa;

    bool flag = false;
    while (p != NULL)
    {
        if (p->prn == x)
        {
            flag = true;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (flag == false)
    {
        cout << "PRN not found!" << endl;
    }
    else
    {
        temp->next = p->next;
        p->next = temp;
    }
}

void StudentList::search()
{
    int x;
    cout << "Which PRN you want to search?" << endl;
    cin >> x;
    bool flag = false;
    Student *p = head;
    while (p != NULL)
    {
        if (p->prn == x)
        {
            flag = true;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (flag == false)
    {
        cout << "PRN not found!" << endl;
    }
    else
    {
        cout << "PRN found!" << endl;
    }
}

void StudentList::update()
{
    int x;
    Student *p = head, *temp;
    cout << "Which PRN you want to update?" << endl;
    cin >> x;
    cout << "Enter PRN, Name, CGPA : " << endl;
    cin >> temp->prn >> temp->name >> temp->cgpa;
    bool flag = false;
    while (p != NULL)
    {
        if (p->prn == x)
        {
            flag = true;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    if (flag == false)
    {
        cout << "PRN not found!" << endl;
    }
    else
    {
        p = temp;
        cout << "PRN Updated!" << endl;
    }
}

void StudentList::delete_by_prn()
{
    int x;
    cout << "Enter the PRN of the student to delete: ";
    cin >> x;

    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->prn == x)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        cout << "Student with PRN " << x << " deleted." << endl;
        return;
    }

    Student *p = head;
    while (p->next != NULL && p->next->prn != x)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        cout << "PRN not found!" << endl;
    }
    else
    {
        Student *temp = p->next;
        p->next = p->next->next;
        delete temp;
        cout << "Student with PRN " << x << " deleted." << endl;
    }
}

void StudentList::count_students()
{
    int count = 0;
    Student *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    cout << "Total number of students: " << count << endl;
}

void StudentList::sort_by_cgpa()
{
    if (head == NULL || head->next == NULL)
        return;

    for (Student *i = head; i != NULL; i = i->next)
    {
        for (Student *j = i->next; j != NULL; j = j->next)
        {
            if (i->cgpa < j->cgpa)
            {
                swap(i->prn, j->prn);
                swap(i->name, j->name);
                swap(i->cgpa, j->cgpa);
            }
        }
    }
    cout << "List sorted by CGPA in descending order." << endl;
}

void StudentList::reverse_list()
{
    Student *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "List reversed." << endl;
}

int main()
{
    StudentList s1;
    int choice;

    do
    {
        cout << "\n1. Create\n2. Display\n3. Insert at head\n4. Append\n5. Insert After\n6. Search\n7. Update\n8. Delete by PRN\n9. Count Students\n10. Sort by CGPA\n11. Reverse List\n12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.create();
            break;
        case 2:
            s1.display();
            break;
        case 3:
            s1.insert_head();
            break;
        case 4:
            s1.append();
            break;
        case 5:
            s1.insert_after();
            break;
        case 6:
            s1.search();
            break;
        case 7:
            s1.update();
            break;
        case 8:
            s1.delete_by_prn();
            break;
        case 9:
            s1.count_students();
            break;
        case 10:
            s1.sort_by_cgpa();
            break;
        case 11:
            s1.reverse_list();
            break;
        case 12:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }
    } while (choice != 12);

    return 0;
}