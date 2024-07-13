#include<vector>
class Graph{
    private:
        bool directed;
        std::vector<std::vector<int>> adjMatrix;

    public:
        Graph(int numVertices,bool directed=true);
        void addEdge(int u, int v);
        void addVertex();
        void removeVertex(int vertexToRemove);
        void removeEdge(int u, int v);
        int numvertices();
        int numEdges() const;
        int indegree(int vertex);
        int outdegree(int vertex);
        int degree(int vertex);
        bool isEdge(int u, int v);
        void printGraph();
        bool isNeighbour(int u, int v);
        std::vector<int> getNeighbours(int u);
        bool isDirected();
        bool isEmpty();
};