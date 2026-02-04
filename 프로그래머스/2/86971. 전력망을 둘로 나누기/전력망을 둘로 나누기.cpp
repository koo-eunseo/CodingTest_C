#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(int node, vector<vector<int>>& tree, vector<bool>& visited){
    
    visited[node]=true;
    int cnt = 1;
    for(int next : tree[node]){
        if(!visited[next])
            cnt+=dfs(next,tree,visited);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> tree(n+1);
    vector<vector<int>> tree2(n+1);
    vector<bool> visited(n,false);
    int answer = -1;
    
    for(auto wire : wires){
        int a = wire[0];
        int b = wire[1];
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    for(auto wire : wires){
        tree2=tree;
        vector<bool> visited(n,false);
        
        int a = wire[0];
        int b = wire[1];
        
        auto it1 = find(tree2[a].begin(),tree2[a].end(),b);
        if(it1!=tree[a].end())
            tree2[a].erase(it1);
        
        auto it2 = find(tree2[b].begin(),tree2[b].end(),a);
        if(it2!=tree[b].end())
            tree2[b].erase(it2);
        
        int cnt = dfs(a, tree2, visited);
        int diff = (n-cnt)-cnt;
        cout<<diff<<endl;
        diff<0? diff=diff*(-1):diff;
        if(answer==-1||answer>=diff)
            answer=diff;
    }
    
    return answer;
}

