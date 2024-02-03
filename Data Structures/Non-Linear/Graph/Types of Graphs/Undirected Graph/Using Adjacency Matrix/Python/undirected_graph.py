from typing import List

class UndirectedGraph:
    def __init__(self, total_nodes: int) -> None:
        self.total_nodes = total_nodes
        self.adj_matrix = [[0]*total_nodes for _ in range(total_nodes)]
        self.total_neighbors = [0]*total_nodes

    def node_exists(self, node: int) -> bool:
        return self.total_nodes > node
    
    def add_edge(self, u: int, v: int) -> None:
        if not self.node_exists(u) or not self.node_exists(v):
            print(f"Error: Node(s) {u} or {v} does not exist in the graph.")
            return
        else:
            if u != v and not self.adj_matrix[u][v]:
                self.total_neighbors[u] += 1
                self.total_neighbors[v] += 1
            self.adj_matrix[u][v] = 1
            self.adj_matrix[v][u] = 1

    def is_edge(self, u: int, v: int) -> bool:
        if not self.node_exists(u) or not self.node_exists(v):
            print(f"Error: Node(s) {u} or {v} does not exist in the graph.")
            return False
        else:
            return self.adj_matrix[u][v] == 1 and self.adj_matrix[v][u] == 1

    def remove_edge(self, u: int, v: int) -> None:
        if not self.node_exists(u) or not self.node_exists(v):
            print(f"Error: Node(s) {u} or {v} does not exist in the graph.")
            return
        else:
            if self.is_edge(u, v):
                self.adj_matrix[u][v] = 0
                self.adj_matrix[v][u] = 0

                if u != v:
                    self.total_neighbors[u] -= 1
                    self.total_neighbors[v] -= 1
    
    def get_neighbors(self, u: int) -> List[int]:
        if not self.node_exists(u):
            print(f"Error: Node {u} does not exist in the graph.")
            return []
        else:
            neighbors = []
            for i in range(self.total_nodes):
                if u != i and self.adj_matrix[u][i] == 1:
                    neighbors.append(i)
            return neighbors
        
    def get_degree(self, u: int) -> int:
        if not self.node_exists(u):
            print(f"Error: Node {u} does not exist in the graph. Cannot calculate degree.")
            return 0
        else:
            return self.total_neighbors[u]

    def print(self):
        for row in self.adj_matrix:
            print(*row)
