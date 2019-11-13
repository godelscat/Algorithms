"""
Use Adjacency list to represent graph.
Storage: O(V + E)
DFS search time: O(V + E)
"""
from collections import defaultdict

class Node:
    def __init__(self, label):
        self.color = "WHITE"
        self.label = label
        self.p = None
        self.d = None # first visit time
        self.f = None # finish scanning time
    
class Graph:
    def __init__(self, V):
        self.V = V
        self.time = 0
        self.vertex = {}
        self.edges = defaultdict(list)
    
    def addEdge(self, u, v):
        self.edges[u.label].append(v)
        if u.label not in self.vertex:
            self.vertex[u.label] = u
        if v.label not in self.vertex:
            self.vertex[v.label] = v
    
    def dfs(self):
        self.time = 0
        for u in self.vertex.values():
            if u.color == "WHITE":
                self.dfs_visit(u)
    
    def dfs_visit(self, u):
        self.time = self.time + 1
        u.color = "GRAY"
        u.d = self.time
        print(u.label, " -> ", end=" ")
        for v in self.edges[u.label]:
            if v.color == "WHITE":
                v.p = u
                self.dfs_visit(v)
        u.color = "BLACK"
        self.time = self.time + 1
        u.f = self.time
    
    def dfs_stack(self):
        self.time = 0
        stack = []
        for u in self.vertex.values():
            if u.color == "WHITE":
                u.color = "GRAY"
                stack.append(u)
                while stack:
                    self.time = self.time + 1
                    temp = stack.pop()
                    temp.d = self.time
                    print(temp.label, " -> ", end=" ")
                    for v in self.edges[temp.label]:
                        if v.color == "WHITE":
                            v.p = temp
                            v.color = "GRAY"
                            stack.append(v)
                    self.time = self.time + 1
                    temp.f = self.time

    def isCycle(self):
        for u in self.vertex.values():
            if u.color == "WHITE":
                return self._isCycle(u)
        return False

    def _isCycle(self, u):
        u.color = "GRAY"
        for v in self.edges[u.label]:
            if v.color == "WHITE":
                self._isCycle(v)
            elif v.color == "GRAY":
                return True
        u.color == "BLACK"
        return False


if __name__ == "__main__":
    g = Graph(4)
    # Node(0) is not Node(0)
    n0, n1, n2, n3 = Node(0), Node(1), Node(2), Node(3)
    g.addEdge(n0, n1)
    g.addEdge(n0, n2)
    g.addEdge(n1, n2)
    g.addEdge(n2, n0)
    g.addEdge(n2, n3)
    g.addEdge(n3, n3)
    #g.dfs()
    #g.dfs_visit(n2, 0)
    #g.dfs_stack()
    #print("\n")
    """
    for key, val in g.vertex.items():
        print(key, " ---start-time--- ", val.d, " ---end-time--- ", val.f)
    """
    if g.isCycle():
        print("cycle exist")
    else:
        print("No cycle")