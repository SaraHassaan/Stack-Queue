#include <iostream>
#include<stdlib.h>
using namespace std;

template<class T>
class Structure //its the base class(parent)
{
protected:
    int top,len;
    T*data;
public:
    Structure() //default constructor of classes that inherit that class make call to this constructor
    {
        top=-1;
    }
    ~Structure()
    {
        delete(data);
    }
    void allocate_structure(int len)
    {
        this->len=len; //len of new instance = len that is passed to this function
        data=new T[len]; //pointer data point to memory contain len elements each element its size=size of(int)
    }
    T pop()
    {
        if(top>-1)
        {
            return data[top--];
        }
        else
        {
            throw 0;
        }
    }
    void show_data()
    {
        if(top>-1)
        {
            cout<<"the data are recorded\n";
            for(int i=top ; i>=0 ; i--)
            {
               cout<<data[i]<<endl;
            }
        }
        else
        {
            throw 1;
        }

    }
    //if you will do abstract method you can not make object from this class
    //and you will use polymorphism ...ex.>Structure *ptr;
    //ptr=new Stack()..ptr its type is Structure but it point to Stack(object of stack)
    virtual void push()=0;//we make that to allow using push method that is exist in stack class

};
/*note:using template class make some problem about which things that inherited
so i make this->top , this->data , this->len to tell compiler these variables inherited
from class structure*/
template<class T>
class Stack:public Structure<T> //this class inherit parent class
{
public:
    void push()
    {
        if((this->top) < (this->len-1))//that mean stack is not completely full,still has empty places
        {
            T record;
            cout<<"Enter the data: ";
            cin>>record;
            this->data[++this->top]=record;
        }
        else
        {
            cout<<"the stack is full\n";
        }

    }

};

template<class T>
class Queue:public Structure<T> // Queue class inherit structure class
{
public:
    void push()
    {
        if(this->top<this->len-1)//that mean queue is not completely full,still has empty places
        {
            this->top++;
            for(int i =this->top ; i>0; i--)//it makes shift to make top point to the first element enter the queue
            {
                this->data[i]=this->data[i-1];
            }
            T record;
            cout<<"Enter the data: ";
            cin>>record;
            this->data[0]=record;
        }

        else
        {
            cout<<"the queue is full\n";
        }

    }


};



int main()
{
    int len;
    int choice;
    cout<<"Enter the size of structure: ";
    cin>>len;
    Structure<int>*ptr;//replace each T in the class with int
    ptr=new Queue<int>;//if you want to use stack just change the word "Queue" into "Stack"
    ptr->allocate_structure(len);
    while(1)
    {
        cout<<"_____________________________\n";
        cout<<"1:push 2:pop 3:ShowData 4:Exit\n";
        cout<<"choose an action: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                ptr->push();
                break;
            case 2:
                try
                {
                  cout<<"data="<<ptr->pop()<<endl;
                }
                catch(int e)
                {
                    cout<<"structure is empty\n";
                }
                break;
            case 3:
                try
                {
                    ptr->show_data();
                }
                catch(int e)
                {
                    cout<<"no data \n";
                }
                break;
            case 4:
                exit(0); //to finish the program
                break;
            default:
                cout<<"incorrect choice\n";
                break;
        }
    }


    return 0;

}
