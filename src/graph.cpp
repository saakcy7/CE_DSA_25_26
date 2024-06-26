#include"../include/graph.h"

#include <iostream>
#include <vector>
#include <stdexcept>


bool Graph::isEmpty() const 
{
    for (const auto& row : adjMatrix) 
    {
        for (int val : row) 
        {     
            if (val != 0) 
            {
                return false;
            }
        }
    }
    return true;
}

bool Graph::isDirected() const 
{
    return directed;
}

void Graph::addVertex() 
{
    numVertices++;
    for (auto& row : adjMatrix) 
    {
        row.push_back(0);
    }
    adjMatrix.push_back(std::vector<int>(numVertices, 0));
}

void Graph::addEdge(int vertex1, int vertex2) 
{
    if (vertex1 >= numVertices || vertex2 >= numVertices) 
    {
        throw std::invalid_argument("Vertex not found");
    }
        adjMatrix[vertex1][vertex2] = 1;
    if (!directed) 
    {
        adjMatrix[vertex2][vertex1] = 1;
    }
}

void Graph::removeVertex(int vertexToRemove) 
{
    if (vertexToRemove >= numVertices) 
    {
        throw std::invalid_argument("Vertex not found");
    }

    for (int i = 0; i < numVertices; ++i) 
    {
        adjMatrix[i].erase(adjMatrix[i].begin() + vertexToRemove);
    }
        adjMatrix.erase(adjMatrix.begin() + vertexToRemove);
        numVertices--;
}

void Graph::removeEdge(int vertex1, int vertex2) 
{
    if (vertex1 >= numVertices || vertex2 >= numVertices) 
    {
        throw std::invalid_argument("Vertex not found");
    }
    adjMatrix[vertex1][vertex2] = 0;
    if (!directed) 
    {
        adjMatrix[vertex2][vertex1] = 0;
    }
}

int Graph::numvertices() const 
{
    return numVertices;
}

int Graph::numEdges() const 
{
    int count = 0;
    for (const auto& row : adjMatrix) 
    {
        for (int val : row) 
        {
            count += val;
        }
    }    
    return directed ? count : count / 2;
}

int Graph::indegree(int vertex) const 
{
    if (vertex >= numVertices) 
    {
        throw std::invalid_argument("Vertex not found");
    }
    int inDeg = 0;
    for (const auto& row : adjMatrix) 
    {
        inDeg += row[vertex];
    }
    return inDeg;
}

int Graph::outdegree(int vertex) const 
{
    if (vertex >= numVertices)
    {
        throw std::invalid_argument("Vertex not found");
    }
    int outDeg = 0;
    for (int val : adjMatrix[vertex]) 
    {
        outDeg += val;
    }
    return outDeg;
}

int Graph::degree(int vertex) const 
{
    if (directed) 
    {
        return indegree(vertex) + outdegree(vertex);
    } 
    else 
    {
        return outdegree(vertex);
    }
}

bool Graph::isNeighbour(int vertex1, int vertex2) const 
{
    if (vertex1 >= numVertices || vertex2 >= numVertices) 
    {
        throw std::invalid_argument("Vertex not found");
    }
    return adjMatrix[vertex1][vertex2] != 0;
}


