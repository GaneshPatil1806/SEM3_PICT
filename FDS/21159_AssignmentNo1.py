def input_(x, y):
    for i in range(y):
        name = input("Name of student>>")
        j = 0
        while j < i:
            if name == x[j]:
                print("Duplicate element found enter the element again")
                name = input("Name of student>>")
                j = 0
            else:
                j += 1
        if(x==SEComp):
            x.append(name)
        else:
            if name not in SEComp:
                print("Element is not found in universal please enter all the elements again")
                x.clear()
                return input_(x,y)
            else:
                x.append(name) 
    return x

def input_num():
    global m, n, o, p
    m = int(input("\nEnter the number of students in SEComp >> "))
    n = int(input("\nEnter the number of students playing cricket >> "))
    o = int(input("\nEnter the number of students playing badminton >> "))
    p = int(input("\nEnter the number of students playing football >> "))
    if m < (n) or m < o or m < p:
        print("Enter the elements again")
        input_num()


def intersection_2(s, t):
    inter = []
    for i in range(len(s)):
        for j in range(len(t)):
            if s[i] == t[j]:
                inter.append(s[i])
    return inter

def union(m,n):
	union_=[]+m
	for i in n:
		if i not in union_:
			union_.append(i)
	return union_


def diff(s,t):
	u=(s+t)
	difference=[]
	g=intersection_2(s,t)
	for i in u:
		if i not in g:
			difference.append(i)
	return (difference)


SEComp = []
cricket = []
badminton = []
football = []

input_num()

print("Enter the names of students in SEComp >>")
input_(SEComp, m)
print("Enter the names of students playing cricket >>")
input_(cricket, n)
print("Enter the names of students playing badminton >>")
input_(badminton, o)
print("Enter the names of students playing football>>")
input_(football, p)


while (True):
    print("\nUniversal : ",SEComp)
    print("\nCricket : ",cricket)
    print("\nBadminton : ",badminton)
    print("\nFootball : ",football)
    q = int(input("\nEnter the operation you want to perform on the list of students:\n1.List of number of students who play both cricket and badminton\n2.List of number of students who play either cricket or badminton but not both\n3.List of number of students who play neither cricket nor badminton\n4.Number of students who play cricket and football but not badminton\n5.If you don't want to perform any operation\n>>"))
    if q == 1:
        print("List of number of students who play both cricket and badminton : ",intersection_2(cricket, badminton))
    elif q == 2:
        print("List of number of students who play either cricket or badminton but not both : ",diff(cricket, badminton))
    elif q == 3:
        K = []
        cb = union(cricket, badminton)
        for i in SEComp:
            if i not in cb:
                K.append(i)
        print("List of number of students who play neither cricket nor badminton : ",K)
    elif q == 4:
        G = []
        ab = intersection_2(cricket, football)
        for i in ab:
            if i not in badminton:
                G.append(i)
        print("Number of students who play cricket and football but not badminton : ",G)
    elif q == 5:
        break
    else:
        print("Invalid Input")
