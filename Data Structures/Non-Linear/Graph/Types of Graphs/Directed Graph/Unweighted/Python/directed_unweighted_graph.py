class DirectedUnweightedGraph:
    def __init__(self, total_vertices: int) -> None:
        self.total_vertices = total_vertices
        self.edges = []

    def is_vertex(self, u: int) -> bool:
        return u < self.total_vertices

    def is_edge(self, u, v) -> bool:
        return [u, v] in self.edges

    def add_edge(self, u, v) -> None: # direction u -> v (u to v)
        if not (self.is_vertex(u) and self.is_vertex(v)):
            return
        else:
            if u != v or not self.is_edge(u, v): # unique edges only, and no self-loop (edge)
                self.edges.append([u, v])

    def remove_edge(self, u, v) -> None:
        if not (self.is_vertex(u) or self.is_vertex(v)):
            return
        else:
            if self.is_edge(u, v):
                self.edges.remove([u, v])

    def print(self) -> None:
        for edge in self.edges:
            print(edge[0], '->', edge[1])
