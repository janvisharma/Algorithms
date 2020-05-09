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
    

    visitedStack = []
    
    def DFS(self,s):
        if s not in self.visitedStack:
            self.visitedStack.append(s)
        
        if s in self.adjList.keys():
            for v in self.adjList[s]:
                if v not in self.visitedStack:
                    self.visitedStack.append(v)
                    self.DFS(v)
        
    
    def printDFS(self):
        print(self.visitedStack)


testCase = Graph()
testCase.addToAdjList(2,3)
testCase.addToAdjList(2,8)
testCase.addToAdjList(3,5)
testCase.addToAdjList(3,6)
testCase.addToAdjList(6,7)

testCase.DFS(2)
testCase.printDFS()

