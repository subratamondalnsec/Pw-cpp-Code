
/*
code by Subrata Mondal
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define uug undirected_unweighted_graph

vector<list<int> >uug;//linked list of vector

int v; // no of vertices
void add_edge(int src,int dest){
    uug[src].push_back(dest);
    uug[dest].push_back(src);
}

void display(){
    for(int i=0;i<uug.size();i++){
        cout<<i<<" -> ";
        for(auto el : uug[i]){
            cout<<el <<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    uug.resize(v,list<int>());
    int e;
    cin>>e;
    // while(e--){
    //     int s,d;
    //     cin>>s>>d;
    //     add_edge(s,d);
    // }
    // display();

    /* vector of array method 2 */

    vector<int>va[v];//vector of array
    while(e--){
        int s,d;
        cin>>s>>d;
        va[s].push_back(d);
        va[d].push_back(s);
    }
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto el : va[i]){
            cout<<el <<" , ";
        }
        cout<<endl;
    }
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
