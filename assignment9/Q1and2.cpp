#include <iostream>
#include <queue>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Graph {
public:
    int V;
    Node* adj[100];  

    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            adj[i] = NULL;     
    }

  
    void addEdge(int u, int v) {
        
        Node* newNode1 = new Node(v);
        newNode1->next = adj[u];
        adj[u] = newNode1;

        
        Node* newNode2 = new Node(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    
    void BFS(int start) {
        bool visited[100] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            
            Node* temp = adj[node];
            while (temp != NULL) {
                int neigh = temp->data;

                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    
    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        Node* temp = adj[node];
        while (temp != NULL) {
            int neigh = temp->data;

            if (!visited[neigh])
                DFSUtil(neigh, visited);

            temp = temp->next;
        }
    }

    
    void DFS(int start) {
        bool visited[100] = {false};
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
