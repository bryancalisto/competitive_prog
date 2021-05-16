#include <bits/stdc++.h>

using namespace std;

/*
Vertices = nodos
Aristas = conectores
*/
class Graph
{
  int vertices;
  list<int> *adj;
  bool isCyclicUtil(int vertice, bool vertices[], bool *recursionStack);

public:
  Graph(int vertices);
  void addEdge(int u, int v);
  bool isCyclic();
};

Graph::Graph(int vertices)
{
  this->vertices = vertices;
  this->adj = new list<int>[vertices];
}

void Graph::addEdge(int u, int v)
{
  adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int vertice, bool visited[], bool *recursionStack)
{
  if (!visited[vertice])
  {
    visited[vertice] = true;
    recursionStack[vertice] = true;

    list<int>::iterator i;

    for (i = adj[vertice].begin(); i != adj[vertice].end(); i++)
    {
      if ((!visited[*i] && isCyclicUtil(*i, visited, recursionStack)) || recursionStack[*i])
      {
        return true;
      }
    }
  }

  recursionStack[vertice] = false;
  return false;
}

bool Graph::isCyclic()
{
  bool *visited = new bool[vertices];
  bool *recursionStack = new bool[vertices];

  for (int i = 0; i < vertices; i++)
  {
    visited[i] = false;
    recursionStack[i] = false;
  }

  for (int i = 0; i < vertices; i++)
  {
    if (isCyclicUtil(i, visited, recursionStack))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int n, m, i;

  cin >> n;
  cin >> m;

  Graph g(n);

  for (i = 0; i < m; i++)
  {
    int u;
    int v;

    cin >> u;
    cin >> v;

    g.addEdge(u, v);
  }

  if (g.isCyclic())
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }

  return 0;
}