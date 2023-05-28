#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class adjacencyMatrix {
private:
    int **graph;
    int vertices;
public:
    adjacencyMatrix() {
        //constructor
        graph = NULL;
        vertices = 0;
    }
    
    void initializeGraph(int x) {
        //initializing graph
        if (x < 1) {
            //in case of less than 1 value
            cout << "\n\nERROR!! Number of vertices is less than 1. Graph not made\n";
            graph = NULL;
            vertices = 0;
            return;
        }

        vertices = x;

        //allocation
        graph = new int* [vertices];
        for (int i = 0; i < vertices; i++)
            graph[i] = new int[vertices];

        //initializing to 0
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                graph[i][j] = 0;
    }

    void loadGraph() {
        //loading from file
        ifstream fin("graph.txt");
        int temp = 0;
        fin >> temp;

        if (temp < 1) {
            cout << "\n\nERROR!!Number of vertices is less than 1. Graph not made\n\n";
            return;
        }

        //initializing graph
        this->initializeGraph(temp);

        while (!fin.eof()) {
            int node1 = 0, node2 = 0;

            fin >> node1;
            fin >> node2;

            graph[node1 - 1][node2 - 1] = 1;
        }
    }


    void inDegree() {
        //printing total in degree
        int vertex;
        cout << "\nEnter vertix whose in Degree you want to find:\t"; cin >> vertex;
        if (vertex > vertices || vertex < 1) {
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }
        int count = 0;
        for (int i = 0; i < vertices; i++) {
            if (graph[i][vertex - 1] == 1)
                count++;
        }

        cout << "\n\nThe in-Degree of vertex " << vertex << " is " << count << endl << endl;
        return;
    }

    void outDegree() {
        //printing total out degree
        int vertex;
        cout << "\nEnter vertix whose out Degree you want to find:\t"; cin >> vertex;
       
        if (vertex > vertices || vertex < 1) {
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }
        int count = 0;

        for (int i = 0; i < vertices; i++)
            if (graph[vertex - 1][i] == 1)
                count++;
        cout << "\n\nThe out-Degree of vertex " << vertex << " is " << count << endl << endl;
        return;
    }

    void printNeighbourVertices() {
        //neighbouring vertices
        int vertex;
        cout << "\nEnter vertix whose neighbouring vertices you want to find:\t"; cin >> vertex;
        if (vertex > vertices || vertex < 1) {
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }

        cout << "\nNeighbouring Vertices of " << vertex << ": ";
        for (int i = 0; i < vertices; i++)
            if (graph[vertex - 1][i] == 1)
                cout << i + 1 << "\t";
        cout << endl << endl;
    }

    void displayConnection() {
        //checking connection
        int left, right;
        cout << "\nEnter left entry:\t"; cin >> left;
        cout << "\nEnter right entry:\t"; cin >> right;
        if ((left - 1 >= vertices) || (right - 1 >= vertices)) {
            cout << "\nInvalid Entries\n";
            return;
        }
        if (graph[left - 1][right - 1]) {
            cout << "\nEntered nodes are connected.\n";
            return;
        }
        cout << "\nEntered nodes are not connected\n";
        return;
    }

    void printMatrix() {
        //displaying matrix
        cout << " ";
        for (int i = 0; i < vertices; i++)
            cout << "\t" << i;
        cout << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << i << "\t";
            for (int j = 0; j < vertices; j++)
                cout << graph[i][j] << "\t";
            cout << endl << endl;
        }
    }
};

class adjacencyList {
private:
    list<int>* graph;
    int vertices;
public:
    adjacencyList() {
        //constructor
        vertices = 0;
        graph = NULL;
    }

    void initializeList(int count) {
        //initialising the list
        vertices = count;
        graph = new list<int>[vertices + 1];
    }

