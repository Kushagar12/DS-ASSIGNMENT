#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    int weight;
    Node* next;
    Node(int v,int w){
        value=v;
        weight=w;
        next=NULL;
    }
};
class Edge{
    public:
    int u,v,w;
};

class Graph{
    public:
    int V;
    Node* adj[100];
    int edgecount;
    Edge E[200];
    Graph(int vertex){
        V=vertex;
        edgecount=0;
        for (int i = 0; i < V; i++)
        {
            adj[i]=NULL;
        }   

    }

    void addEdge(int u,int v,int w){
            Node* newnode=new Node(v,w);
            newnode->next=adj[u];
            adj[u]=newnode;

            newnode=new Node(u,w);
            newnode->next=adj[v];
            adj[v]=newnode;

            E[edgecount].u=u;
            E[edgecount].v=v;
            E[edgecount].w=w;
            edgecount++;

        }

        int findparent(int parent[],int x ){
            if(parent[x]==x) return x;
            return parent[x]=findparent(parent,parent[x]);
        }
        void unionset(int parent[], int rank[],int x,int y){
            x=findparent(parent,x);
            y=findparent(parent,y);

            if(rank[x]>rank[y]){
                parent[y]=x;
            }
            else if(rank[y]>rank[x]) parent[x]=y;
            else{
                parent[y]=x;
                rank[x]++;
            }
        }

        void kruskal(){
            cout<<"MST: "<<endl;
            for (int i = 0; i < edgecount; i++)
            {
                for (int j = 0; j < edgecount-i-1; j++)
                {
                    if(E[j].w>E[j+1].w){
                        Edge temp=E[j];
                        E[j]=E[j+1];
                        E[j+1]=temp;
                    }
                }
                
            }

            int parent[100],rank[100];
            for (int i = 0; i < V; i++)
            {
                parent[i]=i;
                rank[i]=0;
            }

            int total=0;

            for (int i = 0; i < edgecount; i++)
            {
                int u=E[i].u;
                int v=E[i].v;
                int w=E[i].w;
                if(findparent(parent,u)!=findparent(parent,v)){
                    cout<<u<<"--"<<v<<"w="<<w<<endl;
                    total=total+w;
                    unionset(parent,rank,u,v);
                }
            }
            cout<<"Total weight: "<<total<<endl;
            
            

            
        }
        void prim(int start){
            int key[100],parent[100];
            bool inMST[100];
            for (int i = 0; i < V; i++)
            {
                inMST[i]=false;
                parent[i]=-1;
                key[i]=9999999;
            }
            key[start]=0;

            for (int count = 0; count < V-1; count++)
            {
                int u=-1,minval=9999;
                for (int i = 0; i < V; i++)
                {
                    if (!inMST[i] && key[i]<minval)
                    {
                        minval=key[i];
                        u=i;
                    }
                    
                }
                inMST[u]=true;
                Node* temp=adj[u];
                while(temp!=NULL){
                    int v=temp->value;
                    int w=temp->weight;
                    if(!inMST[v] && w<key[v]){
                        key[v]=w;
                        parent[v]=u;
                    }
                    temp=temp->next;
                }
                
            }
            cout<<"Mst: "<<endl;
            int sum=0;
            for (int i = 0; i <V; i++)
            {
                
                if(parent[i]!=-1){
                    cout<<parent[i]<<"--"<<i<<"w= "<<key[i]<<endl;
                    sum=sum+key[i];
                }
            }

            cout<<"Total Weight: "<<sum<<endl;
            
            
            
        }
};

int main(){

     Graph g(9);

   
    g.addEdge(0, 1, 4);  
    g.addEdge(0, 7, 8);  
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7);  
    g.addEdge(2, 8, 2);  
    g.addEdge(1, 2, 8);  
    g.addEdge(2, 5, 4);  
    g.addEdge(3, 4, 9);  
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2);  
    g.addEdge(6, 7, 1);  
    g.addEdge(6, 8, 6);  
    g.addEdge(7, 8, 7);  
    g.kruskal();
    g.prim(0);
return 0;
}