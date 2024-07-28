from collections import defaultdict, deque

def findCheapestPrice(n, flights, src, dst, k):
    dist_arr = [float('inf')] * n

    adj = defaultdict(list)

    for edge in flights:
        adj[edge[0]].append((edge[1], edge[2]))
    
    print(adj)

    dist_arr[src] = 0
    q = deque([(0,src,0)])

    while q:
        stop, node, dist = q.popleft()

        if stop > k:
            continue

        for nei, wt in adj[node]:
            if dist + wt < dist_arr[nei] and stop <= k:
                dist_arr[nei] = dist + wt
                q.append((stop+1, nei, dist_arr[nei]))

    if dist_arr[dst] == float('inf'):
        return -1
    
    return dist_arr[dst]




n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1

print(findCheapestPrice(n, flights, src, dst, k))