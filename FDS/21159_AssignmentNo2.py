def length(s):
    count=0
    for i in s:
        if i!="":
            count+=1
        else:
            break
    return count

def frequency(string):
    char=input("Enter the of which you want to check the frequency:\n")
    count=0
    for i in string:
        if char==i:
            count+=1
    print("\nThe character {} is {} time/times".format(char,count))

def palindrome(string):
    i=0
    for j in range((len(string)-1),0,-1):
        if(string[i]==string[j]):
            flag=1
        else:
            flag=0
            break
        i+=1
    if(flag==1):
        print("\nThe entered string is palindrome")
    else:
        print("\nThe entered string is not palindrome")

def first_appearence(string):
    count=0
    sub_string=input("Enter the substring\n")
    length_1=length(sub_string)
    for i in range(length(string)):
        k=i
        j=0
        while(string[k]==sub_string[j]):
            if(sub_string[j]==sub_string[-1]):
                m=k-length_1+1
                break
            k=k+1
            j=j+1

        if(j==(length_1-1)):
            count+=1
            break
    if(count==1):
        print("\nThe index of first appearance of substring {} in main string is at index {}".format(sub_string,m))
    else:
        print("\nSubstring not present")
    
def longest(list_):
    max_len=0
    for i in range(length(list_)):
        length_temp=length(list_[i])
        if(length_temp>max_len):
            max_len=length_temp
    for i in range(len(list_)):
        m=length(list_[i])
        if m== max_len:
            print(list_[i])
    
def occurance(list_):
    D={}
    m=list(set(list_))
    for i in m:
        count=0
        for j in list_:
            if i==j:
                if j=="":
                    continue
                else:
                    count+=1
                    D[i]=count
    print(D)

def input_():
    s=input("Enter the String:\n")
    print("\nThe entered string is: ",s)
    return s
    
while(True):
    print("\nEnter the operation you want to perform on strings:\n1.To display word of longest length\n2.To determine the frequency of occurance of particular character of the string\n3.To check whether the given string is palindrome or not\n4.To display index of first appearance of the substring\n5.To count the occurances of each word in a given string\n6.If you don't want to perform any operation\n>>")
    p=int(input())
    if p==1:
        m=input_()
        L=list(map(str,m.split(" ")))
        print("\nList is:",L)
        print("\nThe longest word/words from the string is/are:\n")
        longest(L)
    elif p==2:
        m=input_()
        frequency(m)
    elif p==3:
        m=input_()
        palindrome(m)
    elif p==4:
        m=input_()
        first_appearence(m)
    elif p==5:
        m=input_()
        L=list(map(str,m.split(" ")))
        print("\nList is:\n",L)
        print("\nThe occurances of each word/words\n:")
        occurance(L)
    elif p==6:
        break
    else:
        print("\nInvalid input")