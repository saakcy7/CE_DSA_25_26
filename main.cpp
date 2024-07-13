#include<vector>
#include<iostream>
#include"graph.h"
using namespace std;
int main()
{
    Graph g(5);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.printGraph();
    g.removeEdge(0,1);

    std::cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is the graph directed? " << (g.isDirected() ? "Yes" : "No") << std::endl;
    std::cout << "Number of vertices: " << g.numvertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    std::cout << "Indegree of vertex 4: " << g.indegree(3) << std::endl;
    std::cout << "Outdegree of vertex 4: " << g.outdegree(3) << std::endl;
    std::cout << "Degree of vertex 4: " << g.degree(3) << std::endl;

    std::cout << "Neighbours of vertex 2: ";
    vector<int> neighbours = g.getNeighbours(4);
    for(int i=0;i<neighbours.size();i++)
    {
        std::cout << neighbours[i] << " ";
    }
    std::cout << std::endl;

    std::cout<< "Is vertex 3 a neighbour of 4? " << (g.isNeighbour(2,3) ? "Yes" : "No") << std::endl;
    std::cout<< "Is vertex 3 a neighbour of 1? " << (g.isNeighbour(0,2) ? "Yes" : "No") << std::endl;
    
   
    return 0;
}