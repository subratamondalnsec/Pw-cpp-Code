/*
code by Subrata Mondal
*/
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<vector<int> >uug;
int v; // no of vertices
void add_edge(int src,int dest){
    uug[src][dest]=1;
    uug[dest][src]=1;
}

void display(){
    for(int i=0;i<uug.size();i++){
        for(auto el : uug[i]){
            cout<<el <<"  ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    uug.resize(v,vector<int>(v,0));
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
}
/*
5 6
0 1 
0 2
1 2
1 3
2 4
3 4
*/
