def binary_search(arr,target):
    left, right = 0, len(arr)-1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[left] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1


arr = [1,3,4,5,7,9,10]
target = 7

print(binary_search(arr,target))