from undirected_graph import UndirectedGraph

ug = UndirectedGraph(10)

ug.add_edge(1, 2)
ug.add_edge(2, 2)
ug.add_edge(2, 4)
ug.add_edge(2, 3)

ug.remove_edge(2, 2)

ug.print()
