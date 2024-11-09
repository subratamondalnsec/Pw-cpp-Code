/*
code by Subrata Mondal
*/
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<int ,int > >uug;
int v; // no of vertices
void add_edge(int src,int dest,int wt){
    uug[src][dest]=wt;
}

void display(){
    for(int i=0;i<uug.size();i++){
        cout<<i<<" -> ";
        for(auto el : uug[i]){
             cout<<"("<<el.first <<" , " <<el.second<<") , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    uug.resize(v,unordered_map<int ,int>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
}
/*
7 7
0 2 2
0 1 1
1 5 3 
2 5 2 
2 3 6
3 6 2
6 4 4 
*/
