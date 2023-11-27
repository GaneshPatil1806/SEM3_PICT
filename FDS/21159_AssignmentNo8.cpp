#include <iostream>
using namespace std;

class node
{
    string name;
    string flavour;
    node *next;

public:
    node()
    {
        next = NULL;
    }

    friend class icecream;
};

class icecream
{

public:

    int count(node *&s)
    {
        int cnt = 0;
        node *temp = s;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void insertatend(node *&s, string i,string m)
    {
        node *n = new node;
        node *t = s;
        n->name = i;
        n->flavour=m;

        if (s == NULL)
        {
            s = n;
        }
        else
        {
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

    void insertatfirst(node *&s)
    {
        node *n = new node;
        node *t=s;
        string x;
        cout << "\nEnter the name of the student you want to insert: ";
        cin >> x;

        n->name = x;
    
        if(s==NULL)
        {
            s=n;
        }
        else
        {
            n->next=s;
            s=n;
        }
    }

    void createclass(node *&s)
    {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            insertatfirst(s);
        }
    }

    void insertatend1(node *&s, string fla)
    {
        node *n = new node;
        node *t = s;
        string x;

        cout << "\nEnter the name of the student you want to insert: ";
        cin >> x;

        n->name = x;
        n->flavour = fla;

        if (s == NULL)
        {
            s = n;
        }
        else
        {
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = n;
        }
    }

    void creategrp(node *&s, string m)
    {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            insertatend1(s, m);
        }
    }

    node *Both(node *&s1, node *&s2)
    {
        node *temp1 = s1;
        node *temp2 = s2;
        node *ans = NULL;
        while (temp1 != NULL)
        {
            temp2 = s2;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    insertatend(ans, temp1->name,temp1->flavour);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
    }

    node *A_but_not_b(node *&s1, node *&s2)
    {
        node *temp1 = s1;
        node *temp2 = s2;
        node *ans = NULL;
        
        while (temp1 != NULL)
        {
            int flag = 1;
            temp2=s2;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    flag = 0;
                    break;
                }
                temp2 = temp2->next;
            }
            if (flag==1)
            {
                insertatend(ans, temp1->name,temp1->flavour);
            }
            temp1 = temp1->next;
        }
        return ans;
    }

    void printdata(node *&s)
    {
        node *t = s;
        while (t != NULL)
        {
            cout << t->name << " ";
            t = t->next;
        }
    }

};

int main()
{
    int ch;
    icecream a,b,c;

    node *s=NULL;
    node *s1 = NULL;
    node *s2 = NULL;

    while (true)
    {
        cout<<"\n==================================================\n";
        cout<<"Universal: ";
        b.printdata(s);
        cout<<"\n==================================================\n";
        cout<<"Vanilla: ";
        b.printdata(s1);
        cout<<"\n==================================================\n";
        cout<<"Butterscotch: ";
        b.printdata(s2);
         cout<<"\n==================================================\n";

        cout << "1.Create the set of number of students SE Comp class " << endl;
        cout << "2.Create a set who like vanilla " << endl;
        cout << "3.Create a set who like butterscoch " << endl;
        cout << "4.Student who like both vanilla and butterscotch: " << endl;
        cout << "5.Set of students who like either vanilla or butterscotch or not both: " << endl;
        cout << "6.Number of students who like neither vanilla nor butterscotch: " << endl;
        cout << "7.Exit" << endl;
        cout << "Enter choice : " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "Data of students in SE class : " << endl;
            a.createclass(s);
            cout<<"\n==================================================\n";
            a.printdata(s);
            cout<<"\n==================================================\n";
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Data of students who likes vanilla : " << endl;
            a.creategrp(s1, "v");
            cout<<"\n==================================================\n";
            a.printdata(s1);
            cout<<"\n==================================================\n";
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            cout<< "Data of students who likes butterscotch: " << endl;
            b.creategrp(s2, "b");
            cout<<"\n==================================================\n";
            b.printdata(s2);
            cout<<"\n==================================================\n";
            break;
        }
        case 4:
        {

            cout << "student who like both vanilla and butterscotch : " << endl;
            node *ans1 = b.Both(s1, s2);
            cout<<"\n==================================================\n";
            b.printdata(ans1);
            cout<<"\n==================================================\n";
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "\nSet of students who like either vanilla or butterscotch but not both : " << endl;
            node *ans1 = b.Both(s1,s2);
            node *ans2 = b.A_but_not_b(s1, ans1);
            node *ans3 = b.A_but_not_b(s2, ans1);
            cout<<"\n==================================================\n";
            b.printdata(ans2);
            cout<<" ";
            c.printdata(ans3);
            cout<<"\n==================================================\n";
        }
        case 6:
        {
            cout<<"\n==================================================\n";
            cout << "Number of students who like neither vanilla nor butterscotch: ";
            cout<<"\n==================================================\n";
            node *ans6 = a.A_but_not_b(s,s1);
            node *ans7 = b.A_but_not_b(ans6, s2);
            int k = a.count(ans7);
            cout << k;
            cout << endl<< endl;
        }
        case 7:
        {
            break;
        }
            if (ch == 7)
                break;
        }
    }
}