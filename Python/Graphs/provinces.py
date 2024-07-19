def dfs(curr, vis, adjL):
    vis[curr] = True

    for i in adjL[curr]:
        if vis[i] == False:
            vis[i] = True


def provinces(adj):
    n = len(adj)
    adjList = []

    # create adj List from adj Matrix
    for i in range(n):
        adjList.append([])

    for i in range(n):
        for j in range(n):
            if adj[i][j] == 1 and i != j:
                adjList[i].append(j)
                adjList[j].append(i)

    print(adjList)

    visited = [False] * n
    counter = 0 

    for i in range(n):
        if visited[i] == False:
            counter += 1
            dfs(i, visited, adjList)

    return counter


# isConnected = [[1,1,0],[1,1,0],[0,0,1]]
isConnected = [[1,0,0],[0,1,0],[0,0,1]]

print(provinces(isConnected))