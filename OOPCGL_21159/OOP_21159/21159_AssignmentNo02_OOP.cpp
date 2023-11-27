/*Develop an object oriented program in C++ to create a database of student information system containing the following information:
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor,
Copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete as well as exception handling.*/

#include <iostream>
#include <cstring>
using namespace std;

class student
{
    int *RollNo; // declare an integer pointer
    int Division,m;
    string TelephoneNo;
    string DLNo;
    string Name, Class, BloodGroup, ContactAddress, Birthday;
    static int count;
    friend class frnd;

public:
    student()//Default constructor
    {
       RollNo = new int;  // dynamically allocation of memory
    }

    static void static_func();

    student(student &a) //Copy constructor
    {
        cout<<"\n=============================================\n";
        cout << "Copy constructor called\n";
        cout<<"\n=============================================\n";
        Name = a.Name;
        this->RollNo =new int;
        *RollNo = *a.RollNo;
        Division = a.Division;
        TelephoneNo = a.TelephoneNo;
        DLNo = a.DLNo;
        Class = a.Class;
        BloodGroup = a.BloodGroup;
        ContactAddress = a.ContactAddress;
        Birthday = a.Birthday;
    }

    void thisp(int m)
    {
        this->m =m;
    }
    int thispdisplay()
    {
       return m;
    }

    void getdata()
    {
    	cout<<"\nEnter the data of student "<<thispdisplay()<<endl;
        cout << "\nEnter name of the student:\n";
        cin >> Name; //It is used when the variable name in class and member function local variable name in class is same
        cout << "\nEnter Roll no:\n";
        cin >> *RollNo; // Taking input and assigning value to the memory
        cout << "\nEnter your Class:\n";
        cin >> Class;
        cout << "\nEnter your division:\n";
        cin >> Division;
        //Exeption handling
        try{
			if(Division<0)
			{
				throw(Division);
			}
		}
		catch(int)
        {
			cout << "\nEnter your division again:\n";
            cin >> Division;
		}
        cout << "\nEnter your Telephone number:\n";
        cin >> TelephoneNo;
        cout << "\nEnter your Driving license number:\n";
        cin >> DLNo;
        cout << "\nEnter your blood group:\n";
        cin >> BloodGroup;
        cout << "\nEnter your Contact address:\n";
        cin >> ContactAddress;
        cout << "\nEnter your birthday (dd/mm/yyyy): ";
        cin >> Birthday;
    }

    ~student()
    {
        cout << "\nDestructor called\n";
        delete RollNo;  // deallocation the memory
    }
};

int student::count = 1;

inline void student::static_func()
{
    cout << "\nData of student " << count << " is " << endl;
    count++;
}

class frnd
{
public:
    frnd(student &a)
    {

        cout<<"\n=============================================\n";
        cout << "\nName of the student is:  " << a.Name << endl;
        cout << "\nRoll number of the student is: " << *a.RollNo << endl;
        cout << "\nClass of the student is: " << a.Class << endl;
        cout << "\nDivision of the student is: " << a.Division << endl;
        cout << "\nTelephone number of the student is: " << a.TelephoneNo << endl;
        cout << "\nDriving licence number of the student: " << a.DLNo << endl;
        cout << "\nBlood group of the student is: " << a.BloodGroup << endl;
        cout << "\nContact address of the student is: " << a.ContactAddress << endl;
        cout << "\nBirth date of the student is: " << a.Birthday << endl;
        cout<<"\n=============================================\n";
    }
};

int main()
{
    int num; //Number of students
    string a;
    cout << "Enter total number of students: ";
    cin >> num;
    student data[num]; //num=4,data[0],data[1],data[2],data[3]   
    for (int i = 0; i < num; ++i)
    {
        data[i].thisp(i+1);  //data[0], 1 st time this pointer invoked
    	data[i].getdata();
    	cout<<"\nDo you want to invoke copy constructor?Y/n : ";
    	cin>>a;
    	if(a=="Y")
    	{
    		student ni=data[i];
            cout<<"\nCopied information:\n";
    		frnd pi(ni);
    	}

	
    }
    cout<<"\n=============================================\n";
    cout<<"\nStudent Database\n";
    cout<<"\n=============================================\n";
    for(int i=0;i<num;i++)
    {
        data[0].static_func();
	    frnd fd(data[i]);
    }
 
    return 0;
}