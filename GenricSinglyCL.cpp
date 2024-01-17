#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
private:
    struct node<T> *first;
    struct node<T> *Tail;  // Added Tail member
    int Count;

public:
    SinglyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int ipos);
    void DeleteAtPos(int ipos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    Tail = NULL;
    Count = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)  // Check if the linked list is empty
    {
        first = newn;
        Tail = newn;  // Set Tail for the first element
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Tail->next = first;  // Update Tail for circular linked list
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)  // Check if the linked list is empty
    {
        first = newn;
        Tail = newn;
        Tail->next = first;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
        Tail->next = first;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (first == NULL)  // Case 1: Empty list
    {
        return;
    }
    else if (first == Tail)  // Case 2: Only one element
    {
        delete first;
        first = NULL;
        Tail = NULL;
    }
    else  // Case 3: More than one element
    {
        struct node<T> *temp = first;
        first = first->next;
        Tail->next = first;
        delete temp;
    }
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (first == NULL)  // Case 1: Empty list
    {
        return;
    }
    else if (first == Tail)  // Case 2: Only one element
    {
        delete first;
        first = NULL;
        Tail = NULL;
    }
    else  // Case 3: More than one element
    {
        struct node<T> *temp = first;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = first;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<< "Elements of Linked List are :" << "\n";

    if (first != NULL)
    {
        struct node<T> *temp = first;
        do
        {
             cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        } while (temp != Tail->next);

       
        cout<< "Address of First node:" <<"\n";
    }
}

template <class T>
int SinglyCL<T>::CountNode()
{
    int count = 0;
    if (first != NULL)
    {
        struct node<T> *temp = first;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != Tail->next);
    }
    return count;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int size = CountNode();
    struct node<T> *newn = new struct node<T>;

    if ((ipos < 1) || (ipos > size + 1))
    {
        std::cout << "Invalid position" << "\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn->data = no;
        newn->next = NULL;
        struct node<T> *temp = first;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int size = CountNode();

    struct node<T> *temp = first;
    struct node<T> *targetednode = NULL;

    if ((ipos < 1) || (ipos > size))
    {
        std::cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        targetednode = temp->next;
        temp->next = temp->next->next;
        delete targetednode;
    }
}

int main()
{
    SinglyCL<int> iobj;
    SinglyCL<float> fobj;
    SinglyCL<double> dobj;
    SinglyCL<char> cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    std::cout << "LinkedList of integers: " << "\n";
    iobj.Display();

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    std::cout << "LinkedList of Floats: " << "\n";
    fobj.Display();

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    std::cout << "LinkedList of Doubles: " << "\n";
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    std::cout << "LinkedList of Characters: " << "\n";
    cobj.Display();

    return 0;
}
