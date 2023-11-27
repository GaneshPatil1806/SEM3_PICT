#include<iostream>
using namespace std;

class node
{
    char data;
    node *next;
    int value;

public:

    node()
    {
        next=NULL;
        data='0';
        value=0;
    }
    friend class stack;
};

class stack
{
    node *top;
    string postfix="";
public:

    stack()
    {
        top=NULL;
    }
    
    bool isEmpty();
    void push(char);
    void push1(int);
    char pop();
    int pop1();
    string infixtopostfix(string s);
    int precedence(char);
    bool isoperator(char);
    char gettop();
    int evaluate(string s);
};

bool stack :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

void stack :: push(char x)
{
    node *p = new node;
    p->data=x;

    if(isEmpty())
        top=p;
    else
    {
        p->next=top;
        top=p;
    }
}

char stack :: pop()
{
    node *p=top;
    char x = p->data;

    if(isEmpty())
        cout<<"\nUnderflow";
    else
    {
        top=top->next;
        p->next=NULL;
        delete p;
    }
    return x;
}

void stack :: push1(int x)
{
    node *p = new node;
    p->value=x;

    if(isEmpty())
        top=p;
    else
    {
        p->next=top;
        top=p;
    }
}

int stack :: pop1()
{
    node *p=top;
    char x = p->value;

    if(isEmpty())
        cout<<"\nUnderflow";
    else
    {
        top=top->next;
        p->next=NULL;
        delete p;
    }
    return x;
}

char stack ::gettop()
{
    return top->data;
}

bool stack :: isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' )
        return 1;
    else
        return 0;
}

int stack :: precedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
     else if(c=='^')
        return 3;
    else
        return -1;
}

string stack :: infixtopostfix(string s)
{
    stack st1;

    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
            postfix+=s[i];

        else if(s[i]=='(')
            st1.push(s[i]);
        
        else if(s[i]==')')
        {
            while(!st1.isEmpty() && st1.gettop()!='(')
                postfix+=st1.pop();
            
            if(st1.gettop()=='(')
                st1.pop();
        }

        else if(st1.isoperator(s[i]))
        {
            if(st1.isEmpty() || st1.gettop()=='(')
                st1.push(s[i]);

            else if(st1.precedence(s[i])>st1.precedence(st1.gettop()))
                st1.push(s[i]);
            
            else
            {
                while((!st1.isEmpty()) && (st1.precedence(s[i])<=st1.precedence(st1.gettop())))
                    postfix+=st1.pop();
                
                st1.push(s[i]);
            }
            
        }
    }

    while(!st1.isEmpty())
        postfix+=st1.pop();
  
    return postfix;
}

int stack :: evaluate(string s)
{
    stack st;
    int val;
    int a,b;
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            cout<<"\nEnter the value of "<<s[i]<<" ";
            cin>>val;
            st.push1(val);
        }
        else if(st.isoperator(s[i]))
        {
            a=st.pop1();
            b=st.pop1();

            if(s[i]=='+')
                st.push1(a+b);
            else if(s[i]=='-')
                st.push1(b-a);
            else if(s[i]=='*')
                st.push1(a*b);
            else if(s[i]=='/')
                st.push1(b/a);
        }
    }

    int result=st.pop1();
    return result;
}

int main()
{
    string s,p;
    stack st;
    cout<<"\nEnter the expression to be checked\n";
    cin>>s;
    p=st.infixtopostfix(s); 
    cout<<"\nPostfix "<<p;

    int m=st.evaluate(p);
    cout<<"\nResult "<<m;

    return 0;
}