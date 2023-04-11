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

int main() {
    std::vector<Edge<int>> edges = {
            {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    DirectedGraph directedGraph(edges);
    Edge<int> newEdge{8, 4};
    Edge<int> newEdge1 {86, 3};
    Edge<int> newEdge2 {9, 3};
    directedGraph.addEdge(newEdge);
    directedGraph.addEdge(newEdge1);
    directedGraph.addEdge(newEdge2);
    std::cout << graphToString(directedGraph) << std::endl;
    std::cout << "Edge count: " << directedGraph.getEdgeCount() << std::endl;
    return 0;
}
