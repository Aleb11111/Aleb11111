import copy
import math
class OrientedGraph:
    def __init__(self,nr_vertices,nr_edges):
        self.__dictIN={}
        self.__dictOUT={}
        self.__Costs={}
        self.__nr_ver=nr_vertices
        self.__nr_edges=nr_edges

        for i in range(nr_vertices):
            self.__dictIN[i]=[]
            self.__dictOUT[i]=[]

    @property
    def dict_cost(self):
        return self.__Costs

    @property
    def dict_in(self):
        return self.__dictIN

    @property
    def dict_out(self):
        return self.__dictOUT

    @property
    def number_of_vertices(self):
        return self.__nr_ver

    @property
    def number_of_edges(self):
        return self.__nr_edges

    def parse_outbound(self, x):
        for y in self.__dictOUT[x]:
            yield y

    def parse_vertices(self):
        vertices=list(self.__dictIN.keys())
        for v in vertices:
            yield v

    def parse_inbound(self,x):
        for v in self.__dictIN[x]:
            yield v

    def parse_costs(self):
        keys = list(self.__Costs.keys())
        for key in keys:
            yield self.__Costs[key]

    def in_degree(self, vertex):
        if vertex not in self.__dictIN.keys():
            return -1
        return len(self.__dictIN[vertex])

    def out_degree(self,vertex):
        if vertex not in self.__dictOUT.keys():
            return -1
        return len(self.__dictOUT[vertex])

    def add_vertex(self,vertex):
        if vertex in self.__dictIN.keys() and vertex in self.__dictOUT.keys():
            return False
        self.__dictIN[vertex]=[]
        self.__dictOUT[vertex]=[]
        self.__nr_ver+=1
        return True

    def add_edge(self, vertex1, vertex2, cost):
        if vertex1 in self.__dictIN[vertex2]:
            return False
        elif vertex2 in self.__dictOUT[vertex1]:
            return False
        elif (vertex1,vertex2) in self.__Costs.keys():
            return False
        self.__dictIN[vertex2].append(vertex1)
        self.__dictOUT[vertex1].append(vertex2)
        self.__Costs[(vertex1,vertex2)]=cost
        self.__nr_edges+=1
        return True

    def delete_vertex(self,x):
        if x not in self.__dictIN.keys() and x not in self.__dictOUT.keys():
            return False
        self.__dictIN.pop(x)
        self.__dictOUT.pop(x)
        for key in self.__dictIN.keys():
            if x in self.__dictIN[key]:
                self.__dictIN[key].remove(x)
        keys = list(self.__Costs.keys())
        for key in keys:
            if key[0] == x or key[1] == x:
                self.dict_cost.pop(key)
                self.__nr_edges-=1
        self.__nr_ver-=1
        return True

    def get_cost(self,x,y):
        return self.__Costs[(x,y)]

    def is_edge(self,x,y):
        if x in self.__dictIN[y] or y in self.__dictOUT[x]:
            return self.__Costs[(x,y)]
        return False

    def modify_cost(self,x,y,cost):
        if (x,y) not in self.__Costs.keys():
            return False
        self.__Costs[(x,y)] = cost
        return True

    def get_degree_in(self,x):
        if x not in self.__dictIN.keys():
            return -1
        return len(self.__dictOUT[x])

    def get_degree_out(self,x):
        if x not in self.__dictOUT.keys():
            return -1
        return len(self.__dictIN[x])

    def delete_edge(self,x,y):
        if x not in self.__dictIN.keys() or x not in self.__dictOUT.keys() or y not in self.__dictIN.keys() or y not in self.__dictOUT.keys():
            return False
        if x not in self.__dictIN[y]:
            return False
        if y not in self.__dictOUT[x]:
            return False
        elif (x,y) not in self.__Costs.keys():
            return False

        self.__dictIN[y].remove(x)
        self.__dictOUT[x].remove(y)
        self.__Costs.pop((x,y))
        self.__nr_edges-=1
        return True

    def make_copy(self):
        return copy.deepcopy(self)

    def transform_to_matrix(self):
        matrix = [[]]
        for vertex in self.__nr_ver:
            for y in self.__dictOUT[vertex]:
                matrix[vertex][y]=self.get_cost(vertex,y)
        return matrix

    # def lowest_cost_path_k(self, start, target, k):
    #     adj_matrix = self.transform_to_matrix()
    #     n = len(adj_matrix)
    #     d = [[math.inf] * (k + 1) for _ in range(n)]
    #
    #     # Initialize d[x,0] = 0 for the starting vertex
    #     d[start][0] = 0
    #
    #     # Use dynamic programming to compute d[x,k] for k=1,2,...,k
    #     for i in range(1, k + 1):
    #         for x in range(n):
    #             d[x][i] = d[x][i - 1]
    #             for y in range(n):
    #                 if adj_matrix[y][x] != math.inf:
    #                     d[x][i] = min(d[x][i], d[y][i - 1] + adj_matrix[y][x])
    #
    #     # Check if there is a negative cost cycle reachable from the starting vertex
    #     for x in range(n):
    #         if d[x][k] < d[x][k - 1]:
    #             return "There is a negative cost cycle reachable from the starting vertex"
    #
    #     # Return the lowest cost path from the starting vertex to the target vertex of length k
    #     return d[target][k]

    def ford_lowest_cost_walk(graph, start, target):
        n = graph.number_of_vertices
        dist = [math.inf] * n
        prev = [-1] * n

        dist[start] = 0

        for _ in range(n - 1):
            for x in range(n):
                for y in graph.parse_inbound(x):
                    cost = graph.get_cost(y, x)
                    if dist[y] + cost < dist[x]:
                        dist[x] = dist[y] + cost
                        prev[x] = y

        # Check for negative cost cycles
        for x in range(n):
            for y in graph.parse_inbound(x):
                cost = graph.get_cost(y, x)
                if dist[y] + cost < dist[x]:
                    return "There is a negative cost cycle accessible from the starting vertex"

        # Reconstruct the lowest cost walk
        path = []
        curr = target
        while curr != -1:
            path.append(curr)
            curr = prev[curr]

        path.reverse()
        return path

    def topo_sort_dfs(self, vertex, sortedList, fullyProcessed, inProcess):
        """
        Function for sorting the graph topologically.
        :param vertex: the current vertex of the graph
        :param sortedList: the list with the topological order
        :param fullyProcessed: vertices that are fully processed
        :param inProcess: vertices that are in process
        :return: True if the vertex is valid, False otherwise
        """
        inProcess.add(vertex)  # add to the set of processing vertices the current vertex
        for other_vertex in self.__dictIN[vertex]:  # process all the inbound vertices of the current vertex
            if other_vertex in inProcess:
                return False
            elif other_vertex not in fullyProcessed:  # if one of the inbound vertices of the current one is not processed
                # process it and its inbound vertices
                ok = self.topo_sort_dfs(other_vertex, sortedList, fullyProcessed, inProcess)
                if not ok:  # if we get to a vertex that is in process again we have a loop, so the graph is not a DAG
                    # we return False and the algorithm stops
                    return False
        inProcess.remove(vertex)
        sortedList.append(vertex)  # add the processed vertex to the topological sort
        fullyProcessed.add(vertex)  # add the processed vertex to the set of all the processed vertices
        return True

    def base_topo_sort(self):
        """
        Helper function for the topological sort.
        :return:the topological sort of the graph
        """
        sorted_list = []  # list for the topological sort
        fully_processed = set()  # set for all the processed vertices
        in_process = set()  # set for the vertices that are in process
        for vertex in self.__dictIN.keys():  # go through all the vertices of the graph
            if vertex not in fully_processed:
                ok = self.topo_sort_dfs(vertex, sorted_list, fully_processed, in_process)
                if not ok:  # the graph is not a DAG so we return an empty list; it does not have a topological sort
                    sorted_list.clear()
                    return []
        return sorted_list

    def highest_cost_path(self, vertex_begin, vertex_end):
        """
        Function to compute the highest cost path from vertex begin to vertex end.
        :param vertex_begin: the beginning of the path
        :param vertex_end: the end of the path
        :return: the distance(cost) of the path and the dictionary of previous vertices
        """
        topological_order_list = self.base_topo_sort()  # get the topological sort
        dist = {}  # dictionary of costs from the source
        prev = {}  # dictionary that stores for each vertex the previous vertex from the path
        m_inf = float('-inf')
        for vertex in topological_order_list:  # initialize all the values of the dictionaries
            dist[vertex] = m_inf
            prev[vertex] = -1
        dist[vertex_begin] = 0

        for vertex in topological_order_list:  # go through all the vertices
            if vertex == vertex_end:  # stop the loop if we get to the end vertex
                break
            for other_vertex in self.__dictOUT[vertex]:  # parse the outbound vertices of the current vertex
                if dist[other_vertex] < dist[vertex] + self.__Costs[(vertex, other_vertex)]:
                    # if the cost is greater update the dictionary
                    dist[other_vertex] = dist[vertex] + self.__Costs[(vertex, other_vertex)]
                    prev[other_vertex] = vertex

        return dist[vertex_end], prev

