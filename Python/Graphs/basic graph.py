class Graph:
    def __init__(self) -> None:
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []
    
    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.graph and vertex2 in self.graph:
            self.graph[vertex1].append(vertex2)
            self.graph[vertex2].append(vertex1)

    def remove_vertex(self, vertex):
        if vertex in self.graph:
            for neighbours in self.graph[vertex]:
                self.graph[neighbours].remove(vertex)
            del self.graph[vertex]

    def remove_edge(self, vertex1, vertex2):
        if vertex1 in self.graph and vertex2 in self.graph:
            self.graph[vertex1].remove(vertex2)
            self.graph[vertex2].remove(vertex1)

    def print_graph(self):
        for vertex in self.graph:
            print("{vertex}: {edge}".format(vertex = vertex, edge = self.graph[vertex]))



my_graph = Graph()

vertices = [1,2,3,4,5,6]
for vertex in vertices:
    my_graph.add_vertex(vertex)

edges = [(1,2), (1,3), (2,3), (2,4), (4,6), (4,5),(5,3)]
for edge in edges:
    my_graph.add_edge(edge[0],edge[1])

my_graph.remove_vertex(2)
print(my_graph.print_graph())