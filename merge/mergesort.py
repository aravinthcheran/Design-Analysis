#to create a new array using merge sort by appending two array of equal sizes
from typing import List

def merge(a: List[int],b: List[int])-> List[int]:
    c=[]
    fptr=0
    sptr=0
    while(fptr<len(a) and sptr<len(b)):
        if(a[fptr]<=b[sptr]):
            c.append(a[fptr])
            fptr+=1
        else:
            c.append(b[sptr])
            sptr+=1
    while(fptr<len(a)):
        c.append(a[fptr])
        fptr+=1
    while(sptr<len(b)):
        c.append(b[sptr])
        sptr+=1
    return c

print(merge([1,2,3,4,5],[6,7,8,9,10]))