#include<vector>
class Graph{
    private:
        bool directed;
        std::vector<std::vector<int>> adjMatrix;

    public:
        Graph(int numVertices,bool directed=true);
        void addEdge(int u, int v);
        void removeEdge(int u, int v);
        bool isEdge(int u, int v);
        void printGraph();
        std::vector<int> getNeighbours(int u);
        int getNumVertices();
        int getNumEdges();
        bool isDirected();
        bool isEmpty();
        bool isFull();
};