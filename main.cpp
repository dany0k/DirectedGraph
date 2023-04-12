#include <iostream>
#include <vector>

#include "DirectedGraph.h"

std::string graphToString(DirectedGraph<int>& graph) {
    std::string res;
    std::string edges;
    for (auto & iter : graph.getAdjList())
    {
        for (const auto& edge : iter.second)
        {
            edges.append(std::to_string(edge) + ", ");
        }
        edges.resize(edges.size() - 2);
        res.append(std::to_string(iter.first) + " --> " + edges + "\n");
        edges = "";
    }
    return res;
}

std::string graphToString(DirectedGraph<std::string>& graph) {
    std::string res;
    std::string edges;
    for (auto & iter : graph.getAdjList())
    {
        for (const auto& edge : iter.second)
        {
            edges.append(edge + ", ");
        }
        edges.resize(edges.size() - 2);
        res.append(iter.first + " --> " + edges + "\n");
        edges = "";
    }
    return res;
}

int main() {
    std::cout << "==========IntDirectedGraph==========" << std::endl;
    std::vector<Edge<int>> edges = {
            {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    DirectedGraph<int> directedGraph(edges);
    std::cout << graphToString(directedGraph) << std::endl;
    Edge<int> newEdge1{8, 4};
    Edge<int> newEdge2{0, 1};
    Edge<int> edgeToRemove{0, 1};
    directedGraph.addEdge(newEdge1);
    directedGraph.addEdge(newEdge2);
    directedGraph.removeEdge(edgeToRemove);
    std::cout << graphToString(directedGraph) << std::endl;

    std::cout << "==========StringDirectedGraph==========" << std::endl;
    std::vector<Edge<std::string>> strEdges = {
            {"A", "B"}, {"B", "C"}, {"D", "A"}, {"C", "B"}, {"E", "C"}, {"F", "G"}, {"G", "H"}
    };
    DirectedGraph<std::string> strDirectedGraph(strEdges);
    std::cout << graphToString(strDirectedGraph) << std::endl;
    Edge<std::string> newStrEdge1{"H", "A"};
    Edge<std::string> newStrEdge2{"A", "B"};
    Edge<std::string> strEdgeToRemove{"A", "B"};
    strDirectedGraph.addEdge(newStrEdge1);
    strDirectedGraph.addEdge(newStrEdge2);
    strDirectedGraph.removeEdge(strEdgeToRemove);
    std::cout << graphToString(strDirectedGraph) << std::endl;
    return 0;
}
