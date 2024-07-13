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
bool Graph::isEmpty()
{
    return this->adjMatrix.size()==0;
    
}
bool Graph::isDirected()
{
    return this->directed;
}
void Graph::addVertex()
{
    for(int i=0;i<this->adjMatrix.size();i++)
    {
        this->adjMatrix[i].push_back(0);
    }
    this->adjMatrix.push_back(vector<int>(this->adjMatrix.size()+1,0));
}

void Graph::addEdge(int u, int v)
{
    this->adjMatrix[u][v] = 1;
    if(!this->directed)
    {
        this->adjMatrix[v][u] = 1;
    }
}

void Graph::removeVertex(int vertexToRemove)
{
    for(int i=0;i<this->adjMatrix.size();i++)
    {
        this->adjMatrix[i].erase(this->adjMatrix[i].begin()+vertexToRemove);
    }
    this->adjMatrix.erase(this->adjMatrix.begin()+vertexToRemove);
}

void Graph::removeEdge(int u, int v)
{
    this->adjMatrix[u][v] = 0;
    if(!this->directed)
    {
        this->adjMatrix[v][u] = 0;
    }
}

int Graph::numvertices()
{
    return this->adjMatrix.size();
}

int Graph::numEdges() const
{
    int count = 0;
    for(int i=0;i<this->adjMatrix.size();i++)
    {
        for(int j=0;j<this->adjMatrix[i].size();j++)
        {
            if(this->adjMatrix[i][j])
            {
                count++;
            }
        }
    }
    if(!this->directed)
    {
        count = count/2;
    }
    return count;
}

int Graph::indegree(int vertex)
{
    int count = 0;
    for(int i=0;i<this->adjMatrix.size();i++)
    {
        if(this->adjMatrix[i][vertex])
        {
            count++;
        }
    }
    return count;
}

int Graph::outdegree(int vertex)
{
    int count = 0;
    for(int i=0;i<this->adjMatrix[vertex].size();i++)
    {
        if(this->adjMatrix[vertex][i])
        {
            count++;
        }
    }
    return count;
}

int Graph::degree(int vertex)
{
    return this->indegree(vertex)+this->outdegree(vertex);
}

bool Graph::isNeighbour(int u,int v)
{
    return this->adjMatrix[u][v];

}

std::vector<int> Graph::getNeighbours(int u)
{
    vector<int> neighbours;
    for(int i=0;i<this->adjMatrix[u].size();i++)
    {
        if(this->adjMatrix[u][i])
        {
            neighbours.push_back(i);
        }
    }
    return neighbours;
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