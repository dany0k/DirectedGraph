#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <exception>

template <typename T>
struct Edge {
    T src, dest;
};

template <typename T>
class DirectedGraph {
private:
    int edgeCount;
    std::map<T, std::vector<T>> adjList;
public:
    DirectedGraph(std::vector<Edge<T>>& edges);
    int getEdgeCount();
    void removeEdge(Edge<T>& newEdge);
    void addEdge(Edge<T>& newEdge);
    std::map<T, std::vector<T>> &getAdjList();
};

template<typename T>
void DirectedGraph<T>::removeEdge(Edge<T> &edge) {
//    adjList.erase(std::find(adjList);
}


template<typename T>
void DirectedGraph<T>::addEdge(Edge<T> &newEdge) {
    if (newEdge.src > edgeCount) {
        adjList[newEdge.src] = {newEdge.dest};
    } else {
        adjList[newEdge.src].push_back(newEdge.dest);
    }
    edgeCount++;
}

template<typename T>
std::map<T, std::vector<T>> &DirectedGraph<T>::getAdjList() {
    return adjList;
}

template<typename T>
int DirectedGraph<T>::getEdgeCount() {
    return edgeCount;
}

template<typename T>
DirectedGraph<T>::DirectedGraph(std::vector<Edge<T>> &edges) {
    for (const Edge edge: edges) {
        adjList[edge.src].push_back(edge.dest);
    }
    edgeCount = adjList.size();
}

