# Kosaraju's algorithm to find strongly connected components in Python


from collections import defaultdict

class Graph:

    def __init__(self, vertex):
        self.V = vertex
        self.graph = defaultdict(list)

    # Add edge into the graph
    def add_edge(self, s, d):
        self.graph[s].append(d)

    # dfs
    def dfs(self, d, visited_vertex):
        visited_vertex[d] = True
        print(d, end='')
        for i in self.graph[d]:
            if not visited_vertex[i]:
                self.dfs(i, visited_vertex)

    def fill_order(self, d, visited_vertex, stack):
        visited_vertex[d] = True
        for i in self.graph[d]:
            if not visited_vertex[i]:
                self.fill_order(i, visited_vertex, stack)
        stack = stack.append(d)

    # transpose the matrix
    def transpose(self):
        g = Graph(self.V)

        for i in self.graph:
            for j in self.graph[i]:
                g.add_edge(j, i)
        return g

    # Print stongly connected components
    def print_scc(self):
        stack = []
        visited_vertex = [False] * (self.V)

        for i in range(self.V):
            if not visited_vertex[i]:
                self.fill_order(i, visited_vertex, stack)

        gr = self.transpose()

        visited_vertex = [False] * (self.V)

        while stack:
            i = stack.pop()
            if not visited_vertex[i]:
                gr.dfs(i, visited_vertex)
                print("")


g = Graph(18)
g.add_edge(4, 12)
g.add_edge(12, 0)
g.add_edge(0, 10)
g.add_edge(15, 1)
g.add_edge(1, 15)
g.add_edge(1, 17)
g.add_edge(2, 3)
g.add_edge(2, 1)
g.add_edge(16, 2)
g.add_edge(5,7)
g.add_edge(7,8)
g.add_edge(7 , 9)
g.add_edge(8 , 9)
g.add_edge(9 , 10)
g.add_edge(6 , 11)
g.add_edge(11 , 14)
g.add_edge(14 , 13)
g.add_edge(14, 4)
g.add_edge(13 ,6 )


print("Strongly Connected Components:")
g.print_scc()
