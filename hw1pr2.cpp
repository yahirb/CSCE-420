#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node{
  bool visited;
  int x;
  int y;

  Node(int x0, int y0)
  {
    visited = false;
    x = x0;
    y = y0;
  }
  Node& operator[] (int x) {
          return a[x];
      }
};

class Graph{
    private:
        int V;
        list<Node> *adj;
    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<Node>[V];
        }
        void addEdge(Node v, Node w);
        void BFS(Node s, bool visited[]);

};

void Graph::addEdge(Node v, Node w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

/*
 *  A recursive function to print BFS starting from s
 */
void Graph::BFS(Node s, bool visited[])
{
    list<Node> q;
    list<Node>::iterator i;
    visited[s] = true;
    q.push_back(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
  ifstream f;
  f.open("hw1pr1_data.txt");
  vector<Node> Nodes;
  int x;
  int y;
  while(f >> x >> y){
      Node n =  Node(x,y);
      Nodes.push_back(n);
  }


  return 0;
}
