#include<iostream>
using namespace std;

class node{
    public:
    int v;
    int w;
    node* next;
    node(int vertex,int weight){
        v=vertex;
        w=weight;
        next=NULL;


    }


};

class Graph{
    public:
    int V;
    node* adj[100];
    Graph(int v){
        V=v;

        for (int i = 0; i < V; i++)
        {
            adj[i]=NULL;
        }
        
    }

    void addEdge(int u,int v, int w){
        node* newnode=new node(v,w);
        newnode->next=adj[u];
        adj[u]=newnode;
    }
    void dijkstra(int start){
        int parent[100],dist[100];
        bool visited[100];

        for (int i = 0; i < V; i++)
        {
            parent[i]=-1;
            dist[i]=99999;
            visited[i]=false;
        }
        dist[start]=0;
        for (int count = 0; count < V; count++)
        {
            int u=-1,minval=9999;
            for (int i = 0; i < V; i++)
            {
                if(!visited[i] && dist[i]<minval){
                    minval=dist[i];
                    u=i;
                }
            }
            visited[u]=true;
            node* temp=adj[u];
            while(temp!=NULL){
                int v=temp->v;
                int w=temp->w;
                if(!visited[v]  && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                }
                temp=temp->next;
            }
            
        }

        cout<<"Shortest path from source: "<<start<<endl;
        for (int i = 0; i < V; i++)
        {
            if(parent[i]!=-1){
                cout<<"Vertex: "<<i<<" distance: "<<dist[i]<<" parent: "<<parent[i]<<endl;
            }
        }
        
        
        
    }
};

int main(){
    Graph g(5);

   

    g.addEdge(0, 1, 10); 
    g.addEdge(0, 3, 5);  
    g.addEdge(1, 2, 1);  
    g.addEdge(1, 3, 2);  
    g.addEdge(2, 4, 4);  
    g.addEdge(3, 1, 3);  
    g.addEdge(3, 2, 9);  
    g.addEdge(3, 4, 2);  
    g.addEdge(4, 0, 7);  
    g.addEdge(4, 2, 6);  

    g.dijkstra(0); 
return 0;
}