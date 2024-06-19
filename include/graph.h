#include<vector>

class Graph {
    private:
        bool directed;
        std::vector<std::vector<int>>adjMatrix;
    public:
        Graph (int numVerticces, bool directed = true);
        bool isEmpty();
};