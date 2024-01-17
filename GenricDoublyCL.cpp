#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *prev;
    struct node *next;
};

template <class T>
class DoublyCL
{
private:
    struct node<T> *first;
    struct node<T> *Tail; // Add Tail to keep track of the last node
    int Count;

public:
    DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    Tail = NULL; // Initialize Tail to NULL
    Count = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if (first == NULL && Tail == NULL) // LL is empty
    {
        first = newn;
        Tail = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Tail->next = first;
    first->prev = Tail;
    Count++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if (first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
    }
    else
    {
        newn->prev = Tail;
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = first;
    first->prev = Tail;
    Count++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (first == NULL && Tail == NULL) // LL is empty
    {
        return;
    }
    else if (first == Tail) // LL contains a single node
    {
        delete first;
        first = NULL;
        Tail = NULL;
    }
    else // LL contains more than one node
    {
        first = first->next;
        delete Tail->next;
        first->prev = Tail;
        Tail->next = first;
    }
    Count--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (first == NULL && Tail == NULL) // LL is empty
    {
        return;
    }
    else if (first == Tail) // LL contains a single node
    {
        delete first;
        first = NULL;
        Tail = NULL;
    }
    else // LL contains more than one node
    {
        Tail = Tail->prev;
        delete Tail->next;
        Tail->next = first;
        first->prev = Tail;
    }
    Count--;
}

template <class T>
void DoublyCL<T>::Display()
{
    if (first != NULL && Tail != NULL)
    {
        struct node<T> *temp = first;
        do
        {
            cout << "| " << temp->data << " | <=>";
            temp = temp->next;
        } while (temp != Tail->next);
    }
    cout << endl;
}

template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int ipos)
{
    int size = CountNode();
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *temp = first;
    size++;

    if ((ipos < 1) || (ipos > (size + 1)))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    int size = CountNode();
    int i = 0;
    struct node<T> *temp = first;

    if ((ipos < 1) || (ipos > (size)))
    {
        cout << "Invalid position\n";
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
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}

int main()
{
    DoublyCL<int> iobj;
    DoublyCL<float> fobj;
    DoublyCL<double> dobj;
    DoublyCL<char> cobj;

    iobj.InsertLast(51);
    iobj.InsertLast(21);
    iobj.InsertLast(11);
    iobj.InsertLast(10);
    iobj.InsertLast(9);
    iobj.InsertLast(8);

    cout << "Linked List of Integers:" << endl;
    iobj.Display();
    cout << endl;

    fobj.InsertLast(101.11);
    fobj.InsertLast(111.11);
    fobj.InsertLast(121.11);
    fobj.InsertLast(131.11);
    fobj.InsertLast(141.11);
    fobj.InsertLast(151.11);

    cout << "Linked List of Floats:" << endl;
    fobj.Display();
    cout << endl;

    dobj.InsertLast(101.1111);
    dobj.InsertLast(111.1111);
    dobj.InsertLast(121.1111);
    dobj.InsertLast(131.1111);
    dobj.InsertLast(141.1111);
    dobj.InsertLast(151.1111);

    cout << "Linked List of Doubles:" << endl;
    dobj.Display();
    cout << endl;

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.InsertLast('E');

    cout << "Linked List of Characters:" << endl;
    cobj.Display();
    cout << endl;

    return 0;
}
