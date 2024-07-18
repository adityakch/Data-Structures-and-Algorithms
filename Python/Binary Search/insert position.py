def binary_search(arr, target):
    l,r = 0, len(arr)-1

    while l <= r:
        mid = (l+r) // 2
        print(mid)
        if arr[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return l


arr = [1,3,4,5,7,9,10]
target = 6

print(binary_search(arr, target))