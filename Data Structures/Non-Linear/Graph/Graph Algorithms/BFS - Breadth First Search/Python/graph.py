class Graph:
    def __init__(self, vertex) -> None:
        self.vertex = vertex
        self.edges = {}

    def is_vertex(self, u) -> bool:
        return u < self.vertex

    def add_edge(self, u: int, v: int) -> None:
        if self.is_vertex(u) and self.is_vertex(v):
            if u in self.edges:
                self.edges[u].append(v)
            else:
                self.edges[u] = [v]

    def bfs(self, source):
        visited = set()
        queue = []

        queue.append(source)
        visited.add(source)

        while queue:
            source = queue.pop(0)
            print(source, end=" ")

            if source in self.edges:
                for node in self.edges[source]:
                    if node not in visited:
                        queue.append(node)
                        visited.add(node)

    def print(self):
        for node in self.edges:
            print(node, self.edges[node])