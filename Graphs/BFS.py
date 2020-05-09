import collections
class Graph:
    adjList = collections.defaultdict(int)
    
    # undirected graph
    def addToAdjList(self,v,u):
        if v in self.adjList.keys():
            self.adjList[v].append(u)
        else:
            self.adjList[v] = [u] # imp remember to use [u] because we are adding a list, not int
        
        if u in self.adjList.keys():
            self.adjList[u].append(v)
        else:
            self.adjList[u] = [v]
    
    def displayAdjList(self):
        print(self.adjList)

    
    def BFS(self,s):
        visited = [] # to keep track of vertices that we have visited
        queue = [] # visit breadth wise
        visited.append(s)
        queue.append(s)
        print(s,end=' ')

        while(len(queue)!=0):
            v = queue.pop()
            for u in self.adjList[v]:
                if u not in visited:
                    visited.append(u)
                    print(u,end=" ")
                    queue.insert(0,u)


testCase = Graph()
testCase.addToAdjList(2,3)
testCase.addToAdjList(2,8)
testCase.addToAdjList(3,5)
testCase.addToAdjList(3,6)
testCase.addToAdjList(6,7)

testCase.displayAdjList()

testCase.BFS(2)

