/* a) Write a C++ program using STL for sorting and searching user defined records such as personal records
(Name,DOB,Telephone number etc)using vector container*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string name_to_find;

class record
{
    public:
    string name;
    long int phone;
    string DOB;
};

bool comp_by_name(record r1,record r2)
{
    return r1.name<r2.name;
}

bool comp_by_DOB(record r1,record r2)
{
    return r1.DOB<r2.DOB;
}

bool comp_by_phone(record r1,record r2)
{
    return r1.phone<r2.phone;
}

bool find_by_name(record r)
{
    return name_to_find==r.name;
}

int main()
{
    vector<record> v;
    int n,input;

    while(true)
    {
        cout<<"\nEnter the operation you want to perform\n";
        cout<<"\n1.Create records"<<endl<<"2.Display"<<endl<<"3.Search"<<endl<<"4.Sort"<<endl<<"5.Exit"<<endl;
        cin>>input;
        switch (input)
        {
            case 1:
            {
                cout<<"\nEnter the number of records you want to input\n";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                cout<<"Enter the record number "<<i+1<<endl;
                record r;
                cout<<"\nEnter the name\n";
                cin>>r.name;
                cout<<"\nEnter the DOB\n";
                cin>>r.DOB;
                cout<<"\nEnter the phone number\n";
                cin>>r.phone;
                v.push_back(r);
                }
                break;
            }
            case 2:
            {
                for (int i = 0 ; i < n ;i++)
                {
                    cout<<i+1<<" "<<v[i].name<<" "<<v[i].DOB<<" "<<v[i].phone<<endl ;
                }
                break;
            }
            case 3:
            {
			    cout<<"\nEnter the name of which you want to find the record\n";
                cin>>name_to_find;

                vector<record>::iterator it;
                it=find_if(v.begin(),v.end(),find_by_name);
                if(it!=v.end())
                {
                cout<<"\nRecord found for the name\n";
                cout<<it->name<<endl;
                cout<<it->DOB<<endl;
                cout<<it->phone<<endl;
                }
                else
                {
                    cout<<"\nRecord not found for the name\n";
                }
                break;
            }
            case 4:
            {
                int menu1;
                cout<<"\nSelect the data which you want to sort\n"<<endl<<"1)Name"<<endl<<"2)DOB"<<endl<<"3)Phone"<<endl;
                cin>>menu1;
                if(menu1 == 1)
                {
                    sort(v.begin(), v.end(),comp_by_name);
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i].name<<"\n";
                    }
                }
                else if(menu1 == 2)
                {
                    sort(v.begin(), v.end(),comp_by_DOB);
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i].DOB<<"\n";
                    }
                }
                else if(menu1 == 3)
                {
                    sort(v.begin(), v.end(),comp_by_phone);
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i].phone<<"\n";
                    }
                }
                else
                {
                    cout<<"\nEnter a valid input\n"<<endl;
                }
                break;
            }
            default:
                break;
        }
        if(input==5)
        {
            cout<<"\nExit\n";
            break;
        }
    }
    return 0;
}
