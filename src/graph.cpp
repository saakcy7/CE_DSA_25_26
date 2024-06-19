#include<iostream>
#include"graph.h"
#include<vector>
using namespace std;
Graph::Graph(int numVertices,bool directed)
{
    this->directed = directed;
    this->adjMatrix.resize(numVertices);
    for(int i=0;i<numVertices;i++)
    {
        this->adjMatrix[i].resize(numVertices);
    }
}
void Graph::addEdge(int u, int v)
{
    this->adjMatrix[u][v] = 1;
    if(!this->directed)
    {
        this->adjMatrix[v][u] = 1;
    }
}
void Graph::removeEdge(int u, int v)
{
    this->adjMatrix[u][v] = 0;
    if(!this->directed)
    {
        this->adjMatrix[v][u] = 0;
    }
}
void Graph::printGraph()
{
    for(int i=0;i<this->adjMatrix.size();i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<this->adjMatrix[i].size();j++)
        {
            if(this->adjMatrix[i][j])
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}