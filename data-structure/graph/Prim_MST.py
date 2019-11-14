"""
MST-PRIM(G, w, r):
    for each u in G.V:
        u:key = INF
        u:p = NIL
    r:key = 0
    Q = G.V # minimum priority queue
    while Q is not empty:
        u = EXTRACT-MIN(Q) # O(lgV)
        for each v in Adj[u]:
            if v in Q and w(u, v) < v.key:
                v.p = u
                v.key = w(u, v)

NOTE: Use HEAP to implement Q; 
      IDEAL RUNTIME is O(V lgV + E lgV) = O(E lgV); 
      In fact, even though Heap is used, we stil cannot achieve O(E lgV) time,
      because searching node(index) in HEAP takes O(V) time.
"""

from collections import defaultdict
import heapq

INF = float('inf')

class Graph:
    def __init__(self, V):
        self.V = V
        self.parent = {}
        self.mst = []
        self.queue = [] # list of (key, vertex)
        self.key = {} # keep track of key
        self.index = {} # keep track of isIn queue
        self.edges = defaultdict(list)
    
    # Input: each undirected edge only add once
    def addEdge(self, u, v, w):
        self.edges[u].append((v, w))
        self.edges[v].append((u, w))
        if u not in self.key:
            self.queue.append([INF, u])
            self.parent[u] = u
            self.key[u] = INF
            self.index[u] = True
        if v not in self.key:
            self.queue.append([INF, v])
            self.parent[v] = v
            self.key[v] = INF
            self.index[v] = True

    def prim_mst(self):
        r = self.queue[0][1]
        self.queue[0][0] = 0
        self.key[r] = 0
        heapq.heapify(self.queue)
        while self.queue:
            _, u = heapq.heappop(self.queue)
            self.index[u] = False # remove u
            self.mst.append(u)
            for v, w in self.edges[u]:
                if self.index[v] and w < self.key[v]:
                    self.parent[v] = u
                    idx = self.queue.index([self.key[v], v]) # this takes O(V) time
                    self.queue[idx][0] = w
                    self.key[v] = w
                    heapq._siftdown(self.queue, 0, idx)

if __name__ == "__main__":
    g = Graph(9)
    g.addEdge(0, 1, 4)
    g.addEdge(0, 7, 8)
    g.addEdge(1, 7, 11)
    g.addEdge(1, 2, 8)
    g.addEdge(7, 8, 7)
    g.addEdge(7, 6, 1)
    g.addEdge(2, 3, 7)
    g.addEdge(2, 5, 4)
    g.addEdge(2, 8, 2)
    g.addEdge(6, 8, 6)
    g.addEdge(6, 5, 2)
    g.addEdge(3, 5, 14)
    g.addEdge(3, 4, 9)
    g.addEdge(4, 5, 10)
    g.prim_mst()
    for u in g.mst:
        print("{0} ----> {1} | {2}".format(u, g.parent[u], g.key[u]))