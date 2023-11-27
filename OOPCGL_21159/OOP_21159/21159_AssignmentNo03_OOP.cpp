/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication 
that stores the title (a string) and price (type float) of a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data 
and displays the data members. If an exception is caught, replace all the data member 
values with zero values.*/

#include <iostream>
using namespace std;

class publication
{
	protected:
    string name;
	float price;

public:

	publication()
    {
        name="";
        price=0;
    }

	void getdata()
    {
        cout<<"\nEnter the name: ";
		cin>>name;

		cout<<"\nEnter the price: ";
		cin>>price;
		try{
			if(price<0)
			{
				throw(price);
			}
		}
		catch(float)
        {
			price=0;
		}
	}
};

class book : public publication
{
	int pages;

public:

	void getdata()
    {
		publication::getdata();
		cout<<"\nEnter the number of pages of the book: ";
		cin>>pages;
		try{
			if(pages<0){
				throw (pages);
			}
		}
		catch(int){
			pages=0;
		}
	}

	void display()
    {
		cout<<"\n============================================================\n";
		cout<<"\nName of the book: "<<name<<endl;
		cout<<"\nPrice: "<<price<<"Rs."<<endl;
		cout<<"\npage count: "<<pages<<endl;
		cout<<"\n=============================================================\n";
	}
};

class tape:public publication
{
	float minutes;

public:

	void getdata()
    {
		publication::getdata();
		cout<<"\nPlaying time (minutes) :\n";
		cin>>minutes;
		try
        {
			if(minutes<0)
            {
				throw(minutes);
			}
		}
		catch(int)
        {
			minutes=0;
		}
	}

	void display()
	{
		cout<<"\n===========================================================\n";
		cout<<"Name of the tape: "<<name<<endl;
		cout<<"Price: Rs."<<price<<endl;
		cout<<"Play time: "<<minutes<<" min"<<endl;
		cout<<"\n===========================================================\n";
	}
};


int main() 
{
	int n;
	cout<<"Publications\n";

	while(true)
	{
		cout<<"1.Add book\n2.Add Tape\n3.Exit\n";
		cin>>n;
		switch(n)
		{
		case 1:
		{
			book p;
			p.getdata();
			p.display();
			break;
		}
		case 2:
		{
			tape p;
			p.getdata();
			p.display();
			break;
		}
		case 3:
		{	
			cout<<"\nExit";
			break;
		}
		default:
			cout<<"Enter valid input";
			break;
		}
		if(n==3)
			break;	
	}
	return 0;
}

