def binary_search(arr, target):
    l, r = 0, len(arr)-1

    while l <= r:
        mid = (l+r)//2

        if arr[mid] == target:
            return mid
        
        if arr[l] <= arr[mid]: # left part sorted
            if arr[l] <= target <arr[mid]:
                r = mid - 1
            else:
                l = mid + 1
        else: # right parted sorted
            if arr[mid] < target <= arr[r]:
                l = mid + 1
            else:
                r = mid - 1
    
    return -1

arr = [4,5,6,7,0,1,2]
target = 0

print(binary_search(arr, target))