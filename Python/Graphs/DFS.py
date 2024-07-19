def dfs2(V, adj):
    res = []
    visited = set()

    def dfs(curr):
        visited.add(curr)
        res.append(curr)

        for i in adj[curr]:
            if i not in visited:
                dfs(i)

    dfs(0)

    return res


def dfsOfGraph(V, adj):
    res = []
    visited = [False] * V

    def dfs(curr):
        visited[curr] = True
        res.append(curr)

        for i in adj[curr]:
            if visited[i] == False:
                dfs(i)

    dfs(0)

    return res


V = 5
adjList = [[2,3,1] , [0], [0,4], [0], [2]]

print(dfsOfGraph(V, adjList))
print(dfs2(0, adjList))