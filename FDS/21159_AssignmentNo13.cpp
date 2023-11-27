#include<iostream>
using namespace std;
class node{
    int data;
    node*next;
    public:
    node()
    {
        data=0;
        next=NULL;
    } 
    friend class Dqueue;
};
class Dqueue
{
    node*front,*rear;
    public:
    Dqueue(){
        front=rear=NULL;
    }
    void enqueue_front(int x)
    {
        if (front==NULL)
        {
            front=new node;
            rear=front;
            front->data=x;
        }
        else{
            node*t=new node;
            t->next=front;
            front=t;
            t->data=x;
        }
    }
    void enqueue_rear(int x){
        if (front==NULL)
        {
            front=new node;
            rear=front;
            front->data=x;
        }
        else{
            node*t=new node;
            t->next=NULL;
            rear->next=t;
            t->data=x;
            rear=t;
        }
    }
    int dqueue_front(){
        if (front==NULL)
        {
            //cout<<"Empty Queue"<<endl;
            return -1;
        }
        else{
            node*y=front;
            front=front->next;
            int x=y->data;
            delete y;

            return x;
        } 
    }
    int dqueue_rear()
    {
        if (front==NULL)
        {
            //cout<<"Empty Queue"<<endl;
            return -1;
        }
        else{

            node*y=front;
            node*z=NULL;
            while (y->next!=NULL)
            {
                z=y;
                y=y->next;
            }
            int x=y->data;
            z->next=NULL;
            rear=z;
            delete y;

            return x;
        }
    }
    void display(){
        node*p=front;
        while (p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

};
int main()
{
    int n;
    Dqueue q;
    while (true)
    {
        cout<<"Enter 1 for insert at front"<<endl;
        cout<<"Enter 2 for insert at rear"<<endl;
        cout<<"Enter 3 for delete at first"<<endl;
        cout<<"Enter 4 for delete at rear"<<endl;
        cout<<"Enter 5 for display"<<endl;
        cout<<"Enter 6 for exit"<<endl;
        cin>>n;
        if (n==1)
        {
            int x;
            cout<<"Enter element to be inserted at front: ";
            cin>>x;
            q.enqueue_front(x);
        }
        else if (n==2)
        {
            int x;
            cout<<"Enter element to be inserted at rear: ";
            cin>>x;
            q.enqueue_rear(x);
        }
        else if (n==3)
        {
            int c=q.dqueue_front();
            if (c==-1)
            {
                cout<<"underflow"<<endl;
            }
            else{
                cout<<c<<" delted"<<endl;
            }
        }
        else if (n==4)
        {
            int c=q.dqueue_rear();
            if (c==-1)
            {
                cout<<"underflow"<<endl;
            }
            else{
                cout<<c<<" delted"<<endl;
            }
            
        }
        else if (n==5)
        {
            cout<<"Queue: ";
            q.display();
        }
        else{
            cout<<"Exiting program..."<<endl;
            break;
        }
        
        
    }
    
    
    return 0;
}