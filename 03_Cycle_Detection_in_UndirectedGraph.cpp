#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool detectCycle(int src,vector<bool>&vis,int par){//0(V+E)
        vis[src]=true;

        list<int>neighbour=l[src];
        for(int v:neighbour){
            if(!vis[v]){
                if(detectCycle(v,vis,src)){
                    return true;
                }
            }
            else{
                // Cycle detection Condition
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }

    bool CycleDetection(){
        vector<bool>vis(5,false);
        return detectCycle(0,vis,-1);
    }
};
int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(0,3);
    graph.addEdge(3,4);

    cout<<graph.CycleDetection();
    return 0;
}