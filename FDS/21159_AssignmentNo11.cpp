#include<iostream> 
using namespace std;
class queue
{
    int*a;
    int front;
    int rear;
    int size;
    public:
    queue(int n)
    {
        a= new int[n];
        front=-1;
        rear=-1;
        size=n;
    }
    void insert(int x);
    int remove();
    int isfull();
    int isempty();
    void display();
};
void queue::insert(int x)
{
    if (rear==size-1)
    {
        cout<<"Queue is Full"<<endl;
    }
    else
    {
        rear++;
        a[rear]=x;
    }
}

int queue::remove()
{
    if (rear==front)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        front++;
        return a[front];
    }
    
}
int queue::isfull(){
    if (rear==size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int queue::isempty(){
    if (rear==front)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
void queue::display(){
    cout<<"Queue: ";
    for (int i = front+1; i <=rear; i++)
    {
        cout<<a[i]<<" ";
    
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter the size of queue: ";
    int n;
    cin>>n;
    queue Q(n);
    int choice;
    while (true)
    {
        cout<<"Enter 1 for insert"<<endl;
        cout<<"Enter 2 for delete"<<endl;
        cout<<"Enter 3 for is empty"<<endl;
        cout<<"Enter 4 for is full"<<endl;
        cout<<"Enter 5 for display"<<endl;
        cout<<"Enter 6 for exit"<<endl;
        cin>>choice;
        if (choice==1)
        {
            int n;
            cout<<"Enter the element to be inserted: ";
            cin>>n;
            Q.insert(n);
        }
        else if (choice==2)
        {
            int x=Q.remove();
            cout<<x<<" is removed"<<endl;
        }
        else if (choice==3)
        {
            int x=Q.isempty();
            if (x==1)
            {
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<"Queue is not empty"<<endl;
            }
        }
        else if (choice==4)
        {
            bool x=Q.isfull();
            if (x==1)
            {
                cout<<"Queue is full"<<endl;
            }
            else{
                cout<<"Queue is not full"<<endl;
            }
        }
        else if (choice==5)
        {
            Q.display();
        }
        else {
            cout<<"Exiting the program"<<endl;
            break;
        }
    }
    
    return 0;
}
