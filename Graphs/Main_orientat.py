from GraphDomain import OrientedGraph, write_graph_to_file, read_graph_from_file, copy_graph_to_file
import random

class UI:

    def __init__(self):
        self._graphs=[]
        self._graph_current=None

    def add_empty_graph(self):
        if self._graph_current == None:
            self._graph_current = 0
        graph = OrientedGraph(0,0)
        self._graphs.append(graph)
        self._graph_current=len(self._graphs)-1

    def generate_random(selfself,vertices,edges):
        if edges>vertices*vertices:
            raise ValueError("Too many vertices")
        graph =OrientedGraph(vertices,0)
        index=0
        while index<edges:
            v1=random.randint(0,vertices-1)
            v2=random.randint(0,vertices-1)
            cost = random.randint(0,999)
            if graph.add_edge(v1,v2,cost):
                index+=1
        return graph
    def create_random_graph(self):
        vertices=int(input("How many vertices will the graph have? Type a number:"))
        edges=int(input("How many edges? Type a number:"))
        graph = self.generate_random(vertices,edges)
        if self._graph_current == None:
            self._graph_current =0
        self._graphs.append(graph)
        self._graph_current = len(self._graphs) - 1
        return graph

    def write_graph(self):
        current_g=self._graphs[self._graph_current]
        outfile=input("Enter file name>")
        write_graph_to_file(current_g,outfile)

    def read_graph(self):
        filename= input("Enter the file name: ")
        if self._graph_current is None:
            self._graph_current=0
        graph=read_graph_from_file(filename)
        self._graphs.append(graph)
        self._graph_current = len(self._graphs) - 1

    def switch_graphs(self):
        print("You have {} graphs available".format(str(len(self._graphs)-1)),end=" ")
        print("You see now graph number {}.".format(self._graph_current))
        number = int(input("Enter the number of the graph you want to switch to. >"))
        if not 0<=number<len(self._graphs):
            raise ValueError("Trying to access a non existing graph. Cannot perform the action.")
        self._graph_current = number

    def number_vertices_ui(self):
        print("The number of vertices is: {}.".format(self._graphs[self._graph_current].number_of_vertices))

    def number_edges(self):
        print("The number of edges is: {}.".format(self._graphs[self._graph_current].number_of_edges))

    def list_outbound(self):
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_outbound(vertex):
                line = line + " " + str(y)
            print(line)

    def list_inbound(self):
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_inbound(vertex):
                line = line + " " + str(y)
            print(line)

    def list_cost(self):
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_inbound(vertex):
                line = line + " " + "({},{})={}".format(str(y),str(vertex),self._graphs[self._graph_current].parse_costs())
            print(line)

    def parse_all_vertices(self):
        for vertex in self._graphs[self._graph_current].parse_vertices():
            print("{}".format(vertex))

    def add_vert_ui(self):
        vertex=int(input("Enter a new vertex >"))
        is_added=self._graphs[self._graph_current].add_vertex(vertex)
        if is_added:
            print("Vertex added successfully.")
        else:
            print("Cannot add this vertex, this vertex already in the graph.")

    def add_edge_ui(self):
        print("To add an edge specify the 2 vertices and the cost: ")
        x=int(input("Vertex 1>"))
        y=int(input("Vertex 2>"))
        cost=int(input("The cost>"))
        is_added=self._graphs[self._graph_current].add_edge(x,y,cost)
        if is_added:
            print("Edge added successfully")
        else:
            print("This edge cannot be added")
    def delette_vertex_ui(self):
        vertex=int(input("Enter the vertex you want to remove>"))
        is_deleted=self._graphs[self._graph_current].delete_vertex(vertex)
        if is_deleted:
            print("The vertex was deleted successfully")
        else:
            print("That vertex can't be delete.")

    def delete_edge_ui(self):
        print("In order to delete an edge you need to enter the vertices>")
        x=int(input("Vertex 1>"))
        y=int(input("Vertex 2>"))
        is_deleted=self._graphs[self._graph_current].delete_edge(x,y)
        if is_deleted:
            print("The edge was successfully deleted.")
        else:
            print("The edge could not be deleted.")

    def modify_cost_ui(self):
        print("In order to modify an edge you need to enter the vertices and the new cost>")
        x = int(input("Vertex 1>"))
        y = int(input("Vertex 2>"))
        cost = int(input("The cost>"))
        is_modified=self._graphs[self._graph_current].modify_cost(x,y,cost)
        if is_modified:
            print("Cost modified successfully.")
        else:
            print("The cost could not be changed.")

    def check_edge(self):
        x = int(input("Vertex 1>"))
        y = int(input("Vertex 2>"))
        is_edge=self._graphs[self._graph_current].is_edge
        if is_edge is not False:
            print("({},{}) is an edge with the cost {}".format(x,y,is_edge))
        else:
            print("({},{}) is not an edge".format(x,y))

    def inbound_of_an_vertex(self):
        vertex = int(input("Enter the vertex> "))
        line = str(vertex) + ":"
        for i in self._graphs[self._graph_current].parse_inbound(vertex):
            line = line + " " + "({},{})".format(str(i), str(vertex))
        print(line)

    def outbound_of_an_vertex(self):
        vertex = int(input("Enter the vertex> "))
        line = str(vertex) + ":"
        for i in self._graphs[self._graph_current].parse_outbound(vertex):
            line = line + " " + "({},{})".format(str(vertex), str(i))
        print(line)

    def out_degree_ui(self):
        vertex=int(input("Enter the vertex>"))
        indegree=self._graphs[self._graph_current].get_degree_in(vertex)
        if indegree == -1:
            print("The vertex is not in the graph.")
        else:
            print("The degree of the vertex {} is {}.".format(vertex,indegree))

    def in_degree_ui(self):
        vertex = int(input("Enter the vertex>"))
        outdegree=self._graphs[self._graph_current].get_degree_out(vertex)
        if outdegree == -1:
            print("The vertex is not in the graph.")
        else:
            print("The degree of the vertex {} is {}.".format(vertex,outdegree))

    def copy_current_graph_ui(self):
        copy=self._graphs[self._graph_current].make_copy()
        self._graphs.append(copy)
        self._graph_current+=1
        copy_graph_to_file(copy,"copy_file.txt")

    def lowest_cost_path_ford(self):

        start = int(input("Start node: "))
        end = int(input("End node: "))

        path = self._graphs[self._graph_current].ford_lowest_cost_walk(start,end)

        print(path)


    def all_parses(self):
        print("The outbound: ")
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_outbound(vertex):
                line = line + " " + str(y)
            print(line)

        print("The inbound: ")
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_inbound(vertex):
                line = line + " " + str(y)
            print(line)

        print("The cost inbound: ")
        for vertex in self._graphs[self._graph_current].parse_vertices():
            line = str(vertex) + " :"
            for y in self._graphs[self._graph_current].parse_inbound(vertex):
                line = line + " " +"({},{})=".format(str(y),str(vertex))
                line = line+" {}".format(self._graphs[self._graph_current].get_cost(y,vertex))
            print(line)

    def topo_sort_ui(self):
        sorted_list = self._graphs[self._graph_current].base_topo_sort()
        if len(sorted_list) == 0:
            print("The current graph is not a DAG!")
        else:
            print("The graph is a DAG and we have the following topological sorting: ")
            for vertex in sorted_list:
                print(str(vertex), end=' ')
            print("\n")
            vertex_begin = int(input("Enter source vertex = "))
            vertex_end = int(input("Enter end vertex = "))
            if vertex_begin not in self._graphs[self._graph_current].parse_vertices():
                raise ValueError("One vertex/ both vertices entered might not exist.")
            else:
                distance, prev = self._graphs[self._graph_current].highest_cost_path(vertex_begin, vertex_end)
                if distance == float("-inf"):
                    raise ValueError("There is no walk from {} to {}".format(vertex_begin, vertex_end))
                path = []
                vertex = vertex_end
                path.append(vertex)
                while prev[vertex] != -1:
                    path.append(prev[vertex])
                    vertex = prev[vertex]
                print("The cost of the highest cost path is: {}".format(str(distance)))
                # print the path
            print("The path is: ", end=' ')
            for index in range(len(path) - 1, -1, -1):
                print(path[index], end=' ')
            print("\n")

