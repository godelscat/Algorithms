"""
Bellman-Ford Algorithm to find the shortest path from source to all other vertex 
in a weighted DIRECTED graph. It allows NEGATIVE weights, and can detect whether 
or not there is a negative-weight cycle that is reachable from the source.

BELLMAN-FORD(G, w, s):
    INITIALIZE-SINGLE-SOURCE(G, s)
    for i = 1 to G.V - 1:
        for each edge (u, v) in G.E:
            RELAX(u, v, w)
    for each edge(u, v) in G.E:
        if v.d > u.d + w(u, w):
            print("There is negative-cycle reachable from s")
            return False
    print("No such negative-cycle")
    return True


NOTE: The RUNTIME is O(V + VE + E) = O(VE)
"""

from collections import defaultdict

INF = float('inf')

class Graph:
    def __init__(self, V):
        self.V = V
        self.vertex = []
        self.key = {}
        self.parent = {}
        self.edges = defaultdict(list)
    
    def addEdge(self, u, v, w):
        self.edges[u].append((v, w))
        if u not in  self.vertex:
            self.vertex.append(u)
        if v not in self.vertex:
            self.vertex.append(v)
    
    def _init(self, s):
        for u in self.vertex:
            self.key[u] = INF
            self.parent[u] = None
        self.key[s] = 0

    def relax(self, u, v, w):
        if self.key[v] > self.key[u] + w:
            self.key[v] = self.key[u] + w
            self.parent[v] = u
    
    def bellmanFord(self, s):
        self._init(s)
        for i in range(self.V - 1):
            for u in self.edges:
                for v, w in self.edges[u]:
                    self.relax(u, v, w)
        
        for u in self.edges:
            for v, w in self.edges[u]:
                if self.key[v] > self.key[u] + w:
                    print("There is negative-cycle.")
                    return

        print("No negative-cycle.")
    
    def findPath(self, s, u):
        if self.parent[u] is None:
            print("No path from {0} ---> {1} ".format(s, u))
        else:
            temp = u
            while self.parent[temp] is not None:
                print("{0} -----> {1}".format(self.parent[temp], temp))
                temp = self.parent[temp]
            print("Shortest Weight is {}".format(self.key[u]))


if __name__ == "__main__":
    g = Graph(5)
    g.addEdge(0, 1, 6)
    g.addEdge(0, 3, 7)
    g.addEdge(1, 2, 5)
    g.addEdge(2, 1, -2)
    g.addEdge(1, 3, 8)
    g.addEdge(1, 4, -4)
    g.addEdge(3, 4, 9)
    g.addEdge(4, 0, 2)
    g.addEdge(3, 2, -3)
    g.addEdge(4, 2, 7)
    g.bellmanFord(0)
    print(g.key)
    g.findPath(0, 4)