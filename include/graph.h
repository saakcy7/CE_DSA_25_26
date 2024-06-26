#include <iostream>
#include <vector>
#include <stdexcept>



class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;
        bool directed;

    public:

    Graph(int vertices, bool isDirected) : numVertices(vertices), directed(isDirected) 
    {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    bool isEmpty() const ;

    bool isDirected() const ;

    void addVertex() ;

    void addEdge(int vertex1, int vertex2) ;

    void removeVertex(int vertexToRemove) ;

    void removeEdge(int vertex1, int vertex2) ;

    int numvertices() const ;

    int numEdges() const ;

    int indegree(int vertex) const;

    int outdegree(int vertex) const;

    int degree(int vertex) const ;

    std::vector<int> neighbours(int vertex) const
    {
        if (vertex >= numVertices) 
        {
            throw std::invalid_argument("Vertex not found");
        }
        std::vector<int> neighbors;
        for (int i = 0; i < numVertices; ++i) 
        {
            if (adjMatrix[vertex][i] != 0) 
            {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
    
    bool isNeighbour(int vertex1, int vertex2) const ;
};
