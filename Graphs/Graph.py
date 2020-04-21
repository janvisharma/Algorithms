import collections
class Graph:
    vertices = 0
    edges = 0
    adjList = collections.defaultdict(int)

    def __init__(self, v, e):
        self.vertices = v
        self.edges = e
    
    def addToAdjList(self, v, neighbor):
        if v in self.adjList.keys():
            self.adjList[v].append(neighbor)
        else:
            self.adjList[v] = [neighbor]

    def printAdjList(self):
        print("The adjacency list is: ")
        for x in self.adjList.keys():
            print(x, ' -> ',self.adjList[x])

    def printGraphWithEdges(self):
        print("The edges are: ")
        for x in self.adjList.keys():
            for y in self.adjList[x]:
                print(x, ' - ', y)

    def degreeOfV(self,v):
        if v in self.adjList.keys():
            ctr = 0
            for x in self.adjList[v]:
                ctr = ctr + 1
        print("the degree is ",ctr)
    
    def returnAdjList(self):
        return self.adjList

    def dfs(self, v, n):
        visited = []
        if v in self.adjList.keys():
            for x in self.adjList[v]:
                if x == n:
                    print("path: ",v,' - ',x)
                    break
                else:
                    visited.append(x)
                    



            


testCase = Graph(7,7)
testCase.addToAdjList(0,5)
testCase.addToAdjList(4,3)
testCase.addToAdjList(0,1)
testCase.addToAdjList(9,12)
testCase.addToAdjList(6,4)
testCase.addToAdjList(5,4)
testCase.addToAdjList(0,2)
testCase.printAdjList()
testCase.printGraphWithEdges()
testCase.degreeOfV(0)
testCase.dfs(6,4)