class sort:
    def __init__(self,p=0):
        self.numbers= p
        self.list=[]
        print("\nEnter the numbers:")
        for i in range(self.numbers):
            s=int(input())
            self.list.append(s)

    def insertionsort(self):
        for i in range(1,self.numbers):
            key = self.list[i]
            j = i - 1
            while j >= 0 and key < self.list[j]:
                self.list[j + 1] = self.list[j]
                j -= 1
            self.list[j + 1] = key
        return self.list

    def shellsort(self):
        n = self.numbers
        arr = self.list
        inc = n // 2
        while inc != 1:
            j = inc
            while j < n:
                i = j - inc
                while i >= 0:
                    if arr[i + inc] > arr[i]:
                        break
                    else:
                        arr[i + inc] = arr[i]
                        arr[i] = arr[i + inc]
                        i = i - inc
                j += 1
            inc = inc//2
        return arr


while(True):
    p=int(input("\nEnter the operation you want to perfrom:\n1.Insertion Sort\n2.Shell Sort\n3.Binary search\n3.Exit\n"))
    m=int(input("\nHow many numbers you want to Sort:\n>>"))
    if p==1:
        o=sort(m)
        o.insertionsort()
    elif p==2:
        o=sort(m)
        o.shellsort()
    elif p==3:
        break
    else:
        print("Invalid input")