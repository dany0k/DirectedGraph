#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "DirectedGraph.h"

TEST(DirectedGraphTests, Subtest_1) {
    std::vector<Edge<int>> edges = {
         {0, 1},
    };
    Edge<int> newEdge = {0, 1};
    DirectedGraph<int> directedGraph(edges);
    directedGraph.removeEdge(newEdge);
    ASSERT_TRUE(directedGraph.getEdgeCount() == 0);
}

TEST(DirectedGraphTests, Subtest_2) {
    std::vector<Edge<int>> edges = {
         {0, 1},
    };
    Edge<int> newEdge = {0, 1};
    DirectedGraph<int> directedGraph(edges);
    directedGraph.addEdge(newEdge);
    ASSERT_TRUE(directedGraph.getEdgeCount() == 1);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}