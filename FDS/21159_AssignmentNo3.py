class Matrix:
    def __init__(self,p=0,q=0):
        self.row = p
        self.columns = q
        self.u_matrix = []
        self.rowlist = []

        for i in range(p):
            self.rowlist = []
            for j in range(q):
                m=int(input("Enter element of (row,column),({} {}):".format((i+1),(j+1))))
                self.rowlist.append(m)
            self.u_matrix.append(self.rowlist)

    def display_matrix(self):
         for i in self.u_matrix:
            for j in i:
                print(j,end=" ")
            print("\n")
    
    def add(self,obj):
        if((self.row)!=(obj.row) or (self.columns)!=(obj.columns)):
            print("\nThe two matrices cannot be added as the number of row and columns are different in two matrices")
        else:
            for i in range(self.row):
                for j in range(self.columns):
                    self.u_matrix[i][j]=self.u_matrix[i][j]+obj.u_matrix[i][j]
            self.display_matrix()

    def subtract(self,obj):
        if((self.row)!=(obj.row) or (self.columns)!=(obj.columns)):
            print("\nThe two matrices cannot be subtracted as the number of row and columns are different in two matrices")
        else:
            for i in range(self.row):
                for j in range(self.columns):
                    self.u_matrix[i][j]=self.u_matrix[i][j]-obj.u_matrix[i][j]
            self.display_matrix()


    def multiply(self,other):
        m=Matrix()
        if (((self.columns)) != (other.row)):
            print("The two matrix cannot be multiplied as the two matrix don't have proper multiplying property of order")
        else :
            m.u_matrix= []
            for i in range(self.row):
                m.u_matrix.append([])
                for j in range(other.columns):
                    m.u_matrix[i].append(0)
                    for k in range(other.row):
                        m.u_matrix[i][j] += (self.u_matrix[i][k] * other.u_matrix[k][j])    
            m.display_matrix()

    def transpose(self):
        obj2=Matrix()
        for i in range(self.row):
            self.rowlist=[]
            for j in range(self.columns):
                self.rowlist.append(self.u_matrix[j][i])
            obj2.u_matrix.append(self.rowlist)
        obj2.display_matrix()
    
    def input_1(self):
        m=int(input("Enter the number of rows in matrix:\n>>"))
        n=int(input("Enter the number of columns in matrix:\n>>"))
        x=Matrix(m,n)
        return x

    def input_2(self):
        m=int(input("Enter the number of rows:\n>>"))
        n=int(input("Enter the number of columns:\n>>"))
        x=Matrix(m,n)
        a=int(input("\nEnter the number of rows:\n>>"))
        b=int(input("\nEnter the number of columns:\n>>"))
        y=Matrix(a,b)
        return x,y

while(True):
    s=Matrix()
    print("\nEnter the operation you want to perform on matrix:\n1.Addition of two matrices\n2.Subtraction of two matrices\n3.Multiplication of two matrices\n4.Transpose of the matrix\n5.Exit\n")
    p=int(input())
    if p==1:
        m,n=s.input_2()
        print("Matrix 1\n")
        m.display_matrix()
        print("\nMatrix 2\n")
        n.display_matrix()
        print("\nResultant Matrix\n")
        m.add(n)
        
    elif p==2:
        m,n=s.input_2()
        print("Matrix 1\n")
        m.display_matrix()
        print("\nMatrix 2\n")
        n.display_matrix()
        print("\nResultant Matrix\n")
        m.subtract(n)
        
    elif p==3:
        m,n=s.input_2()
        print("Matrix 1\n")
        m.display_matrix()
        print("\nMatrix 2\n")
        n.display_matrix()
        print("\nResultant Matrix\n")
        m.multiply(n)
        
    elif p==4:
        m=s.input_1()
        print("Matrix 1\n")
        m.display_matrix()
        print("\nResultant Matrix\n")
        m.transpose()
    elif p==5:
        break
    else:
        print("Invalid input")