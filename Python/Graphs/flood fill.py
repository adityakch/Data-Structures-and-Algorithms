import copy

def flood_fill(image, sr, sc, color):
    image_copy = copy.deepcopy(image)

    initial_color = image_copy[sr][sc]
    
    if initial_color == color:
        return image

    def dfs(image_copy,r,c):
        if r < 0 or r >= len(image_copy) or c < 0 or c >= len(image_copy[0]) or image_copy[r][c] != initial_color:
            return

        image_copy[r][c] = color

        directions = [(-1,0), (0,1), (0,-1), (1,0)]
        for dr,dc in directions:
            dfs(image_copy, r+dr, c+dc)

    dfs(image_copy,sr,sc)

    return image_copy


# image = [
#     [1,1,1],
#     [1,1,0],
#     [1,0,1]
# ]

image = [
    [1,1,1],
    [2,2,0],
    [2,2,2]
]
sr = 2
sc = 0
color = 3

print(flood_fill(image, sr, sc, color))