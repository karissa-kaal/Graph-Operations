# Graph Operations

This repository contains C++ code for performing various operations on a graph. The code supports two representations of a graph: adjacency matrix and adjacency list.

### Adjacency Matrix

The `adjacencyMatrix` class provides functions to initialize a graph using an adjacency matrix, load graph data from a file, calculate the in-degree and out-degree of a vertex, find neighboring vertices of a vertex, check if two vertices are connected, and print the adjacency matrix.

#### Usage

```cpp
adjacencyMatrix Graph;
Graph.loadGraph();
Graph.printMatrix();
Graph.inDegree();
Graph.outDegree();
Graph.printNeighbourVertices();
Graph.displayConnection();
```

### Adjacency List

The `adjacencyList` class provides functions to initialize a graph using an adjacency list, load graph data from a file, perform depth-first search (DFS) to check if two vertices are connected, calculate the in-degree and out-degree of a vertex, find neighboring vertices of a vertex, and print the adjacency list.

#### Usage

```cpp
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
```

### Instructions

1. Ensure that the graph data is stored in a file named "graph.txt".
2. Update the file with the appropriate graph data in the format specified below.

#### Graph Data File Format

The graph data file should contain the number of vertices on the first line, followed by pairs of vertices indicating the edges. Each pair of vertices should be on a separate line, with a space separating them.

Example:

```
5
1 2
1 3
2 4
3 4
4 5
```

In the above example, the graph has 5 vertices and the edges are as follows:
- Vertex 1 is connected to vertices 2 and 3.
- Vertex 2 is connected to vertex 4.
- Vertex 3 is connected to vertex 4.
- Vertex 4 is connected to vertices 5.

Note: The vertices are 1-indexed.

Feel free to use this code to perform operations on graphs represented using an adjacency matrix or adjacency list.
