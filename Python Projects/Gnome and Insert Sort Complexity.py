import random
from timeit import default_timer as timer

def print_v(v):
    print("The list is:")
    print(v)

def random_numbers(v,n):  #List generator
    v=[]
    for i in range(0,n):
        x=random.randint(0,100)
        v.insert(i,x)
   # print("The list is:",v)
    return v


def insertsort(my_list,st):     #Insert sort
    start=timer()
    v=my_list.copy()
    ct=0
    #print(v)
    for i in range(0,len(v)):
        aux=v[i]
        j=i-1
        while j>=0 and v[j]>aux:
            v[j+1]=v[j]
            j=j-1
        v[j+1]=aux
        ct=ct+1
        if ct==st:
           # print(v)
            ct=0
    end=timer()
    print(end-start)


def gnome_sort(v,st):       #Gnome sort
    start=timer()
    ct=0
    j=0
    while j<len(v):
        if  j==0 or v[j]>v[j-1]:
            j+=1
            ct=ct+1
        else:
            v[j],v[j-1]=v[j-1],v[j]
            ct = ct + 1
            j = j - 1

        if ct==st:
         #   print(v)
            ct=0
    end=timer()
    print(end-start)

def sort1(v):
    start = timer()
    j = 0
    while j < len(v):
        if j == 0 or v[j] > v[j - 1]:
            j += 1
        else:
            v[j], v[j - 1] = v[j - 1], v[j]
            j = j - 1
    end = timer()
    return end - start



def Worst(my_list):
    v=my_list.copy()
    v.sort(reverse=True)
    print("Choose your method:")
    print("1. Insert sort.")
    print("2. Gnome sort")
    op=int(input("Your option:"))
    if(op == 1):
        sort1(v)

def Best():

    print("Choose your method:")
    print("1. Insert sort.")
    print("2. Gnome sort")
    op = int(input("Your option:"))
    if (op == 1):
        l1=500
        l2=1000
        l3=2000
        l4=4000
        l5=8000
        v=[]
        random_numbers(v,l1)
        v.sort()
        print("The time for the first list is",sort1(v))
        v = []
        random_numbers(v, l2)
        v.sort()
        print("The time for the second list is", sort1(v))
        v = []
        random_numbers(v, l3)
        v.sort()
        print("The time for the third list is", sort1(v))
        v = []
        random_numbers(v, l4)
        v.sort()
        print("The time for the forth list is", sort1(v))
        v = []
        random_numbers(v, l5)
        v.sort()
        print("The time for the fifth list is", sort1(v))







def main():         #The menu
    v = []
    st=int(input("The step is:"))
    while True:
        print("The options are:")
        print("1. Generate numbers:")
        print("2. Sort the list using the first algorithm")
        print("3. Sort the list using the second algorithm")
        print("4. Best case")
        print("5. Average case")
        print("6. Worst case")
        print("7. Exit")
        op=int(input("Your option:"))

        if op==1:
            n=int(input("Give the length of the list: "))
            v=random_numbers(v,n)
        elif op==2:
            insertsort(v,st)
        elif op==3:
            Worst(v)
        elif op==4:
            Best()
        else:
            return

main()