def write_graph_to_file(graph : OrientedGraph,file):

    file=open(file,"w")
    line_1=str(graph.number_of_vertices) + ' ' + str(graph.number_of_edges) + '\n'
    file.write(line_1)
    if len(graph.dict_cost) == 0 and len(graph.dict_in) ==0:
        raise ValueError("There is nothing to show!")
    for edge in graph.dict_cost.keys():
        linie_noua= "{} {} {}\n".format(edge[0], edge[1], graph.dict_cost[edge])
        file.write(linie_noua)

    file.close()

def copy_graph_to_file(graph : OrientedGraph,file):

    file=open(file,"w")
    line_1=str(graph.number_of_vertices) + ' ' + str(graph.number_of_edges) + '\n'
    file.write(line_1)
    if len(graph.dict_cost) == 0 and len(graph.dict_in) ==0:
        raise ValueError("There is nothing to show!")
    for edge in graph.dict_cost.keys():
        linie_noua= "{} {} {}\n".format(edge[0], edge[1], graph.dict_cost[edge])
        file.write(linie_noua)
    for vertex in graph.dict_in.keys():
        if len(graph.dict_in[vertex]) == 0 and len(graph.dict_out[vertex]) == 0:
            linie_noua_2="{} -1\n".format(vertex)
            file.write(linie_noua_2)
    file.close()

def read_graph_from_file(file_name):
    file=open(file_name,"r")
    line = file.readline()
    line = line.strip()
    vertices,edges=line.split(' ')
    graph=OrientedGraph(int(vertices),int(edges))
    line = file.readline().strip()
    while len(line) > 0:
        line = line.split(' ')
        if len(line) == 1:
            graph.dict_in[int(line[0])] = []
            graph.dict_out[int(line[0])] = []
        else:
            graph.dict_in[int(line[1])].append(int(line[0]))
            graph.dict_out[int(line[0])].append(int(line[1]))
            graph.dict_cost[int(line[0]), int(line[1])] = int(line[2])
        line = file.readline().strip()
    file.close()
    return graph



