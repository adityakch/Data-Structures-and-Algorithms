def largest_element(arr):
    largest = arr[0]

    for i in range(1, len(arr)):
        if arr[i] > largest:
            largest = arr[i]
    
    return largest


arr = [1, 5, 3, 9, 2, 8, 4, 7, 6]
print(largest_element(arr))