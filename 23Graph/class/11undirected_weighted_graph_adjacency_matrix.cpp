#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

vector<vector<int> >uug;
int v; // no of vertices
void add_edge(int src,int dest,int wt){
    uug[src][dest]=wt;
    uug[dest][src]=wt;
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
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
}
/*
5 6
0 1 4
0 2 10
1 2 7
1 3 8
2 4 4
3 4 11
*/