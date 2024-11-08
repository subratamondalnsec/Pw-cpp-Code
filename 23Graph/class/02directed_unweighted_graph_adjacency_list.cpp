#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define dug directed_unweighted_graph

vector<list<int> >dug;
int v; // no of vertices
void add_edge(int src,int dest){
    dug[src].push_back(dest);
}

void display(){
    for(int i=0;i<dug.size();i++){
        cout<<i<<" -> ";
        for(auto el : dug[i]){
            cout<<el <<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    dug.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();


    /* vector of array method 2 */

    vector<int>va[v];//vector of array
    while(e--){
        int s,d;
        cin>>s>>d;
        va[s].push_back(d);
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
