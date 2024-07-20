from collections import deque

def dfs(grid, visited, i, j):
    if i< 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1' or (i,j) in visited:
        return
    
    # grid[i][j] = '0'
    visited.add((i,j))

    directions = [(-1,0),(0,1),(1,0),(0,-1)]

    for nr, nc in directions:
        dfs(grid, visited, i+nr, j+nc)

def bfs(grid, visited,r,c):
    q = deque([(r, c)])
    # grid[r][c] = '0'
    visited.add((r, c))

    while q:
        cur_r,cur_c = q.popleft()

        directions = [(-1,0),(0,1),(1,0),(0,-1)]

        for nr, nc in directions:
            new_r, new_c = cur_r + nr, cur_c + nc
            
            if 0 <= new_r < len(grid) and 0 <= new_c < len(grid[0]) and grid[new_r][new_c] == '1' and (new_r, new_c) not in visited:
                q.append((new_r, new_c))
                # grid[new_r][new_c] = '0'
                visited.add((new_r, new_c))



def numIslands(grid): 
    if not grid:
        return 0
    
    islands = 0
    visited = set()

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1' and (i,j) not in visited:
                dfs(grid, visited, i, j)
                islands += 1
    
    # print(grid)
    return islands


grid = [
    ["1","1","0","0","1"],
    ["1","1","0","0","1"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]

print(numIslands(grid))