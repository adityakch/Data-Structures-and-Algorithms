def binary_search(arr):
    l, r = 0, len(arr)-1

    while l < r:
        mid = (l+r)//2

        if arr[mid] > arr[r]:
            l = mid + 1
        else:
            r = mid
    
    return arr[l]



arr = [4,5,6,7,0,1,2]

print(binary_search(arr))