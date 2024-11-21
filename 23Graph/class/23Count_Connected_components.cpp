/*
code by Subrata Mondal
*/
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
//uug undirected_unweighted_graph

vector<list<int> >uug;//linked list of vector

int v; // no of vertices
void add_edge(int src,int dest){
    uug[src].push_back(dest);
    uug[dest].push_back(src);
}
void dfs(int node,unordered_set<int>&visit){
    visit.insert(node);
    for(auto neighbour : uug[node]){
        if(! visit.count(neighbour)){
            dfs(neighbour,visit);
        }
    }
}
int Connected_components(){
    int result=0;
    unordered_set<int>visit;
    for(int i=0;i<v;i++){
        //go to every vertex
        //if from a vertex we can initialse a dfs we got one more cc
        if(visit.count(i)==0){
            result++;
            dfs(i,visit);
        }
    }
    return result;
}

int main(){
    cin>>v;
    uug.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    cout<<"total Connected components is : " <<Connected_components()<<endl;
    return 0;
}






/*
7
7
0 2 
0 1
1 5
2 5
2 3
3 6
6 4
*/
