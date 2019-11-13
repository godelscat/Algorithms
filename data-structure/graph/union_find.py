"""
Ref: https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
Find: Determine which subset a particular element is in.
Union: Join two subsets into a single subset.
Union-Find Algorithm can be used to check whether an UNDIRECTED graph contains
cycle or not. It assumes that the graph doesn't contain self-loops.
"""

from collections import defaultdict

# this time we do not use node class
class Graph:
    def __init__(self, V):
        self.V = V
        self.parent = {}
        self.rank = {}
        self.edges = defaultdict(list)
    
    # u, v is vertex label
    def addEdge(self, u, v):
        self.edges[u].append(v)
        if u not in self.parent:
            self.parent[u] = None
            self.rank[u] = 0 # default rank 0
        if v not in self.parent:
            self.parent[v] = None
            self.rank[v] = 0 # default rank 0
    
    # find the root vertex
    def find(self, u):
        temp = u
        while self.parent[temp] is not None:
            temp = self.parent[temp]
        return temp
    
    # union two subsets by rank
    def union(self, u, v):
        if self.rank[u] > self.rank[v]:
            self.parent[v] = u
        elif self.rank[v] > self.rank[u]:
            self.parent[u] = v
        else:
            self.parent[v] = u
            self.rank[u] += 1
    
    def isCycle(self):
        full_visited = []
        for u in self.parent:
            full_visited.append(u)
            u_root = self.find(u)
            for v in self.edges[u]:
                if v in full_visited:
                    continue
                v_root = self.find(v)
                if u_root == v_root:
                    return True
                self.union(u_root, v_root)
        return False

if __name__ == "__main__":
    g = Graph(4)
    g.addEdge(0, 1)
    g.addEdge(1, 0)
    g.addEdge(0, 2)
    g.addEdge(2, 0)
    g.addEdge(1, 2)
    g.addEdge(2, 1)
    g.addEdge(2, 3)
    g.addEdge(3, 3)
    if g.isCycle():
        print("Cycle Exist")
    else:
        print("No Cycle")