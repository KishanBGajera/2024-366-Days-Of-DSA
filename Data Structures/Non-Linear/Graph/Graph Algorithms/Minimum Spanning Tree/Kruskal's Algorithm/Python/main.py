from graph import Graph

g = Graph(6)

g.add_edge(0, 1, 7)
g.add_edge(1, 2, 6)
g.add_edge(2, 3, 5)
g.add_edge(3, 4, 2)
g.add_edge(2, 4, 2)
g.add_edge(4, 5, 3)
g.add_edge(5, 0, 8)
g.add_edge(1, 5, 3)

ms, mst = g.kruskal_algo()

print(ms, mst)
