#include<iostream>
#include<string>
using namespace std;

class node
{
    char data;
    node *next;

public:
    node()
    {
        data='0';
        next=NULL;
    }
    friend class stack;
};

class stack
{
    node *Top;

public:
    stack()
    {
       Top=NULL;
    }
    void push(char x);
    char pop();
    bool isEmpty();
    bool isFull();
    void display();
    char gettop();
};

bool stack :: isEmpty()
{
    if(Top==NULL)
        return 1;
    else
        return 0;
}

bool stack :: isFull()
{
    node *t= new node;

    if(t==NULL)
        return 1;
    else
        return 0;
}

char stack :: pop()
{
    node *t=Top;
    char p=t->data;
    if(isEmpty())
    {
        cout<<"Underflow";
    }
    else
    {
        Top=t->next;
        t->next=NULL;
        delete t;
    }
    return p;
}

void stack :: push(char x)
{
    node *t= new node;
    t->data=x;

    if(isEmpty())
    {
        Top=t;
    }
    else
    {
        t->next=Top;
        Top=t;
    }
}

char stack :: gettop()
{
   return Top->data;
}

void stack :: display()
{
    node *p=Top;
    cout<<"\n==============================\n";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n==============================\n";
}

bool checkParenthesis(string s)
{
    node *t;
    stack st1;
    int flag=0;
    for(int i=0;i<s.length();i++)
    {

        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            st1.push(s[i]);

        else if(s[i]==')' || s[i]==']' || s[i]=='}')
        {
            if(s[i]==')')
            {
                if(!st1.isEmpty())
                {
                    if(st1.gettop()=='(')
                        st1.pop();
                    else
                    {
                        cout<<"\nMatching opening brace '(' not found \n";
                        flag=1;
                    }
                }
                else
                {
                    cout<<"\nStack is empty";
                    flag=1;
                }
            }
            if(s[i]==']')
            {
                if(!st1.isEmpty())
                {
                    if(st1.gettop()=='[')
                        st1.pop();
                    else
                    {
                        cout<<"\nMatching opening brace '[' not found \n";
                        flag=1;
                    }
                }
                else
                {
                    cout<<"\nStack is empty";
                    flag=1;
                }
            }
            if(s[i]=='}')
            {
                if(!st1.isEmpty())
                {
                    if(st1.gettop()=='{')
                        st1.pop();
                    else
                    {
                        cout<<"\nMatching opening brace '{' not found \n";
                        flag=1;
                    }
                }
                else
                {
                    cout<<"\nStack is empty\n";
                    flag=1;
                }
            }
        }
    }

    if(st1.isEmpty() && flag==0)
        return 1;
    else
        return 0;
    
}

int main()
{
    stack st;
    string s;

    cout<<"\nEnter the expression you want to check\n";
    cin>>s;
    
    bool r = checkParenthesis(s);
    
    if(r)
        cout<<"\nExpression is well parenthesized\n";
    else
        cout<<"\nExpression is not well parenthesized\n";

    return 0;
}
