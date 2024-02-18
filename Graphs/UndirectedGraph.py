import copy


class UndirectedGraph:
    def __init__(self, nr_vertices, nr_edges):
        """
        Initialization of the graph
        :param nr_vertices: the number of vertices
        :param nr_edges: the number of edges
        """

        self._nr_vertices = nr_vertices
        self._nr_edges = nr_edges
        self._dict_bound = {}
        self._vertices = []
        for i in range(nr_vertices):
            self._dict_bound[i] = []   # create a list for each vertex
            self._vertices.append(i)   # append the vertex

    @property
    def vertices(self):  # getter for vertices
        return self._vertices

    @property
    def dict_bound(self):  # getter for dict
        return self._dict_bound

    @property
    def nr_vertices(self):
        return self._nr_vertices #getter nr vertices

    @property
    def nr_edges(self):
        return self._nr_edges  #getter nt_edges

    def parse_vertices(self):
        for vertex in self._vertices:
            yield vertex

    def parse_bound(self, vertex):
        for y in self._dict_bound[vertex]:
            yield y

    def add_vertex(self, vertex):
        if vertex in self._vertices:
            return False
        self._vertices.append(vertex)
        self._dict_bound[vertex] = []
        self._nr_vertices+=1
        return True

    def remove_vertex(self, vertex):

        if vertex not in self._vertices or vertex not in self._dict_bound.keys():
            return False
        self._vertices.remove(vertex)
        self._dict_bound.pop(vertex)
        self._nr_vertices-=1
        for key in self._dict_bound.keys():
            if vertex in self._dict_bound[key]:
                self._dict_bound[key].remove(vertex)
                self._nr_edges-=1
        return True

    def degree(self, vertex):
        if vertex not in self._dict_bound.keys():
            return -1
        return len(self._dict_bound[vertex])

    def add_edge(self, vertex1, vertex2):

        if vertex1 not in self._vertices or vertex2 not in self._vertices:
            return False
        if vertex1 == vertex2:
            return False
        if vertex1 in self._dict_bound[vertex2] and vertex2 in self._dict_bound[vertex1]:
            return False

        self._dict_bound[vertex1].append(vertex2)
        self._dict_bound[vertex2].append(vertex1)
        self._nr_edges += 1
        return True

    def remove_edge(self, vertex1, vertex2):
        if vertex1 not in self._dict_bound[vertex2] or vertex2 not in self._dict_bound[vertex1]:
            return False
        if vertex1 not in self._vertices or vertex2 not in self._vertices:
            return False

        self._dict_bound[vertex1].remove(vertex2)
        self._dict_bound[vertex2].remove(vertex1)
        self._nr_edges -=1
        return True

    def find_if_edge(self,x,y):
        if x not in self._vertices or y not in self._vertices:
            return False
        if x in self._dict_bound[y] and y in self._dict_bound[x]:
            return True

    def make_copy(self):
        return copy.deepcopy(self)

    def breath_first_traversal(self, vertex,visited):
        queue_list = []
        connected = []
        queue_list.append(vertex)
        visited[vertex] = True
        while queue_list:
            x = queue_list.pop(0)
            connected.append(x)
            for i in self._dict_bound[x]:
                if visited[i] is False:
                    queue_list.append(i)
                    visited[i] = True
        return connected

    def find_connected_components(self):
        visited={}
        all_connected = []
        for vertex in self._vertices:
            visited[vertex] = False
        for vertex in self._vertices:
            if visited[vertex] is False:
                connected = self.breath_first_traversal(vertex,visited)
                all_connected.append(connected)
        return all_connected


def write_graph_to_file(graph: UndirectedGraph, file):
    file = open(file,"w")
    first_line = str(graph.nr_vertices) + ' ' + str(graph.nr_edges) + '\n'
    file.write(first_line)
    if len(graph.vertices) == 0 and len(graph.dict_bound) == 0:
        raise ValueError("There is nothing that can be written!")
    edges = []
    for vertex in graph.vertices:
        if len(graph.dict_bound[vertex]) != 0:
            for second_vertex in graph.dict_bound[vertex]:
                edge = (vertex,second_vertex)
                if (vertex,second_vertex) not in edge and (second_vertex,vertex) not in edges:
                    edges.append(edge)
        else:
            new_line = "{}\n".format(vertex)
            file.write(new_line)
    for edge in edges:
        new_line = "{} {}\n".format(edge[0],edge[1])
        file.write(new_line)
    file.close()

def read_graph_from_file(file):

    file = open(file,"r")
    line = file.readline()
    line = line.strip()
    vertices,edges=line.split(' ')
    graph = UndirectedGraph(int(vertices),0)
    line = file.readline().strip()
    while(len(line) > 0):
        line=line.split()
        if len(line) !=1 and int(line[0]) != int(line[1]):
            if int(line[0]) not in graph.dict_bound[int(line[1])]:
                graph._nr_edges+=1
                graph.dict_bound[int(line[1])].append(int(line[0]))
            if int(line[1]) not in graph.dict_bound[int(line[0])]:
                graph.dict_bound[int(line[0])].append(int(line[1]))\

        line = file.readline().strip()
    file.close()
    return graph
