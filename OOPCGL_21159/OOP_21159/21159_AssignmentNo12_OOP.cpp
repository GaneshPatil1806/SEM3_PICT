/* Write a C++ program to use map associative container.The keys will be the names of states and the values will 
be population of the states. When the program runs, the user is prompted to type the name of the state. The 
program, then looks in the map,using the state name as an index and returns the population of the state*/

#include <iostream>
#include <iterator>
#include<string>
#include <map>
using namespace std;

int main()
{
	map<string, int> data;
	data["Maharashtra"] = 20020000;
	data["Kerela"] = 1820000;
	data["Karnataka"] = 6310000;
	data["Gujrat"] = 25820000;
	data["Goa"] = 820000;

	cout<<"\nEnter the state name you want to get population of :"<<endl ;
	cout<<"(Enter the name such that first letter should be capital and reamining should be small)\n>>";
	string state ;
	cin>>state;
	auto iterator=data.find(state);
	if(iterator == data.end())
    {
		cout<<"Not found ";
	}
	else
    {
		cout<<iterator->first<<" has population of "<<iterator->second;
	}
	return 0 ;
}