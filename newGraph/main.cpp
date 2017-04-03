//
//  main.cpp
//  newGraph
//
//  Created by ComarPers 922 on 2017/4/2.
//  Copyright © 2017年 ComarPers 922. All rights reserved.
//

#include <iostream>
#include "myNewGraph.hpp"
#include "PathDFS.hpp"
#include "PathBFS.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    const int numVex = 7;
    myNewGraph graph(numVex);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 5);
    graph.addEdge(0, 6);
    
    graph.addEdge(3, 5);
    graph.addEdge(3, 4);
    
    graph.addEdge(4, 6);
    graph.addEdge(4, 5);
    
    for(int i = 0; i < numVex; i++)
    {
        myNewGraph::myNewGraphIterator it(graph,i);
        cout << "vertex " << i << ": ";
        for(int temp = it.begin();!it.end();temp = it.next())
        {
            cout << temp<<'\t';
        }
        cout << endl;
    }
    PathDFS dfs(graph,0);
    dfs.showPath(6);
    
    PathBFS bfs(graph,0);
    bfs.showPath(4);
    return 0;
}
