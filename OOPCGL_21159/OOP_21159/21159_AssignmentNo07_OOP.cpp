/*Write C++ program that creates output file, writes information to it,closes the file, open it again as an input file 
and read the information from the file.*/

#include<iostream>
#include<fstream>
using namespace std;

class book
{
    float price;
    string author;

public:

    book()
    {
        price=0;
        author="None";
    }

    void take(float p,string a)
    {
        price=p;
        author=a;
    }

    void write_(fstream &out)
    {
        out<<"\nThe price of the book is: "<<price;
        out<<"\nThe name of the author of the book is: "<<author;
    }

    void read_(fstream &in)
    {
        char line[80];
        cout<<"\nContents of file: \n";
        while(in)
        {
            in.getline(line,80);
            cout<<line<<"\n";
        }
        in.close();
    }
};

int main()
{
    book a;
    fstream out; //creating the stream
    out.open("Assignment4.txt",ios::out); //connect stream to Assignment4.txt
    string book;
    cout<<"Enter the book name you want to include in the file: ";
    cin>>book;
    out<<"The name of the book is: "<<book;

    float price;
    string name;

    cout<<"\nEnter the price of the book: ";
    cin>>price;

    cout<<"\nEnter the author name: ";
    cin>>name;

    a.take(price,name);
    a.write_(out);
    out.close();  //disconnects the stream 

    fstream in;
    in.open("Assignment4.txt",ios::in);
    a.read_(in);
    return 0;
}
