
//  ------------------------------------------PROJECT STANDARD TEMPLATE LIBRARY(STL)---------------------------------------------------


#include<iostream> 
using namespace std;

template <class T>
struct node{
    T data;
    struct node *next;
};


template <class T>
struct Node{
    T data;
    struct Node *next;
    struct Node *prev;
};



template <class T>
class SinglyLL{
    private:
    struct node<T> * first;
    int count;

    public:
    SinglyLL();

    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int countNode();
    void InsertAtPos(T no,int ipos);
    void DeleteAtPos(int ipos);

};




template <class T>
class SinglyCL{
    private:
    struct node<T> * first;
    struct node<T> * last;
    int count;

    public:

    SinglyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void Display();
    int countNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no,int ipos);
    void DeleteAtPos(int ipos);


};


template <class T>
class DoublyLL{
    private:
    struct Node<T> * first;
    int count;
    
    public:

    DoublyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void Display();
    int countNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no,int ipos);
    void DeleteAtPos(int ipos);

};


template <class T>
class DoublyCL{
    private:
    struct Node<T> * first;
    struct Node<T> * last;
    int count;

    public:

    DoublyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void Display();
    int countNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no,int ipos);
    void DeleteAtPos(int ipos);

};



template <class T>
class Stack{
    private:
    struct node<T> * first;

    public:

    Stack();
    void push(T no);
    T Pop();
    void Display();

};



template <class T>
class Queue{
    private:
    struct node<T> * first;

    public:
    Queue();
    void Enqueue(T no);
    int Dequeue();
    void Display();
};


//Singly LL 
//genric

template <class T>
SinglyLL<T> ::SinglyLL(){
    first=NULL;
    count=0;
}


template <class T>
void SinglyLL<T> ::InsertFirst(T no){
    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    if(first==NULL){
        first=newn;
    }
    else{
        newn->next=first;
        first=newn;
    }
    count++;
    
}


template <class T>
void SinglyLL<T> :: InsertLast(T no){
    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    struct node<T> * temp=first;
    newn->data=no;
    newn->next=NULL;
    if(first==NULL){
        first=newn;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newn;
    }
    count++;
}


template <class T>
void SinglyLL<T> :: DeleteFirst(){
    struct node<T> * temp=first;
    if(first==NULL){
        return;
    }
    else if(first->next==NULL){
        delete first;
        first=NULL;
    }
    else{
        first=first->next;
        delete temp;
    }
    count--;
}



