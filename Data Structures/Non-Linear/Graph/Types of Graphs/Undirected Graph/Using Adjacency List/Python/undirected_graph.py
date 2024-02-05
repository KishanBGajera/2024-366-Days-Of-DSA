from typing import List, Tuple

class UndirectedGraph:
    def __init__(self, total_nodes) -> None:
        self.total_nodes = total_nodes
        self.edges = []

    def node_exists(self, u: int) -> bool:
        return self.total_nodes > u
    
    def is_edge(self, edge: List[Tuple[int, int]]) -> bool:
        return edge in self.edges or edge[::-1] in self.edges

    def add_edge(self, u: int, v: int):
        if not self.node_exists(u) or not self.node_exists(v):
            print("Error: node doesn't exist in Graph")
        else:
            if not self.is_edge([u, v]):
                if u == v:
                    print("Exception: can't add edge to self")
                    return
                self.edges.append([u, v])
            else:
                print("EdgeExistsException: Can't add the same edge (Undirected graph)")

    def remove_edge(self, u: int, v: int) -> None:
        if not self.node_exists(u) or not self.node_exists(v):
            print("Error: node doesn't exist in Graph")
        else:
            if self.is_edge([u, v]):
                try:
                    self.edges.remove([u, v])
                except ValueError:
                    self.edges.remove([v, u])
            else:
                print("EdgeError: Edge doesn't exist")

    def get_neighbors(self, u: int):
        neighbors = []

        for i in range(self.total_nodes):
            if self.edges[i][0] == u or self.edges[0][i] == u:
                neighbors.append(self.edges[i][1] if self.edges[i][0] == u else self.edges[i][0])

        return neighbors

    def get_degree(self, u: int):
        return len(self.get_neighbors(u))
    
    def print(self):
        print("Graph: ")
        for edge in self.edges:
            print(*edge)
