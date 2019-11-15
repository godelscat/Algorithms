"""
Dijkstra's algorithm to find the shortest path from source to all other vertex
in DIRECTED/(or undirectred) NON-NEGATIVE weight graph (cycle is allowed).

DIJKSTREA.(G, w, s):
    INITIALIZE-SINGLE-SOURCE(G, s):
        for each v in G.V:
            v.p = NIL
            v.d = INF
        s.d = 0
    S = {}
    Q = G.V # min-priority queue with key v.d
    while Q is not empty:
        u = EXTRACT-MIN(Q)
        S = S + {u}
        for v in Adj[u]:
            RELAX(u, v, w)

NOTE: RUNTIME depends on how to implent Q
    if Q is array: O(V * V + E) = O(V^2)
    if Q is min-Heap: O(V * lgV + E * lgV)
    if Q is Fib-Heap: O(V * lgV + E)
"""

from collections import defaultdict
import heapq

INF = float('inf')

class Graph:
    def __init__(self, V):
        self.V = V
        self.vertex = []
        self.parent = {}
        self.key = {} # store priority d
        self.queue = [] # priority queue
        self.edges = defaultdict(list)
    
    def addEdge(self, u, v, w):
        self.edges[u].append((v, w))
        if u not in self.vertex:
            self.vertex.append(u)
        if v not in self.vertex:
            self.vertex.append(v)
    
    def _init(self, s):
        for v in self.vertex:
            self.parent[v] = None
            self.key[v] = INF
            self.queue.append([INF, v])
        idx = self.queue.index([INF, s])
        self.queue[idx][0] = 0
        self.key[s] = 0
    
    def _relax(self, u, v, w):
        if self.key[v] > self.key[u] + w:
            idx = self.queue.index([self.key[v], v])
            self.key[v] = self.key[u] + w
            self.queue[idx][0] = self.key[u] + w
            heapq._siftdown(self.queue, 0, idx)
            self.parent[v] = u
    
    def dijkstra(self, s):
        self._init(s)
        heapq.heapify(self.queue)
        while self.queue:
            _, u = heapq.heappop(self.queue)
            for v, w in self.edges[u]:
                self._relax(u, v, w)

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
    g.addEdge(0, 1, 10)
    g.addEdge(1, 2, 1)
    g.addEdge(1, 3, 2)
    g.addEdge(0, 3, 5)
    g.addEdge(3, 1, 3)
    g.addEdge(3, 4, 2)
    g.addEdge(3, 2, 9)
    g.addEdge(2, 4, 4)
    g.addEdge(4, 2, 6)
    g.addEdge(4, 0, 7)
    g.dijkstra(0)
    print(g.key)
    g.findPath(0, 4)