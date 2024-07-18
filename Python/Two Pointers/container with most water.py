def container_with_most_water(height):
    if not height:
        return 0
    
    l, r = 0, len(height) - 1
    max_area = 0

    while l < r:
        length = height[l]  if height[l] < height[r] else height[r]
        breadth = r - l
        area = length * breadth
        max_area = max(max_area, area)

        if height[l] < height[r]:
            l += 1
        else:
            r -= 1

    return max_area


height = [1,7,2,5,4,7,3,6]
# height = [2,2,2]

print(container_with_most_water(height))