from undirected_weighted_graph import UndirectedWeightedGraph

uwg = UndirectedWeightedGraph(5)

uwg.add_edge(1, 2, 1)
uwg.add_edge(3, 2, 5)
uwg.add_edge(1, 3, 1)
uwg.add_edge(0, 1, 2)

uwg.print()

neighbors = uwg.get_neighbors(3)
print(neighbors)

uwg.remove_edge(2, 1)
print("\nAfter removal:")
uwg.print()
