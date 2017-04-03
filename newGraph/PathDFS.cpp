//
//  PathDFS.cpp
//  newGraph
//
//  Created by ComarPers 922 on 2017/4/2.
//  Copyright © 2017年 ComarPers 922. All rights reserved.
//

#include "PathDFS.hpp"
#include <cstring>

void PathDFS::dfs(int v)
{
    visited[v] = true;
    typename myNewGraph::myNewGraphIterator it(graph,v);
    for(int temp = it.begin(); !it.end(); temp = it.next())
    {
        if(!visited[temp])
        {
            preVex[temp] = v;
            dfs(temp);
        }
    }
}
PathDFS::PathDFS(myNewGraph& g,int f): graph(g),from(f)
{
    visited = new bool[g.getNumVer()];
    preVex = new int[g.getNumVer()];
    
    for(int i = 0; i<g.getNumVer();i++)
    {
        visited[i] = false;
        preVex[i] = SUPERNUM;
    }
    dfs(f);
}
bool PathDFS::hasPath(int des)
{
    return visited[des];
}
void PathDFS::findPath(int des, std::vector<int>& nodes)
{
    if(hasPath(des))
    {
        std::stack<int> s;
        int current = des;
        s.push(des);
        while(preVex[current] != SUPERNUM)
        {
            s.push(preVex[current]);
            current = preVex[current];
        }
        while(!s.empty())
        {
            nodes.push_back(s.top());
            s.pop();
        }
    }
    else
    {
        std::cout<<"没路！！！"<<std::endl;
    }
}
void PathDFS::showPath(int des)
{
    std::vector<int> nodes;
    findPath(des, nodes);
    for (int i = 0; i<nodes.size(); i++)
    {
        std::cout<<nodes[i]<<(i+1==nodes.size()?"\n":"->");
    }
}
PathDFS::~PathDFS()
{
    delete [] visited;
    delete [] preVex;
}

