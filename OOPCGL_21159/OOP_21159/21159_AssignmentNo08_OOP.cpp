/*Write a function template for selection sort that inputs,sorts and outputs aninteger array and a float array*/

#include <iostream>
using namespace std;

template<class T>

void selection_sort(T a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index=j;
            }
        }
        swap(a[min_index],a[i]);
    }
}

int main()
{
    int n;
    int p;

    cout<<"\nEnter the number of integers you want in array: \n";
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }

    cout<<"\nEnter the number of float values you want in array: \n";
    cin>>p;
    float data1[p];
    for(int i=0;i<p;i++)
    {
        cin>>data1[i];
    }

    selection_sort(data,n);
    selection_sort(data1,p);

    cout<<"\nSorted integer array\n";
    for(int i=0;i<n;i++)
    {
        cout<<data[i]<<"  ";
    }

    cout<<"\nSorted float array\n";
    for(int i=0;i<p;i++)
    {
        cout<<data1[i]<<"  ";
    }
}