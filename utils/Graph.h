#include <bits/stdc++.h>

using namespace std;

class Graph
{
  int V;                // number of vertices
  list<int> *adjacents; // List of adjacent edges

public:
  Graph(int V);

  void addEdge(int u, int v);
  void DFS(int vertice);
  void DFS_aux(bool *DFS_visited, int vertice);
  void BFS(int source); // Make the implementation you need
};

Graph::Graph(int V)
{
  this->V = V;
  adjacents = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
  adjacents[u].push_back(v);
}

// Wrapper for DFS_visited (to not make DFS_visited a class global array)
void Graph::DFS(int vertice)
{
  bool *DFS_visited = new bool[V];
  DFS_aux(DFS_visited, vertice);
}

void Graph::DFS_aux(bool *DFS_visited, int vertice)
{
  list<int>::iterator it;
  DFS_visited[vertice] = true;

  for (it = adjacents[vertice].begin(); it != adjacents[vertice].end(); it++)
  {
    if (!DFS_visited[*it])
    {
      DFS_aux(DFS_visited, *it);
    }
  }
}

void Graph::BFS(int source)
{
  bool *visited = new bool[V];
  list<int> queue;
  list<int>::iterator it;

  for (int i = 0; i < V; i++)
  {
    visited[i] = false;
  }

  visited[source] = true;
  queue.push_back(source);

  while (!queue.empty())
  {
    source = queue.front();
    queue.pop_front();

    for (it = adjacents[source].begin(); it != adjacents[source].end(); it++)
    {
      if (!visited[*it])
      {
        visited[*it] = true;
        queue.push_back(*it);
      }
    }
  }

  delete visited;
}
