#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data; 
    struct Node * next;
};

typedef struct Node Node;

struct Graph{
    Node** graph; // Pointer pointing to the address of the 1st Node of the Graph
};
typedef struct Graph Graph;

// Initializing/Creating a Node
Node* initializeNode(int val){
    Node* tempNode = (Node*) malloc(sizeof(Node));
    tempNode->data = val;
    tempNode->next = NULL;
    return tempNode;
}

void addEdge(Node* graph , Node* firstNode , Node* secondNode){
    
}

void main(){
    // Inputting the number of nodes from the user
    int n;
    printf("Enter the number of Nodes in the Graph : ");
    scanf("%d" , &n);

    // Initializing the graph
    Graph *g = (Graph*) malloc(sizeof(Graph));
    g->graph = (Node*) calloc(n , sizeof(Node));

    int inp;
    printf("Enter the value of the 1st Node in the Graph : ");
    scanf("%d" , &inp);
    Node* graphRoot = initializeNode(inp);
}