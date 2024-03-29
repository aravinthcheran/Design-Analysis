#to find min and max value in a given array using divide and conquer approach
from array import array
from typing import Tuple

def min_max(arr: array) -> Tuple[int, int]:
    low= 0
    high= len(arr) - 1
    if low == high:
        return arr[low],arr[low]
    else:
        mid = (low + high) // 2
        min1, max1 = min_max(arr[:mid+1])
        min2, max2 = min_max(arr[mid+1:])
        return min1 if min1 < min2 else min2, max1 if max1 > max2 else max2

print("Minimum and Maximum values in the given array are: ", min_max([3, 1, 4, 2, 5, 6, 7, 8, 9, 10]))