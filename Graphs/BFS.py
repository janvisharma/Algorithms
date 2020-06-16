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

    """
        Time Analysis
        Since each vertex is enqueued at most once, each vertex would be dequeued once. The number of times a
        vertex is dequeued is 1 because we keep track of visited vertices in a list [].
        Enqueue and Dequeue take O(1) time and we perform them for each vertex once.
        O(V+V) = O(2V) = O(V) time.
        
        Now we scan the adjacency list of each vertex, if the graph is undirected each edge appears twice. 
        If the graph is directed then each edge appears once.
        Hence time taken O(2E) = O(E)
        
        Total run time = O(V+E)
    """
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