template <class T>
void SinglyLL<T> :: DeleteLast(){
    struct node<T> * temp=first;
    if(first==NULL){
        return;
    }
    else if(first->next==NULL){
        delete first;
        first=NULL;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    count--;
}


template <class T>
void SinglyLL<T> :: Display(){
    cout<<"\nElements of linked list are : "<<endl;
    struct node<T> * temp=first;
    while(temp!=NULL){
        cout<<"| "<<temp->data<<" | ->";
        temp=temp->next;
    }
    cout<<" NULL";
}


template <class T>
int SinglyLL<T> :: countNode(){
    return count;
}


template <class T>
void SinglyLL<T> :: InsertAtPos(T no,int ipos){
    struct node<T> * temp=first;
    int i=0;
    if(ipos<1 || ipos >count+1){
        return;
    }
    if(ipos==1){
        InsertFirst(no);
    }
    else if(ipos==count+1){
        InsertLast(no);
    }
    else{
        struct node<T> * newn=NULL;
        newn=new struct node<T>;
        newn->data=no;
        newn->next=NULL;
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    count++;
}



template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos){
    struct node<T> * temp=first;
    struct node<T> * tempValue=NULL;
    int i=0;
    if(ipos<1 || ipos >count){
        return;
    }
    if(ipos==1){
        DeleteFirst();
    }
    else if(ipos==count){
        DeleteLast();
    }
    else{
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        tempValue=temp->next;
        temp->next=temp->next->next;
        delete tempValue;
    }
    count--;
}

//Singly Circular LL 
//genric



template <class T>
SinglyCL<T> :: SinglyCL(){
    first=NULL;
    last=NULL;
    count=0;
}


template <class T>
void SinglyCL<T> ::  InsertFirst(T no){
    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    if((first==NULL) && (last==NULL)){
        first=newn;
        last=newn;
    }
    else{
        newn->next=first;
        first=newn;
    }
    last->next=first;
    count++;
}


template <class T>
void SinglyCL<T> :: InsertLast(T no){
    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    if(first==NULL && last==NULL){
        first=newn;
        last=newn;
    }
    else{
        last->next=newn;
        last=newn;
    }
    last->next=first;
    count++;
}



template <class T>
void SinglyCL<T> :: DeleteFirst(){
    if(first==NULL && last==NULL){
        return;
    }
    else if(first==last){
        delete first;
        first=NULL;
        last=NULL;
    }
    else{
        first=first->next;
        delete last->next;
    }
    last->next=first;
    count--;
}


template <class T>
void SinglyCL<T> :: DeleteLast(){
    struct node<T> * temp=first;
    if(first==NULL && last==NULL){
        return;
    }
    else if(first==last){
        delete first;
        first=NULL;
        last=NULL;
    }
    else{
        while(temp->next!=last){
            temp=temp->next;
        }
        delete temp->next;
        last=temp;
    }
    last->next=first;
    count--;
}

template <class T>
void SinglyCL<T> :: Display(){
    cout<<"\nElements of LL are : "<<endl;
    struct node<T> * temp=first;
    if((first!=NULL) && (last!=NULL)){
        do{
            cout<<"| "<<temp->data<<" | ->";
            temp=temp->next;
        }while(temp!=last->next);
    }
    cout<<"NULL";
}


template <class T>
int SinglyCL<T> :: countNode(){
    return count;
}



template <class T>
void SinglyCL<T> :: InsertAtPos(T no,int ipos){
    struct node<T> * temp=first;
    int i=0;
    if(ipos<1 || ipos >count+1){
        return;
    }
    if(ipos==1){
        InsertFirst(no);
    }
    else if(ipos==count+1){
        InsertLast(no);
    }
    else{
        struct node<T> * newn=NULL;
        newn=new struct node<T>;
        newn->data=no;
        newn->next=NULL;
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    count++;
}



template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos){
    struct node<T> * temp=first;
    struct node<T> * tempValue=NULL;
    int i=0;
    if(ipos<1 || ipos >count){
        return;
    }
    if(ipos==1){
        DeleteFirst();
    }
    else if(ipos==count+1){
        DeleteLast();
    }
    else{
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        tempValue=temp->next;
        temp->next=temp->next->next;
        delete tempValue;
    }
    count--;
}

//Doubly linear LL in cpp
//genric




template <class T>
DoublyLL<T> :: DoublyLL(){
    first=NULL;
    count=0;
}


template <class T>
void DoublyLL<T> :: InsertFirst(T no){
    struct Node<T> * newn=NULL;
    newn=new struct Node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if(first==NULL){
        first=newn;
    }
    else{
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    count++;
}



template <class T>
void DoublyLL<T> :: InsertLast(T no){
    struct Node<T> * newn=NULL;
    newn=new struct Node<T>;
    struct Node<T> * temp=first;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if(first==NULL){
        first=newn;
    }
    else{
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    count++;
}



template <class T>
void DoublyLL<T> :: Display(){
    struct Node<T> * temp=first;
    cout<<"\nElements of linked list are : \n";
    while(temp!=NULL){
        cout<<"| "<<temp->data<<" | "<<" <=> ";
        temp=temp->next;
    }
    cout<<"NULL";

}


template <class T>
int DoublyLL<T> :: countNode()
{
    return count;
}



template <class T>
void DoublyLL<T> :: DeleteFirst(){
    if(first==NULL){
        return;
    }
    else if((first->next==NULL) && (first->prev==NULL)){
        delete first;
        first=NULL;
    }
    else{
        first=first->next;
        delete first->prev;
        first->prev=NULL;
    }
    count--;
}



template <class T>
void DoublyLL<T> :: DeleteLast(){
    struct Node<T> * temp=first;
    if(first==NULL){
        return;
    }
    else if((first->next==NULL) && (first->prev==NULL)){
        delete first;
        first=NULL;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    count--;
}



template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int ipos){
    struct Node<T> * temp=first;
    int i=0;
    if(ipos<1 || ipos>count+1){
        return;
    }
    if(ipos==1){
        InsertFirst(no);
    }
    else if(ipos==count+1){
        InsertLast(no);
    }
    else{
        struct Node<T> * newn=NULL;
        newn=new struct Node<T>;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }
    count++;
}



template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos){
    struct Node<T> * temp=first;
    int i=0;
    if(ipos<1 || ipos>count){
        return;
    }
    if(ipos==1){
        DeleteFirst();
    }
    else if(ipos==count){
        DeleteLast();
    }
    else{
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
    count--;
}


//Doubly Circular LL in cpp
//genric




template <class T>
DoublyCL<T> :: DoublyCL(){
    first=NULL;
    last=NULL;
    count=0;
}


template <class T>
void DoublyCL<T> :: InsertFirst(T no){
    struct Node<T> * newn=NULL;
    newn=new struct Node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if((first==NULL) &&(last==NULL)){
        first=newn;
        last=newn;
    }
    else{
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    last->next=first;
    first->prev=last;
    count++;
}


template <class T>
void DoublyCL<T> :: InsertLast(T no){
    struct Node<T> * newn=NULL;
    newn=new struct Node<T>;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    if((first==NULL) && (last==NULL)){
        first=newn;
        last=newn;
    }
    else{
        last->next=newn;
        newn->prev=last;
        last=newn;
    }
    last->next=first;
    first->prev=last;
    count++;
}



template <class T>
void DoublyCL<T> :: Display(){
    struct Node<T> * temp=first;
    cout<<"\nElements of linked list are : \n";
    if((first!=NULL) && (last!=NULL)){
        do{
        cout<<"| "<<temp->data<<" | <=>";
        temp=temp->next;
        }while(temp!=last->next);
    }    
}
   


template <class T>
int DoublyCL<T> :: countNode(){
     return count;
}


template <class T>
void DoublyCL<T> :: DeleteFirst(){
    if((first==NULL) && (last==NULL)){
        return;
    }
    else if(first==last){
        delete first;
        first=NULL;
        last=NULL;
    }
    else{
        first=first->next;
        delete last->next;
    }
        last->next=first;
        first->prev=last;
        
        count--;
}



template <class T>
void DoublyCL<T> :: DeleteLast(){
    if((first==NULL) && (last==NULL)){
        return;
    }
    else if(first==last){
        delete first;
        first=NULL;
        last=NULL;
    }
    else{
        last=last->prev;    
        delete first->prev;
    }
        last->next=first;
        first->prev=last;
        count--;
}



template <class T>
void DoublyCL<T> :: InsertAtPos(T no,int ipos){
    struct Node<T> * temp=first;
    int i=0;
    if((ipos<1) || (ipos>count+1)){
        return;
    }
    if(ipos==1){
        InsertFirst(no);
    }
    else if(ipos==count+1){
        InsertLast(no);
    }
    else{
        struct Node<T> * newn=NULL;
        newn=new struct Node<T>;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        }
        count++;
}



template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos){
    struct Node<T> * temp=first;
    int i=0;
    if((ipos<1) || (ipos>count)){
        return;
    }
    if(ipos==1){
        DeleteFirst();
    }
    else if(ipos==count){
        DeleteLast();
    }
    else{
        for(i=1;i<ipos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        count--;
    }
}




//Stack 
//genric


template <class T>
Stack<T> :: Stack(){
    first=NULL;
}


template <class T>
void Stack<T> :: push(T no){
    struct node<T> * newn=NULL;
    newn=new struct node<T>;
    newn->data=no;
    newn->next=NULL;
    if(first==NULL){
        first=newn;
    }
    else{
        newn->next=first;
        first=newn;
    }
}


template <class T>
T Stack<T> :: Pop(){
    T iValue;
    struct node<T> * tempvalue=first;
    if(first==NULL){
        cout<<"STACK IS EMPTY..";
    }
    else{
        iValue=first->data;
        first=first->next;
        delete tempvalue;
    }
    return iValue;
}



template <class T>
void Stack<T> ::  Display(){
    struct node<T> * temp=first;
    cout<<"\nElements of stack are : "<<endl;
    while(temp!=NULL){
        cout<<"| "<<temp->data<<" |"<<endl;
        temp=temp->next;
    }
}


//Queue
//genric


template <class T>
Queue<T> :: Queue(){
    first=NULL;
}


template <class T>
void Queue<T> :: Enqueue(T no){
    struct node<T> * temp=first;
    struct node<T> * newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(first==NULL){
        first=newn;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newn;
    }
}



template <class T>
int Queue<T> :: Dequeue(){
    int iValue=0;
    struct node<T> * temp=first;
    if(first==NULL){
        cout<<"QUEUE IS EMPTY..";
    }
    else{
        iValue=first->data;
        first=first->next;
        delete temp;
    }
    return iValue;
}



template <class T>
void Queue<T> :: Display(){
    struct node<T> * temp=first;
    cout<<"Elements of linked list are : \n";
    while(temp!=NULL){
        cout<<"| "<<temp->data<<" |\t";
        temp=temp->next;
    }
}


int main(){

    SinglyLL<int> obj;
    SinglyLL<float> fobj;
    SinglyLL<double> dobj;
    SinglyLL<char> cobj;
    int iRet=0;
    

    //////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\nSingly Linear LL"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    //////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
    cout<<"LinkedList of Integer number : "<<endl;
////////////////////////////////////////////////////


    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    obj.DeleteFirst();
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    obj.DeleteLast();
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    obj.InsertAtPos(105,2);
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    obj.DeleteAtPos(2);
    obj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Floating number : "<<endl;
////////////////////////////////////////////////////



    fobj.InsertFirst(101.99);
    fobj.InsertFirst(51.99);
    fobj.InsertFirst(21.99);
    fobj.InsertFirst(11.99);
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    fobj.InsertLast(121.99);
    fobj.InsertLast(151.99);
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    fobj.DeleteFirst();
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    fobj.DeleteLast();
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    fobj.InsertAtPos(105.99,2);
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    fobj.DeleteAtPos(2);
    fobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of double number : "<<endl;
////////////////////////////////////////////////////



    dobj.InsertFirst(101.9999);
    dobj.InsertFirst(51.9999);
    dobj.InsertFirst(21.9999);
    dobj.InsertFirst(11.9999);
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dobj.InsertLast(121.9999);
    dobj.InsertLast(151.9999);
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dobj.DeleteFirst();
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dobj.DeleteLast();
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dobj.InsertAtPos(105.9999,2);
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dobj.DeleteAtPos(2);
    dobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    

/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Charachter number : "<<endl;
////////////////////////////////////////////////////



    cobj.InsertFirst('D');
    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    cobj.InsertLast('E');
    cobj.InsertLast('F');
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    cobj.DeleteFirst();
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    cobj.DeleteLast();
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    cobj.InsertAtPos('X',2);
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    cobj.DeleteAtPos(2);
    cobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    

     ////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\nSingly Circular LL"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    /////////////////////////////////////////////////////////////////////////////////////

    SinglyCL<int> scobj;
    SinglyCL<float> scfobj;
    SinglyCL<double> scdobj;
    SinglyCL<char> sccobj;

/////////////////////////////////////////////////////
    cout<<"LinkedList of Integer number : "<<endl;
////////////////////////////////////////////////////


    scobj.InsertFirst(101);
    scobj.InsertFirst(51);
    scobj.InsertFirst(21);
    scobj.InsertFirst(11);
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scobj.InsertLast(121);
    scobj.InsertLast(151);
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scobj.DeleteFirst();
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    scobj.DeleteLast();
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scobj.InsertAtPos(105,2);
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    scobj.DeleteAtPos(2);
    scobj.Display();
    iRet=scobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Floating number : "<<endl;
////////////////////////////////////////////////////



    scfobj.InsertFirst(101.99);
    scfobj.InsertFirst(51.99);
    scfobj.InsertFirst(21.99);
    scfobj.InsertFirst(11.99);
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scfobj.InsertLast(121.99);
    scfobj.InsertLast(151.99);
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scfobj.DeleteFirst();
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    scfobj.DeleteLast();
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scfobj.InsertAtPos(105.99,2);
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    scfobj.DeleteAtPos(2);
    scfobj.Display();
    iRet=scfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of double number : "<<endl;
////////////////////////////////////////////////////



    scdobj.InsertFirst(101.9999);
    scdobj.InsertFirst(51.9999);
    scdobj.InsertFirst(21.9999);
    scdobj.InsertFirst(11.9999);
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scdobj.InsertLast(121.9999);
    scdobj.InsertLast(151.9999);
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scdobj.DeleteFirst();
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    scdobj.DeleteLast();
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    scdobj.InsertAtPos(105.9999,2);
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    scdobj.DeleteAtPos(2);
    scdobj.Display();
    iRet=scdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    

/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Charachter number : "<<endl;
////////////////////////////////////////////////////



    sccobj.InsertFirst('D');
    sccobj.InsertFirst('C');
    sccobj.InsertFirst('B');
    sccobj.InsertFirst('A');
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    sccobj.InsertLast('E');
    sccobj.InsertLast('F');
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    sccobj.DeleteFirst();
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    sccobj.DeleteLast();
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    sccobj.InsertAtPos('X',2);
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    sccobj.DeleteAtPos(2);
    sccobj.Display();
    iRet=sccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;


    //////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\nDoubly linear LL"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    /////////////////////////////////////////////////////////////////////////////////////
    

    DoublyLL<int> dlobj;
    DoublyLL<float> dlfobj;
    DoublyLL<double> dldobj;
    DoublyLL<char> dlcobj;

/////////////////////////////////////////////////////
    cout<<"LinkedList of Integer number : "<<endl;
////////////////////////////////////////////////////


    dlobj.InsertFirst(101);
    dlobj.InsertFirst(51);
    dlobj.InsertFirst(21);
    dlobj.InsertFirst(11);
    dlobj.Display();
    iRet=dlobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dlobj.InsertLast(121);
    dlobj.InsertLast(151);
    dlobj.Display();
    iRet=dlobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dlobj.DeleteFirst();
    dlobj.Display();
    iRet=dlobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dlobj.DeleteLast();
    obj.Display();
    iRet=dlobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dlobj.InsertAtPos(105,2);
    dlobj.Display();
    iRet=dlobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dlobj.DeleteAtPos(2);
    dlobj.Display();
    iRet=obj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Floating number : "<<endl;
////////////////////////////////////////////////////



dlfobj.InsertFirst(101.99);
    dlfobj.InsertFirst(51.99);
    dlfobj.InsertFirst(21.99);
    dlfobj.InsertFirst(11.99);
    dlfobj.Display();
    iRet=fobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


dlfobj.InsertLast(121.99);
    dlfobj.InsertLast(151.99);
    dlfobj.Display();
    iRet=dlfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dlfobj.DeleteFirst();
    dlfobj.Display();
    iRet=dlfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dlfobj.DeleteLast();
    dlfobj.Display();
    iRet=dlfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dlfobj.InsertAtPos(105.99,2);
    dlfobj.Display();
    iRet=dlfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dlfobj.DeleteAtPos(2);
    dlfobj.Display();
    iRet=dlfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of double number : "<<endl;
////////////////////////////////////////////////////



    dldobj.InsertFirst(101.9999);
    dldobj.InsertFirst(51.9999);
    dldobj.InsertFirst(21.9999);
    dobj.InsertFirst(11.9999);
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dldobj.InsertLast(121.9999);
    dldobj.InsertLast(151.9999);
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dldobj.DeleteFirst();
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dldobj.DeleteLast();
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dldobj.InsertAtPos(105.9999,2);
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dldobj.DeleteAtPos(2);
    dldobj.Display();
    iRet=dldobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    

/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Charachter number : "<<endl;
////////////////////////////////////////////////////




    dlcobj.InsertFirst('D');
    dlcobj.InsertFirst('C');
    dlcobj.InsertFirst('B');
    dlcobj.InsertFirst('A');
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dlcobj.InsertLast('E');
    dlcobj.InsertLast('F');
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dlcobj.DeleteFirst();
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    

    dlcobj.DeleteLast();
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dlcobj.InsertAtPos('X',2);
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    



    dlcobj.DeleteAtPos(2);
    dlcobj.Display();
    iRet=dlcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    
    ////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\nDoubly Circular LL"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    ///////////////////////////////////////////////////////////////////////////////////

    DoublyCL<int> dcobj;
    DoublyCL<float> dcfobj;
    DoublyCL<double> dcdobj;
    DoublyCL<char> dccobj;


/////////////////////////////////////////////////////
    cout<<"LinkedList of Integer number : "<<endl;
////////////////////////////////////////////////////


    dcobj.InsertFirst(101);
    dcobj.InsertFirst(51);
    dcobj.InsertFirst(21);
    dcobj.InsertFirst(11);
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcobj.InsertLast(121);
    dcobj.InsertLast(151);
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcobj.DeleteFirst();
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dcobj.DeleteLast();
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcobj.InsertAtPos(105,2);
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dcobj.DeleteAtPos(2);
    dcobj.Display();
    iRet=dcobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Floating number : "<<endl;
////////////////////////////////////////////////////



    dcfobj.InsertFirst(101.99);
    dcfobj.InsertFirst(51.99);
    dcfobj.InsertFirst(21.99);
    dcfobj.InsertFirst(11.99);
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcfobj.InsertLast(121.99);
    dcfobj.InsertLast(151.99);
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcfobj.DeleteFirst();
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dcfobj.DeleteLast();
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcfobj.InsertAtPos(105.99,2);
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dcfobj.DeleteAtPos(2);
    dcfobj.Display();
    iRet=dcfobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


/////////////////////////////////////////////////////
    cout<<"\nLinkedList of double number : "<<endl;
////////////////////////////////////////////////////



    dcdobj.InsertFirst(101.9999);
    dcdobj.InsertFirst(51.9999);
    dcdobj.InsertFirst(21.9999);
    dcdobj.InsertFirst(11.9999);
    dcdobj.Display();
    iRet=dcdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcdobj.InsertLast(121.9999);
    dcdobj.InsertLast(151.9999);
    dcdobj.Display();
    iRet=dcdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcdobj.DeleteFirst();
    dcdobj.Display();
    iRet=dcdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    

    dcdobj.DeleteLast();
    dcdobj.Display();
    iRet=dcdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    dcdobj.InsertAtPos(105.9999,2);
    dcdobj.Display();
    iRet=dcdobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    


    dcdobj.DeleteAtPos(2);
    dcdobj.Display();
    iRet=dobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    

/////////////////////////////////////////////////////
    cout<<"\nLinkedList of Charachter number : "<<endl;
////////////////////////////////////////////////////




    dccobj.InsertFirst('D');
    dccobj.InsertFirst('C');
    dccobj.InsertFirst('B');
    dccobj.InsertFirst('A');
    dccobj.Display();
    iRet=dccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dccobj.InsertLast('E');
    dccobj.InsertLast('F');
    dccobj.Display();
    iRet=dccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dccobj.DeleteFirst();
    dccobj.Display();
    iRet=dccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    


    

    dccobj.DeleteLast();
    dccobj.Display();
    iRet=dccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    




    dccobj.InsertAtPos('X',2);
    dccobj.Display();
    iRet=cobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    
    



    dccobj.DeleteAtPos(2);
    dccobj.Display();
    iRet=dccobj.countNode();
    cout<<"\nNumber of nodes in the LL are : "<<iRet;
    



     //////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\n----------------STACK-------------------"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    /////////////////////////////////////////////////////////////////////////////////////
  

    Stack<int> sobj;
    Stack<float> sfobj;
    Stack<double> sdobj;
    Stack<char> sc1obj;
    int siRet=0;
    float sfRet=0.0f;
    double sdRet=0.0;
    char scRet='\0';

    cout<<"\nStack for Integer...."<<endl;
    sobj.push(101);
    sobj.push(51);
    sobj.push(21);
    sobj.push(11);
    sobj.Display();

    siRet=sobj.Pop();
    cout<<"poped element is : "<<siRet<<endl;
    siRet=sobj.Pop();
    cout<<"poped element is : "<<siRet<<endl;
    iRet=sobj.Pop();
    cout<<"poped element is : "<<siRet<<endl;
    siRet=sobj.Pop();
    cout<<"poped element is : "<<siRet<<endl;
   


    cout<<"\nStack for float...."<<endl;
    sfobj.push(101.99);
    sfobj.push(51.99);
    sfobj.push(21.99);
    sfobj.push(11.99);
    sfobj.Display();

    sfRet=sfobj.Pop();
    cout<<"poped element is : "<<sfRet<<endl;
    sfRet=sfobj.Pop();
    cout<<"poped element is : "<<sfRet<<endl;
    sfRet=sfobj.Pop();
    cout<<"poped element is : "<<sfRet<<endl;
    sfRet=sfobj.Pop();
    cout<<"poped element is : "<<sfRet<<endl;
    




    cout<<"\nStack for doubble...."<<endl;
    sdobj.push(101.9999);
    sdobj.push(51.9999);
    sdobj.push(21.9999);
    sdobj.push(11.9999);
    sdobj.Display();

    sdRet=sdobj.Pop();
    cout<<"poped element is : "<<sdRet<<endl;
    sdRet=sdobj.Pop();
    cout<<"poped element is : "<<sdRet<<endl;
    sdRet=sdobj.Pop();
    cout<<"poped element is : "<<sdRet<<endl;
    sdRet=sdobj.Pop();
    cout<<"poped element is : "<<sdRet<<endl;
    




    cout<<"\nStack for Charachter...."<<endl;
    sc1obj.push('D');
    sc1obj.push('C');
    sc1obj.push('B');
    sc1obj.push('A');
    sc1obj.Display();

    scRet=sc1obj.Pop();
    cout<<"poped element is : "<<scRet<<endl;
    scRet=sc1obj.Pop();
    cout<<"poped element is : "<<scRet<<endl;
    scRet=sc1obj.Pop();
    cout<<"poped element is : "<<scRet<<endl;
    scRet=sc1obj.Pop();
    cout<<"poped element is : "<<scRet<<endl;
    



       //////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    cout<<"\n----------------QUEUE-------------------"<<endl;
    cout<<"\n----------------------------------------------------------------------------------"<<endl;
    ////////////////////////////////////////////////////////////////////////////////////////


    Queue<int> qobj;
    Queue<float> qfobj;
    Queue<double> qdobj;
    Queue<char> qcobj;
    int qiRet=0;
    float qfRet=0.0f;
    double qdRet=0.0;
    char qcRet='\0';


    cout<<"\nQUEUE for integer : \n";
    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);
    qobj.Enqueue(111);
    qobj.Display();

    qiRet = qobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qiRet<<endl;
    qiRet = qobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qiRet<<endl;
    qiRet = qobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qiRet<<endl;
    qiRet = qobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qiRet<<endl;



    cout<<"\nQUEUE for float : \n";
    qfobj.Enqueue(11.99);
    qfobj.Enqueue(21.99);
    qfobj.Enqueue(51.99);
    qfobj.Enqueue(101.99);
    qfobj.Enqueue(111.99);
    qfobj.Display();

    qfRet = qfobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qfRet<<endl;
    qfRet = qfobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qfRet<<endl;
    qfRet = qfobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qfRet<<endl;
    qfRet = qfobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qfRet<<endl;



    cout<<"\nQUEUE for doubble : \n";
    qdobj.Enqueue(11.9999);
    qdobj.Enqueue(21.9999);
    qdobj.Enqueue(51.9999);
    qdobj.Enqueue(101.9999);
    qdobj.Enqueue(111.9999);
    qdobj.Display();

    qdRet = qdobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qdRet<<endl;
    qdRet = qdobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qdRet<<endl;
    qdRet = qdobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qdRet<<endl;
    qdRet = qdobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qdRet<<endl;


    cout<<"\nQUEUE for charachter : \n";
    qcobj.Enqueue('A');
    qcobj.Enqueue('B');
    qcobj.Enqueue('C');
    qcobj.Enqueue('D');
    qcobj.Enqueue('E');
    qcobj.Display();

    qcRet = qcobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qcRet<<endl;
    qcRet = qcobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qcRet<<endl;
    qcRet = qcobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qcRet<<endl;
    qcRet = qcobj.Dequeue();
    cout<<"\nRemoved element from queue is : "<<qcRet<<endl;


    







    return 0;
}
