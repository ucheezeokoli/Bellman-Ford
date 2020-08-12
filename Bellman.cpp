#include <iostream>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

struct Edge{
    int u;
    int v;
    int weight;
    Edge(int u, int v, int w): u(u), v(v), weight(w){}
};

bool Bellman_Ford(int V, int E, vector<Edge*> edges, int* price);

int main(){
    bool result = true;

    int V;
    int E;
    int u, v, w;

    int* price; //cost to each vertex
    vector<Edge*> edges;

    cin >> V;
    price = new int[V];
    cin >> E;

    for(int i = 0; i < E; i++){
        cin >> u;
        cin >> v;
        cin >> w;
        edges.push_back(new Edge(u, v, w));
    }

    result = Bellman_Ford(V, E, edges, price);

    if(!result){
        cout << "FALSE" << endl;
    }else{
        cout << "TRUE" << endl;
        for(int i = 0; i < V; i++){
            if(price[i] == INT_MAX){
                cout << "INFINITY" << endl;
            }else{
                cout << price[i] << endl;
            }
        }
    }

    for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); ++it){
        delete *it;
    }
    delete price;

    return 0;
}

bool Bellman_Ford(int V, int E, vector<Edge*> edges, int* price){
    int i, u , v, w;

    //init, src =0, rest='INFINITY'
    for(i = 0; i < V; i++){
        price[i] = INT_MAX;
    }
    price[0] = 0;

    //first pass Theta(VE)
    for(i = 1; i < V-1; i++){
        for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); it++){
            u = (*it)->u;
            v = (*it)->v;
            w = (*it)->weight;

            if(price[u] != INT_MAX && price[u] + w < price[v]){
                price[v] = price[u] + w;
            }
        }
    }

    //second pass, any cheaper path is a result of a negative cycle
    for(vector<Edge*>::iterator it = edges.begin(); it != edges.end(); it++){
        u = (*it)->u;
        v = (*it)->v;
        w = (*it)->weight;

        if(price[u] != INT_MAX && price[u] + w < price[v]){
            return false;
        }
    }

return true;
}
