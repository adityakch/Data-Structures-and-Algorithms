def two_sum(nums,target):
    lookup = {}

    for i,v in enumerate(nums):
        diff = target - v
        if diff in lookup:
            return[lookup[diff], i]
        lookup[v] = i
    return []

nums = [2,7,3,4]
target = 9

print(two_sum(nums,target))