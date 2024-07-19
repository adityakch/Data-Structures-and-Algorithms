from collections import deque

def bfsOfGraph(V, adj):
    res = []
    queue = deque([0])
    visited = [False] * V
    visited[0] = True

    while queue:
        curr = queue.popleft()
        res.append(curr)

        for i in adj[curr]:
            if visited[i] == False:
                visited[i] = True
                queue.append(i)

    return res

V = 5
adjList = [[1,2,3], [], [4],[], []]

print(bfsOfGraph(V, adjList))