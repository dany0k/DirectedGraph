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
    int removeEdge(Edge<T>& edge);
    int addEdge(Edge<T>& newEdge);
    std::map<T, std::vector<T>> &getAdjList();
    void getMessage(const std::string &message);
};


template<typename T>
int DirectedGraph<T>::removeEdge(Edge<T> &edge) {
    for (auto& key: adjList) {
        if (key.first == edge.src) {
            std::vector<T> childs = adjList[edge.src];
            if (childs.size() == 1) {
                auto it = adjList.find(key.first);
                adjList.erase(it);
                getMessage("Successfully removed edge!");
                edgeCount--;
                return 0;
            }
            for (int i = 0; !childs.empty(); i++) {
                if (childs[i] == edge.dest) {
                    childs.erase(childs.begin() + i);
                    adjList[edge.src] = childs;
                    getMessage("Successfully removed edge!");
                    edgeCount--;
                    return 0;
                }
            }
        }
    }
    getMessage("No such edge!");
    return 1;
}


template<typename T>
int DirectedGraph<T>::addEdge(Edge<T> &newEdge) {
    for (auto& key: adjList) {
        if (key.first == newEdge.src) {
            for (auto& item: key.second) {
                if (item == newEdge.dest) {
                    getMessage("Already have this edge!");
                    return 1;
                } else {
                    adjList[newEdge.src].push_back(newEdge.dest);
                    getMessage("Added new edge!");
                    edgeCount++;
                    return 0;
                }
            }
        }
    }
    adjList[newEdge.src] = {newEdge.dest};
    edgeCount++;
    getMessage("Added new edge and vertex!");
    return 0;
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

template<typename T>
void DirectedGraph<T>::getMessage(const std::string& message) {
    std::cout << "===========Message===========\n" <<
        message << "\n============================="<< std::endl;
}

