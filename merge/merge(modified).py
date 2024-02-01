from typing import List

def merge_sort(arr: List[int])->List[int]:
    low:int=0
    high:int=len(arr)-1
    if(low==high):
        return [arr[low]]
    else:
        mid:int=(low+high)//2
        left_arr=merge_sort(arr[low:mid+1])
        right_arr=merge_sort(arr[mid+1:high+1])
        return merge(left_arr,right_arr)

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

print(merge_sort([3,1,4,2,5,6,7,8,9,10]))