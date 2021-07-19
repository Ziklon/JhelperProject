#pragma once

#include "../commons.h"

template<class Edge>
class Graph {
public:
    int vertexCount;
    int edgeCount;
private:
    vector<vector<Edge>> edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount), edges(vertexCount, vector<Edge>()) {}

    template<typename... Ts>
    int addEdge(int from, int to, Ts... args) {
      edges[from].emplace_back(to, edgeCount, args...);
      int directId = edges[from].size() - 1;
      if (Edge::reversable) {
        edges[to].push_back(edges[from][directId].reverseEdge(from));
        int revId = edges[to].size() - 1;
        edges[from][directId].setReverseId(revId);
        edges[to][revId].setReverseId(directId);
      }
      edgeCount++;
      return directId;
    }

    vector<Edge> &operator[](int at) {
      return edges[at];
    }

    void addVertices(int count) {
      vertexCount += count;
      edges.resize(vertexCount);
    }

    void clear() {
      edgeCount = 0;
      for (int i = 0; i < vertexCount; ++i) {
        edges[i].clear();
      }
    }
};