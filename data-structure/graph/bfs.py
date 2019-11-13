"""
Use Adjacency list to represent graph.
Storage: O(V + E)
BFS search time: O(V + E)
"""
from collections import defaultdict

class Node:
    def __init__(self, label):
        self.color = 'WHITE'
        self.p = None # parent node
        self.label = label # vertex label
        self.d = float('Inf') # tree height from source node

class Graph:
    def __init__(self, V):
        self.V = V 
        self.vertex = {}
        self.edges = defaultdict(list)
    
    # u, v is node
    def addEdge(self, u, v):
        self.edges[u.label].append(v)
        if u.label not in self.vertex:
            self.vertex[u.label] = u
        if v.label not in self.vertex:
            self.vertex[v.label] = v
    
    def bfs(self, u):
        u.d = 0
        u.color = "GRAY"
        queue = [u]
        while queue:
            temp = queue.pop(0)
            print(temp.label, " -> ", end=" ")
            for v in self.edges[temp.label]:
                if v.color == "WHITE":
                    v.color = "GRAY"
                    v.d = temp.d + 1
                    v.p = temp
                    queue.append(v)
            #temp.color = "BLACK"
        print()

if __name__ == "__main__":
    g = Graph(5)
    n0, n1, n2, n3, n4 = Node(0), Node(1), Node(2), Node(3), Node(4)
    g.addEdge(n0, n1)
    g.addEdge(n0, n2)
    g.addEdge(n0, n3)
    g.addEdge(n2, n4)
    g.bfs(n0)