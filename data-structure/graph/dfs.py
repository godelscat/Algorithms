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
        self.vertex = set()
        self.edges = defaultdict(list)
    
    def addEdge(self, u, v):
        self.edges[u.label].append(v)
        self.vertex.update([u, v])
    
    def dfs(self):
        time = 0
        for u in self.vertex:
            if u.color == "WHITE":
                self.dfs_visit(u, time)
    
    def dfs_visit(self, u, time):
        time = time + 1
        u.color = "GRAY"
        u.d = time
        print(u.label, " -> ", end=" ")
        for v in self.edges[u.label]:
            if v.color == "WHITE":
                v.p = u
                self.dfs_visit(v, time)
        u.color = "BLACK"
        time = time + 1
        u.f = time
    
    def dfs_stack(self):
        time = 0
        stack = []
        for u in self.vertex:
            if u.color == "WHITE":
                u.color = "GRAY"
                stack.append(u)
                while stack:
                    time = time + 1
                    temp = stack.pop()
                    temp.d = time
                    print(temp.label, " -> ", end=" ")
                    for v in self.edges[temp.label]:
                        if v.color == "WHITE":
                            v.p = temp
                            v.color = "GRAY"
                            stack.append(v)
                    time = time + 1
                    temp.f = time


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
    g.dfs_stack()

    print("\n")