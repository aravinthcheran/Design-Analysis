#to find min and max value in a given array using divide and conquer approach
from typing import List
from typing import Tuple


def min_max(arr: List[int]) -> Tuple[int, int]:
    low: int = 0
    high: int = len(arr) - 1
    if low == high:
        return arr[low],arr[low]
    else:
        mid: int = (low + high) // 2
        min1, max1 = min_max(arr[low:mid+1])
        min2, max2 = min_max(arr[mid+1:high+1])
        return min1 if min1 < min2 else min2, max1 if max1 > max2 else max2


print("Minimum and Maximum values in the given array are: ", min_max([3, 1, 4, 2, 5, 6, 7, 8, 9, 10]))