def Menu():
    print("Menu:")
    print("0. Exit.")
    print("1. Get the number of vertices.")
    print("2. Parse the set of vertices.")
    print("3. Find out if there is an edge between two given vertices.")
    print("4. Get the in degree of a specified vertex.")
    print("5. Get the out degree of a specified vertex.")
    print("6. Parse the set of outbound edges of a specified vertex.")
    print("7. Parse the set of inbound edges of a specified vertex.")
    print("8. Modify the information of an edge.")
    print("9. Add a vertex.")
    print("10. Add an edge.")
    print("11. Delete a vertex.")
    print("12. Delete an edge.")
    print("13. Copy graph.")
    print("14. Read from text file.")
    print("15. Write in the text file.")
    print("16. Create a random graph.")
    print("17. Switch graph.")
    print("18. Get number of edges.")
    print("19. List outbound of the graph.")
    print("20. List inbound of the graph.")
    print("21. List the edges and their costs.")
    print("22. All parses.")
    print("23. Lowest price path using Ford's algorithm.")
    print("24. Find out if the graph is a DAG and compute the highest path.")

def start():

    ui=UI()
    Menu()
    print("Welcome!")
    ui.add_empty_graph()
    print("The current graph is empty")

    commands={"1":ui.number_vertices_ui,"2":ui.parse_all_vertices,"3":ui.check_edge,
              "4":ui.in_degree_ui,"5":ui.out_degree_ui,"6":ui.outbound_of_an_vertex,
              "7":ui.inbound_of_an_vertex,"8":ui.modify_cost_ui,"9":ui.add_vert_ui,"10":ui.add_edge_ui,
              "11":ui.delette_vertex_ui,"12":ui.delete_edge_ui,"13":ui.copy_current_graph_ui,
              "14":ui.read_graph,"15":ui.write_graph,"16":ui.create_random_graph,
              "17":ui.switch_graphs,"18":ui.number_edges,"19":ui.list_outbound,"20":ui.list_inbound,"21":ui.list_cost,"22":ui.all_parses,"23": ui.lowest_cost_path_ford,"24":ui.topo_sort_ui}

    done=False
    while not done:
        try:
            option=input("Choose an option from the menu> \n")
            if option=="0":
                done = True
                print("Good bye!")
            elif option in commands:
                commands[option]()
            else:
                print("Not a valid option.")
        except ValueError as ve:
            print(str(ve))
        except FileNotFoundError as fnfe:
            print(str(fnfe).strip("[Errno 2] "))




start()
