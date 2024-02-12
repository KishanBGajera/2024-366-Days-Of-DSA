from directed_unweighted_graph import DirectedUnweightedGraph

dug = DirectedUnweightedGraph(10)

dug.add_edge(1, 2)
dug.add_edge(2, 1)

dug.remove_edge(1, 2)

dug.print()
