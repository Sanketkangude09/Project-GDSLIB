#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node *prev;

};
template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:

        DoublyLL(); 
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);

};
template <class T>
DoublyLL<T>::DoublyLL()
{
    
    first = NULL;
    Count = 0;
}
template <class T>
void DoublyLL<T> ::InsertFirst( T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // #

    if(first == NULL)   // LL is empty
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;       // #
        first = newn;
    }
    Count++;
}
template <class T>
void DoublyLL<T>:: InsertLast( T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = first;

    newn =new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // #

    if(first == NULL)   // LL is empty
    {
        first = newn;
    }
    else
    {
        // type 2
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // #
    }
    Count++;
}
template <class T>
void DoublyLL <T>:: DeleteFirst()
{
    if(first == NULL)   // empty LL
    {
        return;
    }
    else if(((first) -> next == NULL) && ((first) -> prev == NULL)) // Single node
    {                                                               // #    
        delete(first);
        first= NULL;
    }
    else
    {
        first = first -> next;
        free((first)->prev);
        first->prev = NULL;
    }
    Count--;
}
template <class T>
void  DoublyLL<T> ::DeleteLast()
{
    
    if(first == NULL)   // empty LL
    {
        return;
    }
    else if(((first) -> next == NULL) && ((first) -> prev == NULL)) // Single node
    {                                                               // #    
        delete(first);
        first = NULL;
    }
    else
    {
        struct node <T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    Count--;
}
template <class T>
void DoublyLL<T>:: Display()
{   
    struct node<T> *temp = first;
    cout<<"Contents of LinkedList are : \n";

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
		cout<<"| "<<temp->data<<"|=>";
		temp = temp -> next;
    }
    cout<<"NULL\n";
}
template <class T>
int  DoublyLL<T> ::CountNode()
{
    return Count;
}
template <class T>
void  DoublyLL<T>::DeleteAtPos( int ipos)
{
    T size = 0, i = 0;
    size = CountNode();
    struct node< T>*temp = first;

    if((ipos < 1) || (ipos > (size)))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {   
        DeleteLast();
    }
    else
    {
        for(i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);     // #
        temp->next->prev = temp;    // #

        Count--;
    }
}
template <class T>
void  DoublyLL<T>::InsertAtPos( T no,int ipos)
{
    int size = 0, i = 0;
    size = CountNode();
    struct node<T>* newn = NULL;
    struct node<T> *temp= first;

    if((ipos < 1) || (ipos > (size+1)))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size+1)
    {   
        InsertLast( no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // #

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;        // #
        temp->next = newn;
        newn->prev = temp;      // #
    }
}

int main()
{
    DoublyLL <int>iobj;
    DoublyLL <float>fobj;
    DoublyLL <double>dobj;
    DoublyLL <char>cobj;



    
    int iRet = 0;

   iobj. InsertLast(51);
   iobj. InsertLast(21);
   iobj. InsertLast(11);
   iobj. InsertLast(10);
   iobj. InsertLast(9);
   iobj. InsertLast(8);
   
  
   
   cout<<"lINKED LIST OF INTEGERS:"<<endl;
   iobj. Display();
   cout<<endl;
   


    fobj.InsertLast(101.11);
    fobj.InsertLast(111.11);
    fobj.InsertLast(121.11);
    fobj.InsertLast(131.11);
    fobj.InsertLast(141.11);
    fobj.InsertLast(151.11);


    cout<<"Linked list of floats:"<<endl;
     fobj. Display();
     cout<<endl;

    dobj.InsertLast(101.1111);
    dobj.InsertLast(111.1111);
    dobj.InsertLast(121.1111);
    dobj.InsertLast(131.1111);
    dobj.InsertLast(141.1111);
    dobj.InsertLast(151.1111);


    cout<<"Linked list of Doubles:"<<endl;
    dobj. Display();
    cout<<endl;


    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.InsertLast('E');


    cout<<"Linked list of charcter:"<<endl;
    cobj. Display();
    cout<<endl;


  
   
    

    return 0;
}