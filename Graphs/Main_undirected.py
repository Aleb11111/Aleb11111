from random import randint
from UndirectedGraph import UndirectedGraph, write_graph_to_file, read_graph_from_file

class UI:
    def __init__(self):
        self._graphs = []
        self._current = None

    def empty_graph(self):
        if self._current is None:
            self._current = 0
        graph = UndirectedGraph(0,0)
        self._graphs.append(graph)
        self._current = len(self._graphs)-1

    def generate_random(self,vertices,edges):
        if edges > vertices*(vertices - 1) // 2:
            raise ValueError("Too many edges!")
        graph = UndirectedGraph(vertices,0)
        i=0
        while i < edges:
            x = randint(0,vertices-1)
            y = randint(0,vertices - 1)
            if graph.add_edge(x,y):
                i+=1
        return graph

    def create_random_graph(self):
        vertices = int(input("Enter the number of vertices: "))
        edges = int(input("Enter the number of edges: "))
        graph = self.generate_random(vertices,edges)
        if self._current is None:
            self._current = 0
        self._graphs.append(graph)
        self._current = len(self._graphs) - 1

    def write_graph_file_ui(self):
        current_graph = self._graphs[self._current]
        write_graph_to_file(current_graph,"random_undirected.txt")

    def read_graph_ui(self):
        if self._current is None:
            self._current = 0
        graph=read_graph_from_file("random_undirected.txt")
        self._graphs.append(graph)
        self._current = len(self._graphs)-1

    def switch_graph_ui(self):
        print("You are on the graph number: {}".format(self._current))
        print("Available graphs: 0 - {}".format(str(len(self._graphs)-1)))
        number = int(input("Enter the graph number you want to switch to: "))
        if not 0 <= number < len(self._graphs):
            raise ValueError("Trying to switch to a non existing graph!")
        self._current = number

    def get_number_of_vertices(self):
        print("The number of vertices is: {}.".format(self._graphs[self._current].nr_vertices))

    def get_number_of_edges(self):
        print("The number of edges is {}".format(self._graphs[self._current].nr_edges))

    def list_all_bound(self):
        for x in self._graphs[self._current].parse_vertices():
            line = str(x) + " :"
            for y in self._graphs[self._current].parse_bound(x):
                line = line + " " + str(y)
            print(line)

    def list_bound(self):
        vertex = int(input("Enter the vertex: "))
        line = str(vertex) + " :"
        for y in self._graphs[self._current].parse_bound(vertex):
            line = line + " " + "({}, {})".format(str(vertex),str(y))
        print(line)

    def parse_all_vertices(self):
        for vertex in self._graphs[self._current].parse_vertices():
            print("{}".format(vertex))

    def add_vertex_ui(self):
        vertex = int(input("Enter the vertex: "))
        added = self._graphs[self._current].add_vertex(vertex)
        if added:
            print("Vertex added successfully!")
        else:
            print("Cannot add this vertex, it already exists!")

    def delete_vertex_ui(self):
        vertex = int(input("Enter the vertex to be deleted: "))
        delete = self._graphs[self._current].remove_vertex(vertex)
        if delete:
            print("Vertex deleted successfully!")
        else:
            print("Cannot delete the vertex, it is already missing!")

    def add_edge_ui(self):
        print("Add edge (an edge is(x,y))")
        x = int(input("Enter x = "))
        y = int(input("Enter y = "))
        added = self._graphs[int(self._current)].add_edge(x,y)
        if added:
            print("Edge added successfully!")
        else:
            print("Cannot add this edge!")

    def remove_edge_ui(self):
        print("Remove an edge (an edge is (x,y))")
        x = int(input("Enter x = "))
        y = int(input("Enter y = "))
        delete = self._graphs[self._current].remove_edge(x,y)
        if delete:
            print("Edge deleted successfully!")
        else:
            print("Cannot delete this edge!")

    def get_degree_ui(self):
        vertex = int(input("Enter the vertex: "))
        degree = self._graphs[self._current].degree(vertex)
        if degree == -1:
            print("The vertex does not exist!")
        else:
            print("The degree of the vertex {} is {}".format(vertex,degree))

    def check_edge(self):
        x=int(input("Enter x = "))
        y = int(input("Enter y = "))
        edge = self._graphs[self._current].find_if_edge(x,y)
        if edge is True:
            print("There is an edge!")
        else:
            print("There is not an edge!")

    def make_copy_ui(self):
        copy = self._graphs[self._current].make_copy()
        self._graphs.append(copy)

    def find_connected_components_ui(self):
        all_conected = self._graphs[self._current].find_connected_components()
        for index in range(len(all_conected)):
            print(all_conected[index])

    def print_menu(self):
        print("MENU:\n"
              "0. EXIT.\n"
              "1. Create a random graph with specified number of vertices and edges.\n"
              "2. Read the graph from a text file.\n"
              "3. Write the graph in a text file.\n"
              "4. Switch the graph.\n"
              "5. Get the number of vertices.\n"
              "6. Get the number of edges.\n"
              "7. List the bound edges of a vertex.\n"
              "8. List all the bound vertices.\n"
              "9. Add a vertex.\n"
              "10. Remove a vertex.\n"
              "11. Add an edge.\n"
              "12. Remove an edge.\n"
              "13. Get the degree of a vertex.\n"
              "14. Check if there is an edge between two given vertices.\n"
              "15. Make a copy of the graph.\n"
              "16. Get the connected components using a breadth-first traversal.\n")

def start():

    ui = UI()

    print("Welcome!")
    done = False
    ##ui.empty_graph()
    print("The current graph is an empty graph!")
    commands = {"1": ui.create_random_graph,"2":ui.read_graph_ui, "3":ui.write_graph_file_ui,"4":ui.switch_graph_ui,"5":ui.get_number_of_vertices,
                "6":ui.get_number_of_edges,"7": ui.list_bound, "8": ui.parse_all_vertices, "9": ui.add_vertex_ui, "10": ui.delete_vertex_ui, "11": ui.add_edge_ui,
                "12":ui.remove_edge_ui, "13": ui.get_degree_ui,"14":ui.check_edge, "15": ui.make_copy_ui, "16": ui.find_connected_components_ui}


    while not done:
        try:
            ui.print_menu()
            option = input("Choose an option: \n")
            if option == "0":
                done = True
                print("Good bye!")
            elif option in commands:
                commands[option]()
            else:
                print("Bad input!\n")
        except ValueError as ve:
            print(str(ve))


start()

