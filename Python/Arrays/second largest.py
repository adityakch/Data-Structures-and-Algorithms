def optimal(arr):
    n = len(arr)

    largest = arr[0]
    slargest = -1

    for i in range(1,n):
        if arr[i] > largest:
            slargest = largest
            largest = arr[i]
        elif arr[i] < largest and arr[i] > slargest:
            slargest = arr[i]

    return slargest

def second_largest(arr):
    n = len(arr)

    largest = arr[0]
    slargest = -1

    for i in range(1,n):
        if arr[i] > largest:
            largest = arr[i]
    
    print('LA:' , largest)
    
    for i in range(n):
        if arr[i] > slargest and arr[i] != largest:
            slargest = arr[i]
    
    return slargest

arr = [1, 5, 3, 9, 2, 8, 4, 7, 6]
print(optimal(arr))