from typing import List

class UndirectedWeightedGraph:
    def __init__(self, total_nodes: int) -> None:
        self.total_nodes = total_nodes
        self.matrix = [[float('inf') if i != j else 0 for i in range(total_nodes)] for j in range(total_nodes)]
        self.total_neighbors = [0]*total_nodes
    
    def is_node(self, u: int) -> bool:
        return self.total_nodes > u

    def is_edge(self, u, v) -> bool:
        return self.matrix[u][v] != float('inf') or self.matrix[u][v] != 0

    def add_edge(self,u, v, weight) -> None:
        if not self.is_node(u) or not self.is_node(v):
            return
        else:
            if u == v:
                print("Can't add a self-edge")
                return
            else:
                self.matrix[u][v] = self.matrix[v][u] = weight
                self.total_neighbors[u] += 1
                self.total_neighbors[v] += 1

    def remove_edge(self, u, v) -> None:
        if not self.is_node(u) or not self.is_node(v):
            return
        else:
            if self.is_edge(u, v):
                self.matrix[u][v] = self.matrix[v][u] = float('inf')
                self.total_neighbors[u] -= 1
                self.total_neighbors[v] -= 1 

    def get_degree(self, u) -> int:
        if not self.is_edge(u):
            return 0
        else:
            return self.total_neighbors[0]

    def get_neighbors(self, u) -> List[int]:
        if not self.is_node(u):
            return
        neighbors = []
        for i in range(self.total_nodes):
            if u != i and (self.matrix[u][i] != float('inf') or self.matrix[u][i] == 0):
                neighbors.append(i)
        return neighbors

    def print(self) -> None:
        for node in self.matrix:
            print(*node)
