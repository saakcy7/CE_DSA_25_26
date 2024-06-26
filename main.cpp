#include"./include/graph.h"

#include <iostream>
#include <vector>
#include <stdexcept>



int main() {
    Graph g(5, true); // Create a directed graph with 5 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    // Display graph properties
    std::cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is the graph directed? " << (g.isDirected() ? "Yes" : "No") << std::endl;
    std::cout << "Number of vertices: " << g.numvertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    // Display degree information
    std::cout << "Indegree of vertex 2: " << g.indegree(2) << std::endl;
    std::cout << "Outdegree of vertex 2: " << g.outdegree(2) << std::endl;
    std::cout << "Degree of vertex 2: " << g.degree(2) << std::endl;

    // Display neighbors
    std::vector<int> neighbors = g.neighbours(2);
    std::cout << "Neighbours of vertex 2: ";
    for (int neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    // Check if vertices are neighbours
    std::cout << "Is vertex 1 a neighbour of vertex 2? " << (g.isNeighbour(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Is vertex 3 a neighbour of vertex 2? " << (g.isNeighbour(3, 2) ? "Yes" : "No") << std::endl;

    return 0;
}


