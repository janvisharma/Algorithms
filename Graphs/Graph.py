import collections
class Graph:
    '''
        Class Graph to implement a graph object
        adjList - Adjacency List of the graph 
    '''
    vertices = 0 
    edges = 0
    adjList = collections.defaultdict(int)

    def __init__(self, v, e):
        self.vertices = v
        self.edges = e
    '''
        Method addToAdjList()
            we get in an edge as an argument of the form v and neighbor
            imp: our graph is undirected
            so neighbor will get added to v's adjacency list and
            v will also get added to neighbor's adjacency list
    '''
    def addToAdjList(self, v, neighbor):
        if v in self.adjList.keys(): # if v is already a key in adjList i.e. it already has some edges connected to it
            self.adjList[v].append(neighbor) # then we can just append the neighbor to that key entry in the adjList
            if neighbor in self.adjList.keys(): # now we also need to add v to the neighbor's adjacency list
                self.adjList[neighbor].append(v)
            else:
                self.adjList[neighbor] = [v] 
        else:
            self.adjList[v] = [neighbor] # if this is the first entry for the key 'v' then we simply add neighbor as a new entry
            if neighbor in self.adjList.keys(): # again neighbor's adjList needs to be updated to add v
                self.adjList[neighbor].append(v)
            else:
                self.adjList[neighbor] = [v]

    def printAdjList(self):
        print("The adjacency list is: ")
        for x in self.adjList.keys():
            print(x, ' -> ',self.adjList[x])

    def printGraphWithEdges(self):
        print("The edges are: ") # undirected graph
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
'''
    Decouple the graph and the graph processing routine
    So we can use a single class Graph to represent all graph objects
    and we can define several graph processing routines all working on graph objects

    We try to avoid what is called a "fat interface"
    fat interface - an interface with more member functions and friends than are logically necessary
'''    
class DFSPath:
    def __init__(self, G):
        self.adjListG = G.returnAdjList()
        self.stackVisited = []
        self.vertices = G.vertices
        self.keepTrack = [self.vertices]*self.vertices
    
    def dfs_recursive(self, s):
        '''
            Maintaing a keepTrack list 
            the indexes represent the vertices of the graph
            and the value stored at keepTrack[vertex] = parent vertex found in DFS
            this will help us backtrack and find paths between vertices
        '''
        self.stackVisited.append(s)
        if s in self.adjListG.keys():
            for x in self.adjListG[s]:
                if x not in self.stackVisited:
                    self.keepTrack[x]= s
                    self.dfs_recursive(x)

    def printStackVisited(self):
        print(self.stackVisited)
    
    def hasAPath(self,s,e):
        self.stackVisited = []
        self.dfs_recursive(s)
        # first we call DFS so that we have tracking info avail. in keepTrack list
        path = []
        ctr = 0

        while ctr<self.vertices:
            # processing all vertices
            ctr = ctr + 1
            path.append(e) # first append the 'end' 
            # we are going to trace our way back from the end to the starting vertex
            temp = self.keepTrack[e] # temp now holds the parent vertex of 'e'
            e = temp 
            if e == s:
                path.append(e)
                break # we will stop when we have reached the parent vertex
        ctr = 0
        print("\npath from end to start vertex")       
        while ctr<len(path)-1:
            print(path[ctr], ' -> ',end='')
            ctr = ctr + 1
        print(path[ctr],end=' ')
    
    def bfs(self, s):
        visitedArray = [0]*self.vertices
        queue = []
        queue.append(s)
        while(len(queue)!=0):
            i = queue.pop(0)
            if(visitedArray[i]!=1):
                visitedArray[i] = 1
                print(i,end=" ")
                for w in self.adjListG[i]:
                    if(visitedArray[w]!=1):
                        queue.append(w)

              
testCase = Graph(7,7)

testCase.addToAdjList(1,3)
testCase.addToAdjList(1,2)
testCase.addToAdjList(2,5)
testCase.addToAdjList(2,4)
testCase.addToAdjList(5,6)

testPath = DFSPath(testCase)

testPath.bfs(1)