from graph import Graph

g = Graph(5)

g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(1, 3)
g.add_edge(2, 4)
g.add_edge(3, 4)
g.add_edge(4, 1)
# g.add_edge(2, 5)

g.dfs(2)
