from collections import deque
import copy

def rotten_oranges(grid):
    rows, cols = len(grid), len(grid[0])
    queue = deque()
    fresh_oranges = 0
    time = 0

    grid_copy = copy.deepcopy(grid)

    for r in range(rows):
        for c in range(cols):
            if grid_copy[r][c] == 2:
                queue.append((r,c,1))
            elif grid_copy[r][c] == 1:
                fresh_oranges += 1

    while queue and fresh_oranges > 0:
        cur_r, cur_c, time = queue.popleft()

        directions = [(-1,0), (0,1), (1,0),(0,-1)]
        for dr, dc in directions:
            new_r, new_c = cur_r + dr, cur_c + dc

            if (0 <= new_r < rows and 0 <= new_c < cols and grid_copy[new_r][new_c] == 1 ):
                grid_copy[new_r][new_c] = 2
                fresh_oranges -= 1
                queue.append((new_r, new_c, time+1))
    
    return time if fresh_oranges == 0 else -1



grid = [[2,1,1],[1,1,0],[0,1,1]]
# grid = [[2,1,1],[0,1,1],[1,0,1]]
print(rotten_oranges(grid))