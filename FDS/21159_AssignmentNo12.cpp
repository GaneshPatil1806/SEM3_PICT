#include<iostream>
using namespace std;

class item{
    public:
    char name;
    int priority;
    public:
    item(){
        name='0';
        priority=0;
    }
    item(char n , int p)
    {
        name=n;
        priority=p;
    }
    int operator <=(item&obj){
        return this->priority <= obj.priority;

    }
};

class node
{
    item a;
    node* next;
    node*prev;
    public:
    node(){
        prev=NULL;
        next=NULL;
    }
    friend class PQueue;

};

class PQueue
{
    node* front , * rear;
    public:
    PQueue(){
        front=NULL;
        rear=NULL;
    }
    
    void enqueue(item a){
        node* temp=new node;
        if (temp==NULL)
        {
            cout<<"Full"<<endl;
        }
        else
        {
            temp->a=a;
            if (front==NULL)
            {
                front=temp;
                rear=temp;
            }
            
           else if (temp->a<= front->a)
            {
                temp->next=front;
                temp->prev=NULL;
                front->prev=temp;
                front=temp;
            }
            else if (rear->a<= temp->a)
            {
                rear->next=temp;
                temp->next=NULL;
                temp->prev=rear;
                rear=temp;
            }
            else{
                node*temp1= rear;
                while (temp->a <= temp1->a)
                {
                    temp1=temp1->prev;
                }
                temp->next=temp1->next;
                temp1->next->prev=temp;
                temp1->next=temp;
                temp->prev=temp1;
            }    
        }
    }
        void dequeue()
        {
            node*del=front;
            front=front->next;
            delete del;
        }
        void display(){
            node*p=front;
            while (p)
            {
                cout<<"Data - "<<p->a.name<<" priority: "<<p->a.priority<<endl;
                p=p->next;
            }
            
        }
    };

int main()
{
    class item A1('A',6), A2('B',3) , A3('C', 1) , A4('D', 7), A5('E', 2);
    PQueue q;
    q.enqueue(A1);
    q.enqueue(A2);
    q.enqueue(A3);
    q.enqueue(A4);
    q.enqueue(A5);
    q.display();

    return 0;
}