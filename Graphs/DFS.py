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
    
    def DFS_recursive(self,s):
        if s not in self.visitedStack:
            self.visitedStack.append(s)
        
        if s in self.adjList.keys():
            for v in self.adjList[s]:
                if v not in self.visitedStack:
                    self.visitedStack.append(v)
                    self.DFS_recursive(v)
        
    '''
        DFS - non recursive solution
        We can implement the DFS algorithm using a stack
        Complexity: each element gets inserted into the stack once, O(V) +
        we need to visit each edge in the AdjList so we add O(2E)
        Total = O(V + 2E) = O(V + E) , undirected graph 
    '''
    stack = []
    order = []
    def DFS_wr(self,s):
        self.stack.insert(0,s)

        while(len(self.stack)!=0):
            v = self.stack.pop(0)
            self.order.append(v)
            for u in self.adjList[v]:
                if u not in self.order:
                    self.stack.insert(0,u)

    def printDFS(self):
        print(self.order)


testCase = Graph()
testCase.addToAdjList(2,3)
testCase.addToAdjList(2,8)
testCase.addToAdjList(3,5)
testCase.addToAdjList(3,6)
testCase.addToAdjList(6,7)

testCase.DFS_wr(2)
testCase.printDFS()

