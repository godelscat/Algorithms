"""
Ref:https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
Steps to find MST using Kruskal's algorithm:
    1. Sort all the edges in non-decreasing order of their weight.
    2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed 
        so far. If cycle is not formed, include this edge. Else, discard it.
    3. Repeat step#2 until there are (V-1) edges in the spanning tree.

NOTE: The edge of this UNDIRECTED graph only register once for each pair of vertex.
"""

from collections import defaultdict

class Graph:
    def __init__(self, V):
        self.V = V
        self.parent = {}
        self.rank = {}
        self.mst = [] # MST weight and edges
        self.weight = defaultdict(list) # weight of each edge
        #self.edges = defaultdict(list) # could discard

    def addEdge(self, w, u, v):
        #self.edges[u].append(v)
        self.weight[w].append((u, v))
        if u not in self.parent:
            self.parent[u] = None
            self.rank[u] = 0
        if v not in self.parent:
            self.parent[v] = None
            self.rank[v] = 0
    
    # find the root vertex of u
    def find(self, u):
        temp = u
        while self.parent[temp] is not None:
            temp = self.parent[temp]
        return temp
    
    # union two root vertex by rank
    def union(self, u_root, v_root):
        if self.rank[u_root] > self.rank[v_root]:
            self.parent[v_root] = u_root
        elif self.rank[u_root] < self.rank[v_root]:
            self.parent[u_root] = v_root
        else:
            self.parent[v_root] = u_root
            self.rank[u_root] += 1
    
    # find the minimum spanning tree
    def get_mst(self):
        for key in sorted(self.weight.keys()):
            w = key
            for u, v in self.weight[w]:
                u_root = self.find(u)
                v_root = self.find(v)
                if u_root != v_root:
                    self.mst.append((w, u, v))
                    self.union(u_root, v_root)
                if len(self.mst) >= self.V - 1:
                    break

if __name__ == "__main__":
    g = Graph(9)
    g.addEdge(4, 0, 1)
    g.addEdge(8, 1, 2)
    g.addEdge(7, 2, 3)
    g.addEdge(9, 3, 4)
    g.addEdge(10, 4, 5)
    g.addEdge(2, 5, 6)
    g.addEdge(1, 6, 7)
    g.addEdge(7, 7, 8)
    g.addEdge(6, 6, 8)
    g.addEdge(2, 8, 2)
    g.addEdge(4, 5, 2)
    g.addEdge(14, 5, 3)
    g.addEdge(11, 7, 1)
    g.addEdge(8, 7, 0)
    g.get_mst()
    for w, u, v in g.mst:
        print("{1} ----> {2} | {0}".format(w, u, v))