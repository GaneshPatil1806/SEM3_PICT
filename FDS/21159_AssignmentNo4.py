class search:
    def __init__(self,p=0):
        self.numbers= p
        self.list=[]
        print("Enter the numbers:\n")
        for i in range(self.numbers):
            m=int(input("\n"))
            self.list.append(m)

    def linear_search(self,key):
        flag=1
        for i in range(self.numbers):
            if(key==self.list[i]):
                flag=0
                print("\nThe number {} is present at {} index".format(key,i))
        if(flag):
            print("\nEntered key is not present in the list")

    def sentinal_search(self):
        key = int(input("\nEnter the number which you have to search\n>>"))
        self.list.append(key)
        i=0
        while(self.list[i]!=key):
            i+=1
        if i==self.numbers:
            print("\nEntered element is not present in the list")          
        else:
            print("\nThe element {} is present at {} index".format(key,i))

  
    def binary_search(self,key):
        self.list.sort()
        l=0
        h=(len(self.list))-1
        while(l<=h):
            mid=(l+h)//2
            if self.list[mid]==key:
                print("\nThe element is present.")
                break
            elif key<self.list[mid]:
                h=mid-1
            elif key>self.list[mid]:
                l=mid+1
        if(l>h):
            print("\nEntered element is not present in the list")

    def fibonacci_search(self,x):
        self.list.sort()
        print(self.list)
        size = self.numbers
        offset = -1
        f0 = 0
        f1 = 1
        f2 = 1
        while f2 <= size:
            f0 = f1
            f1 = f2
            f2 = f1 + f0
        while f2 > 1:
            index = min(offset + f0, size - 1)
            if self.list[index]==x:
               print("\nThe element is present in the list")
               break
            elif self.list[index]<x:
                f2 = f1
                f1 = f0
                f0 = f2 - f1
                offset = index
                size = size - 1
            elif self.list[index]>x:
                f2 = f0
                f1 = f1 - f0
                f0 = f2 - f1
                size=size-2
        if (f1 and self.list[self.numbers - 1]==x):
            print("\nThe element {} is present at {} index".format(x,self.numbers-1))

while(True):
    p=int(input("\nEnter the operation you want to perfrom:\n1.Linear search\n2.Sentinal search\n3.Binary search\n4.Fibonacci search\n5.Exit\n"))
    m=int(input("\nHow many numbers you want in the list:\n>>"))
    key=int(input("\nEnter the number which you have to search\n>>"))
    if p==1:
        o=search(m)
        o.linear_search(key)
    elif p==2:
        o=search(m)
        o.sentinal_search(key)
    elif p==3:
        o=search(m)
        o.binary_search(key)
    elif p==4:
        o=search(m)
        o.fibonacci_search(key)
    elif p==5:
        break
    else:
        print("\nInvalid input\n")