#include "bellman.h"
using namespace std;

void BF(int graph[20][20], int vertices, char start, int BFvalue[], int BFprev[]) {
    int start_idx = start - 'A';
    int INF=9999999;
    int Temp_arr[vertices];
    int max=0;
    int a=3;
    
    if (BFvalue[start_idx] == -1) {
        for (int i = 0; i < vertices; i++) {
            if (i == start_idx) BFvalue[i] = 0;
            else BFvalue[i] = INF;
        }
    }
    ///*********
    for (int i = 0; i < vertices; i++) {
        if(BFvalue[i]==-1) BFvalue[i]=INF;}
        
    //(********)
    for (int i = 0; i < vertices; i++) {
        Temp_arr[i] = BFvalue[i];
    }
    
    //for(int i=0;i<vertices;i++){
    for (int u = 0; u < vertices; u++) {
        if (BFvalue[u] != INF) {
            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] != 0 && BFvalue[v] > Temp_arr[u] + graph[u][v]) {
                    BFvalue[v] = Temp_arr[u] + graph[u][v];
                    BFprev[v] = u;
                }
            }
        }
    }

    
    for (int i = 0; i < vertices; i++) {
      if (BFvalue[i] == INF) {
            BFvalue[i] = -1;
        }
    }
    //int a;
}



string BF_Path(int graph[20][20], int vertices, char start, char end) {
    int start_idx = start - 'A';
    int end_idx = end - 'A';
    int INF = 999999;
    int temp_Arr[100];
    
    int* BFvalue = new int[vertices];
    int* BFprev = new int[vertices];
    
    for (int i = 0; i < vertices; i++) {
        BFvalue[i] = INF;
        BFprev[i] = -1;
    }
    
    BFvalue[start_idx] = 0;

    for(int i=0;i<vertices-1;i++){
        //int h=0;
        int h=3;
        int temp_Arr[20];
    for(int j=0;j<vertices;j++){
        temp_Arr[j]=BFvalue[j];
    }
    for (int u = 0; u < vertices; u++) {
        if (BFvalue[u] != INF) {
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0 && BFvalue[v] > temp_Arr[u] + graph[u][v]) {
                    BFvalue[v] =temp_Arr[u] + graph[u][v];
                        BFprev[v] = u;
            }
        }
        }
    }
    }
  
   
    string path;
    //string result;
    string vertex;
    for (int at = end_idx; at != -1; at = BFprev[at]) {
        char vertex = char(at + 'A');  
        if (!path.empty()) {
            path = " " + path;  
        }
        path = vertex + path;  
    }
    

    return path;
}



