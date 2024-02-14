class Graph:
    def __init__(self, vertex) -> None:
        self.vertex = vertex
        self.edges = []

    def is_vertex(self, u) -> bool:
        return u < self.vertex

    def add_edge(self, u: int, v: int, w: int = 1) -> None:
        if u != v and self.is_vertex(u) and self.is_vertex(v):
            self.edges.append([u, v, w])
            self.edges.append([v, u, w])

    def kruskal_algo(self):
        edges = sorted(self.edges, key=lambda x: x[2])
        visited = set()

        mst = []
        ms = 0

        for edge in edges:
            if edge[0] not in visited or edge[1] not in visited:
                visited.add(edge[0])
                visited.add(edge[1])

                mst.append(edge)
                ms += edge[2]
        
        return ms, mst

    def print(self):
        for edge in self.edges:
            print(*edge)