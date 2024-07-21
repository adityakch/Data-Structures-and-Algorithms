def dfs(r,c,board,visited):
    if r < 0 or c < 0 or r >= len(board) or c >= len(board[0]) or (r,c) in visited or board[r][c] != 'O':
            return

    visited.add((r,c))

    directions = [(-1,0), (0,1), (1,0), (0,-1)]
    for dr, dc in directions:
        dfs(dr + r, dc + c, board, visited)

def surrounded_regions(board):
    visited = set()
    rows = len(board)
    cols = len(board[0])

    for i in range(cols):
        if board[0][i] == 'O':
            dfs(0,i, board, visited)
        if board[rows-1][i] == 'O':
            dfs(rows-1, i, board, visited)
    
    for j in range(rows):
        if board[j][0] == 'O':
            dfs(j,0, board, visited)
        if board[j][cols-1] == 'O':
            dfs(j,cols-1, board, visited)
    
    for r in range(rows):
        for c in range(cols):
            if board[r][c] == 'O' and (r,c) not in visited:
                # print(r,c)
                board[r][c] = 'X'

    # print(visited)
    return board



board = [
    ["X","X","X","X"],
    ["X","O","O","X"],
    ["X","X","O","X"],
    ["X","O","X","X"]
]

print(surrounded_regions(board))