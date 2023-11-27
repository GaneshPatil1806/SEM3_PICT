class quick_sort:
    def __init__(self,m=0):
        self.number=m
        self.list1=[]
        print("\nEnter the numbers\n")
        for i in range(m):
            n=input()
            self.list1.append(n)

    def partition(self,p,q):
        pivot=self.list1[p]
        i=p
        for j in range(p+1,q+1):
            if(pivot>=self.list1[j]):
                i+=1
                self.list1[i],self.list1[j]=self.list1[j],self.list1[i]
        self.list1[p],self.list1[i]=self.list1[i],self.list1[p]

        return i
        
    def q_sort(self,p,q):
        if p<q :
            m=self.partition(p,q)
            self.q_sort(p,m-1)
            self.q_sort(m+1,q)

p=quick_sort(6)
p.q_sort(0,5)
print(p.list1)
