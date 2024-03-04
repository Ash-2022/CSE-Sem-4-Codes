#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data; 
    struct Node * next;
};

typedef struct Node Node;

struct Graph{
    Node** graph; // Pointer pointing to the address of the 1st Node of the Graph
    int V;
};
typedef struct Graph Graph;

// Initializing/Creating a Node
Node* initializeNode(int val){
    Node* tempNode = (Node*) malloc(sizeof(Node));
    tempNode->data = val;
    tempNode->next = NULL;
    return tempNode;
}

Node* inArrayOfAdjList(Graph* g , Node* x){
    for(int i = 0 ;i< g->V;i++){
        if(g->graph[i] == x){
            return i;
        }
    }
    return NULL;
}

void addEdge(Graph* graph , int firstNodeValue , int secondNodeValue){
    Node* firstNode = initializeNode(firstNodeValue);
    Node* secondNode = initializeNode(secondNodeValue);
    int i = 0;
    if(graph == NULL){
        graph->graph[i] = firstNode;
        i++;
        graph->graph[i] = secondNode;
        i++;
    }
    else{
        inArrayOfAdjList(graph , )
    }
}

void displayGraph(Graph* g){
    Graph * temGraph = g;
    for(int i = 0; i < temGraph->V; i ++){
        while(temGraph->graph[i]->next != NULL){
            printf("%d  --> " , temGraph->graph[i]->data);
            temGraph->graph[i] = temGraph->graph[i]->next;
        }
    }
}

void main(){
    // Inputting the number of nodes from the user
    int n;
    printf("Enter the number of Nodes in the Graph : ");
    scanf("%d" , &n);

    // Initializing the graph
    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->graph = (Node**) calloc(n , sizeof(Node*));
    g->V = n;

    int inp;
    printf("Enter the value of the 1st Node in the Graph : ");
    scanf("%d" , &inp);
    // Node* graphRoot = initializeNode(inp);
    addEdge(g , 5 , 6);
    displayGraph(g);
}