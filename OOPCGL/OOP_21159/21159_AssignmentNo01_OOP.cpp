/*Implement a class Complex which represents the Complex Number data type. Implement the 
following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers. 
*/

#include<iostream>
using namespace std;

class complex
{
    int real,imaginary;

public:

    friend operator >>(istream &,complex &);
    friend operator <<(ostream &,complex &);

    complex()
    {
        real=0;
        imaginary=0;
    }

    complex(float r,float c)
    {
        real=r;
        imaginary=c;
    }

    complex operator+(complex a)
    {
        complex temp;
        temp.real=real+a.real;
        temp.imaginary=imaginary+a.imaginary;
        return temp;
    }

    complex operator*(complex a)
    {
        complex temp;
        temp.real=real*a.real-imaginary*a.imaginary;
        temp.imaginary=real*a.imaginary+imaginary*a.real;
        return temp;
    }

};

operator>>(istream &input,complex &obj )
{
    cout << "\nEnter the real part:\n";
    input >> obj.real;
    cout << "\nEnter the imaginary part:\n";
    input >> obj.imaginary;
}

operator<<(ostream &output,complex &obj)
{
    output<<obj.real<<"+"<<obj.imaginary<<"i";
}

int main()
{
    int q;
    complex c1,c2,c3;
    cout<<"\nEnter first complex number\n";
    cin>>c1;
    cout<<"\nEnter second complex number\n";
    cin>>c2;
    while(q!=4)
    {
    cout<<"\n";
    cout<<"\nEnter the choice\n";
    cout<<"1.Print default complex number\n";
    cout<<"2.Add\n";
    cout<<"3.Multiply\n";
    cout<<"4.Exit\n";
    cin>>q;
    switch(q)
    {
        case 1:
        {
            cout<<"\nThe default complex number is "<<c3;
            break;
        }
        case 2:
        {
            c3 = c1 + c2;
            cout << "\nAddition is " << (c3);
            break;
        }
        case 3:
        {
            c3 = c1 * c2;
            cout << "\nMultiplication is " << (c3);
            break;
        }
        case 4:
        {
            cout << "\nExit";
            q=4;
            break;
        }
    }

    }

    return 0;
}
