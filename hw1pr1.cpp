#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;


struct Node{
  int x;
  int y;

  Node(int x0, int y0)
  {
    x = x0;
    y = y0;
  }
};


int main(){
  ifstream f;
  f.open("hw1pr1_data.txt");
  vector<Node> Nodes;
  int x;
  int y;
  int path = 0;
  double totalDistance = 0;
  int curr = 0;
  int testNode = 0;
  int prev = -1;
  while(f >> x >> y){
      Node n =  Node(x,y);
      Nodes.push_back(n);
  }

  for(int i = 0; i < Nodes.size(); i++){
      path = 0;
      testNode = curr;
      float distance = 1000000000000;
      while(path < Nodes.size()){
        if(path != testNode){
          double testDistance = sqrt(pow((Nodes[testNode].x - Nodes[path].x),2) + pow((Nodes[testNode].y - Nodes[path].y),2));
          if(testDistance < distance && Nodes[path].x != Nodes[prev].x && Nodes[path].y != Nodes[prev].y && (!Nodes[path].visited || path == 0)){
            distance = testDistance;
            curr = path;
          }
        }
        path++;
      }
      totalDistance += distance;
      if(curr == 0){
        break;
      }
      Nodes[curr].visited = true;
      prev = testNode;
  }

  for(int i = 0; i < Nodes.size(); i++){
    cout << Nodes[i].x << " " << Nodes[i].y << endl;
  }

  cout << totalDistance << endl;
}
