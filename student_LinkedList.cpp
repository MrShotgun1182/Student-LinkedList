#include <iostream>
# include <unistd.h>

using namespace std;

void animation(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text.length() < 18)
            if (text.length() < 5)
                usleep(3000);
            else
                usleep(9000);
        else
            usleep(2000);
        cout << text[i] << flush;
    }
    cout << endl;
}

struct node
{
    string first_name;
    string last_name;
    string ID;
    struct node *next;
};

class LinkedList
{
public:
    node *start;
    node *make_node();
    void add_first();
    void add_in();
    void add_last();
    void delete_first();
    void delete_in();
    void delete_last();
    void display();
    void Search();
    LinkedList()
    {
        start = NULL;
    }
};

node *LinkedList::make_node()
{
    struct node *temp;
    temp = new (struct node);

    animation("enter the name :");
    cin >> temp->first_name;
    animation("enter the last name :");
    cin >> temp->last_name;
    animation("inter the ID :");
    cin >> temp->ID;
    temp->next = NULL;

    return temp;
}

void LinkedList::delete_first()
{
    if (start == NULL)
    {
        animation("The List is Empty");
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
}

void LinkedList::delete_in()
{
    int counter;
    animation("Enter the student number:");
    cin >> counter;

    if (start == NULL)
    {
        animation("The List is Empty");
        return;
    }
    else if (start->next == NULL)
    {
        start = NULL;
        animation("The List is now Empty");
    }
    else
    {
        struct node *s, *temp;
        s = start;
        for (int i = 0; i < counter - 3 ; i++)
        {
            s = s->next;
        }
        temp = s->next;
        s->next = s->next->next;
        delete temp;
    }
}

void LinkedList::delete_last()
{
    if (start == NULL)
    {
        animation("The List is Empty");
        return;
    }
    else if (start->next == NULL)
    {
        start = NULL;
        animation("The list is now Empty");
        return;
    }

    struct node *s, *temp;
    s = start;
    while (s->next->next != NULL)
    {
        s = s->next;
    }
    temp = s->next;
    s->next = NULL;
    delete temp;
}

void LinkedList::add_first()
{
    struct node *temp;
    temp = make_node();
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
        animation(" Inserted at List");
        return;
    }
    temp->next = start;
    start = temp;
    animation(" Inserted at List");
}

void LinkedList::add_in()
{
    int counter;
    animation("Enter the student number:");
    cin >> counter;

    struct node *temp, *s;
    temp = make_node();
    if (start == NULL)
    {
        start = temp;
        animation(" Inserted at List");
        return;
    }
    s = start;
    for (int i = 0; i < counter - 2; i++)
    {
        s = s->next;
    }
    temp->next = s->next;
    s->next = temp;
    animation(" Inserted at List");
}

void LinkedList::add_last()
{
    struct node *temp, *s;
    temp = make_node();
    if (start == NULL)
    {
        start = temp;
        animation(" Inserted at List");
        return;
    }
    s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    s->next = temp;
    animation(" Inserted at List");
}

void LinkedList::display()
{
    if (start == NULL)
    {
        animation("The List is Empty");
        return;
    }
    struct node *s;
    s = start;
    animation("Elements of list are: ");
    while (s != NULL)
    {
        cout << s->first_name << "->" << s->last_name << "->" << s->ID << endl;
        cout << "|" << endl;
        cout << "v" << endl;
        s = s->next;
    }
    animation("NULL");
}

void LinkedList::Search()
{
    string Search_Content;
    int counter = 1;
    animation("Enter value from student:");
    cin >> Search_Content;

    struct node *s, *temp;
    s = start;

    if (s->first_name == Search_Content)
    {
        animation("Student number in the list:");
        cout << counter << endl;
        return;
    }
    else if (s->last_name == Search_Content)
    {
        animation("Student number in the list:");
        cout << counter << endl;
        return;
    }
    else if (s->ID == Search_Content)
    {
        animation("Student number in the list:");
        cout << counter << endl;
        return;
    }

    while (s->next != NULL)
    {
        s = s->next;
        counter++;
        if (s->first_name == Search_Content)
        {
            animation("Student number in the list:");
            cout << counter << endl;
            return;
        }
        else if (s->last_name == Search_Content)
        {
            animation("Student number in the list:");
            cout << counter << endl;
            return;
        }
        else if (s->ID == Search_Content)
        {
            animation("Student number in the list:");
            cout << counter << endl;
            return;
        }
    }
    animation("not found value !!!");
}

int main()
{
    LinkedList Student_Linkedlist;

    int operator_index;

    animation("dorood");
    animation("khob bia shoro konim :");
    while (true)
    {
        animation("what to do?");
        animation("1) Add the student to the first list");
        animation("2) Add the student to the middle of the list");
        animation("3) Add the student to the end of the list");
        animation("4) Remove the student from the first list");
        animation("5) Remove the student from the middle of the list");
        animation("6) Remove the student from the end of the list");
        animation("7) display ");
        animation("8) Search");
        animation("9) Exit");

        cin >> operator_index;
        switch (operator_index)
        {
        case 1:
            Student_Linkedlist.add_first();
            break;

        case 2:
            Student_Linkedlist.add_in();
            break;

        case 3:
            Student_Linkedlist.add_last();
            break;

        case 4:
            Student_Linkedlist.delete_first();
            break;

        case 5:
            Student_Linkedlist.delete_in();
            break;

        case 6:
            Student_Linkedlist.delete_last();
            break;

        case 7:
            Student_Linkedlist.display();
            break;

        case 8:
            Student_Linkedlist.Search();
            break;

        case 9:
            return 0;

        default:
            continue;
        }
    }
    return 0;
}