import heapq

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v, weight):
        """Adiciona uma aresta ao grafo."""
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))  # Grafo não direcionado

    def dijkstra(self, start, end):
        """Encontra o menor caminho entre dois vértices usando o Algoritmo de Dijkstra."""
        # Fila de prioridade para explorar os vértices
        pq = [(0, start)]  # (distância acumulada, vértice atual)
        distances = {vertex: float('inf') for vertex in self.graph}
        distances[start] = 0
        predecessors = {vertex: None for vertex in self.graph}

        while pq:
            current_distance, current_vertex = heapq.heappop(pq)

            # Se chegarmos ao destino, terminamos
            if current_vertex == end:
                break

            # Verifica os vizinhos
            for neighbor, weight in self.graph[current_vertex]:
                distance = current_distance + weight

                # Atualiza a distância se for menor
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    predecessors[neighbor] = current_vertex
                    heapq.heappush(pq, (distance, neighbor))

        # Reconstrói o caminho
        path = []
        at = end
        while at is not None:
            path.append(at)
            at = predecessors[at]
        path.reverse()

        return distances[end], path


# Testando com o grafo da figura
if __name__ == "__main__":
    g = Graph()
    # Adicionando as arestas do grafo
    g.add_edge('A', 'B', 6)
    g.add_edge('A', 'C', 3)
    g.add_edge('B', 'C', 2)
    g.add_edge('B', 'D', 5)
    g.add_edge('C', 'D', 3)
    g.add_edge('C', 'E', 4)
    g.add_edge('D', 'E', 2)
    g.add_edge('D', 'F', 3)
    g.add_edge('E', 'F', 5)

    # Calculando o menor caminho entre A e F
    start = 'A'
    end = 'F'
    distance, path = g.dijkstra(start, end)

    print(f"Menor caminho de {start} para {end}: {path} com distância {distance}")