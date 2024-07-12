#include <iostream>
#include <unistd.h>

using namespace std;

void loading (){
	cout << "LOADING : ";
	sleep (2);
	for (int i = 0 ; i < 9 ; i ++)
	{
		cout<< ".";
		usleep(50000);
	}
	sleep (2);
	for (int i =1 ; i <11 ; i++)
	{
		cout << ".";
		usleep (50000);
	}
	cout << endl ;
	sleep(1);
	cout << "100% \npackages loaded ...";
	sleep (1);
	cout << "\n PROGRAM IS READY";
	sleep (2);
	cout << endl << endl ;
}
//////////////////////////////////////////////////////////////////////////
void animation(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text.length() < 18)
            if (text.length() < 5)
                usleep(30000);
            else
                usleep(90000);
        else
            usleep(20000);
        cout << text[i] << flush;
    }
    cout << endl ;
}
////////////////////////////////////////////////////////////////////////
struct node
{ 
    int info;
    struct node *next;
};
///////////////////////////////////////////////////////////////////////
class LinkedList {
    public:
        node* start; 
        node* make_node(int value);
        void add_last(int value);
        void add_first(int value);
        void add_in(int counter, int value);
        void delete_last();
        void delete_first();
        void delete_in(int counter);
        void display();
        LinkedList()
        { 
            start = NULL;
        }
};
node *LinkedList::make_node(int value) {
    struct node *temp;
    temp = new (struct node);
    temp->info = value;
    temp->next = NULL;
    return temp;
}
void LinkedList::delete_last() {
    if (start == NULL)
	{ 
        animation("The List is Empty");
        return;
    }
    else if (start->next == NULL)
    {
        start = NULL;
        animation("The list is now Empty");
    }
    else
    {
    struct node *s, *temp;
    s = start; 
    while (s->next->next != NULL)
	{ 
        s = s->next;
    }
    temp = s->next->next;
    s->next = NULL;
    delete temp;
    }
}
void LinkedList::delete_first() {
    if (start == NULL)
	{ 
        animation("The List is Empty");
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp; 
}
void LinkedList::delete_in(int counter)
{
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
        for(int i = 0 ; i<counter-3 ; i++)
        {
            s = s->next;
        }
        temp = s->next;
        s->next = s->next->next;
        delete temp;
    }
}
void LinkedList::add_last(int value) { 
    struct node *temp, *s;
    temp = make_node(value);
    if(start == NULL)
	{ 
        start = temp; 
        start->next = NULL;
        cout << value ;
        animation(" Inserted at List");
        return; 
    }
    s = start; 
    while (s->next != NULL)
	{ 
        s = s->next;
    } 
    temp->next = NULL;
    s->next = temp;
    cout << value;
    animation(" Inserted at List");
}
void LinkedList::add_first(int value)
{
    //TODO: This is just an easter egg, don't pay attention
        if(value == 14)
        {
        	int i = 0 ;
            while(1)
            {
                cout << "010101010101010110101010110110010101010" ;
                i ++;
                if (i == 100)
                {
                	cout << "A....?    ";
                    cout << "khob hala aghaie shabany moshkeli nadari ?????????";
				}
            }
        }
    struct node *temp ;
    temp = make_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
        cout << value;
        animation(" Inserted at List");
        return;
    }
    temp->next = start;
    start = temp;
    cout << value;
    animation(" Inserted at List");
}
void LinkedList::add_in(int counter, int value)
{
    struct node *temp, *s;
    temp = make_node(value);
    if(start == NULL)
	{
        start = temp;
        cout << value;
        animation(" Inserted at List");
        return;
    }
    s = start;
    for (int i = 0 ; i < counter-2 ; i++)
    {
        s = s->next;
    }
    temp->next = s->next;
    s->next = temp;
    cout << value;
    animation(" Inserted at List"); 
}
void LinkedList::display() {
    struct node *temp;
    if (start == NULL) 
	{ 
        animation("The List is Empty");
        return; 
    } 
    temp = start; 
    animation("Elements of list are: ");
    while (temp != NULL)
	{ 
        cout << temp->info << "->";
        temp = temp->next;
    } 
    animation("NULL");
}
///////////////////////////////////////////////////////////////////////////
int main() {
    loading();
    system("color 0A");
    LinkedList test;
    test.add_first("1");
    test.add_last(100);
    test.add_first(2);
    test.add_in(50,2);
	test.add_first(5);
	test.add_first(9);
    test.add_in(55,2);
	test.display();
    test.delete_in(2);
    test.display();
    return 0; 
}