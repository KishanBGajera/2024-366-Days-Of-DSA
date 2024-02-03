from undirected_graph import UndirectedGraph

def main():
    graph = UndirectedGraph(5)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)

    print("Graph:")
    graph.print()

    print("Neighbors of node 3:", graph.get_neighbors(3))

    graph.remove_edge(1, 3)

    print("\nGraph after removing edge (1, 3):")
    graph.print()

if __name__ == "__main__":
    main()