    void loadList() {
        //loading data from file
        ifstream fin("graph.txt");
        int temp = 0;

        fin >> temp;
        if (temp < 1) {
            cout << "ERROR: vertices are less than 1\n";
            return;
        }

        //initializing list
        this->initializeList(temp);

        while (!fin.eof()) {
            int node1 = 0, node2 = 0;

            fin >> node1;
            fin >> node2;

            //adding enteries
            graph[node1].push_back(node2);
        }
    }

    void DFS(int i, bool checker[]) {
        //using DFS
        checker[i] = true;

        list<int>::iterator j;
        for (j = graph[i].begin(); j != graph[i].end(); ++j)
            if (!checker[*j])//true if 1
                DFS(*j, checker);
    }

    bool checkConnection(int node1, int node2) {

        if (node1 < 0 || node1 > vertices)
            return false;

        if (node2 < 0 || node2 > vertices)
            return false;

        bool* Checker = new bool[vertices + 1];
        //initializing to false
        for (int i = 0; i < vertices + 1; i++)
            Checker[i] = false;

        //true in case of the 1
        DFS(node1, Checker);

        if (Checker[node2] == false)
            return false;

        return true;

    }

    bool checkConnection() {
        //wrapper to take values
        int left, right;
        cout << "\nEnter left entry:\t"; cin >> left;
        cout << "\nEnter right entry:\t"; cin >> right;
        if ((left - 1 >= vertices) || (right - 1 >= vertices)) {
            cout << "\nInvalid Entries\n";
            return false;
        }

        return checkConnection(left, right);
    }

    void outDegree() {
        //display out degree
        int vertex;
        cout << "\nEnter vertix whose in Degree vertices you want to find:\t"; cin >> vertex;

        if (vertex < 1 || vertex > vertices) {
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }
        cout << "\n\nThe out-Degree of vertex " << vertex << " is " << graph[vertex].size() << endl << endl;
        return;
    }

    void inDegree() {
        //display in degree
        int vertex;
        cout << "\nEnter vertix whose in Degree vertices you want to find:\t"; cin >> vertex;
        
        if (vertex > vertices || vertex < 1) {
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }
        
        int count = 0;

        for (int i = 1; i < vertices + 1; i++) {
            if (i != vertex) {
                list<int>::iterator j = graph[i].begin();
                for (; j != graph[i].end(); j++) {
                    if (*j == vertex)
                        count++;
                }
            }
        }
        cout << "\n\nThe in-Degree of vertex " << vertex << " is " << count << endl << endl;
        return;
    }

    void printNeighbourVertices() {
        //prinitng neighbours
        int vertex;
        cout << "\nEnter vertix whose neighbouring vertices you want to find:\t"; cin >> vertex;

        if (vertex > vertices || vertex < 1) {
            //in case of wrong enteries
            cout << "\n\nERROR!! Vertex index out of bounds\n";
            return;
        }

        cout << "Neighbours of " << vertex << ": ";
        list<int>::iterator i = graph[vertex].begin();
        while (i != graph[vertex].end()) {
            cout << *i << "\t";
            i++;
        }
        cout << "\n";
    }

    void printlist() {
        //printing list
        for (int vertex = 0; vertex < vertices + 1; vertex++) {
            list<int>::iterator i = graph[vertex].begin();
            while (i != graph[vertex].end()) {
                cout << *i << " ";
                i++;
            }
            cout << endl;
        }
    }

};

void main() {
    cout << "\n------------Q1------------\n";
    adjacencyMatrix Graph;
    Graph.loadGraph();
    Graph.printMatrix();
    Graph.inDegree();
    Graph.outDegree();
    Graph.printNeighbourVertices();
    Graph.displayConnection();
    cout << "\n------------Q2------------\n";
    adjacencyList List;
    List.loadList();
    List.printlist();
    List.inDegree();
    List.outDegree();
    List.printNeighbourVertices();
    if (List.checkConnection())
        cout << "\nConnected.\n";
    else
        cout << "\nNot Connected\n";
}
