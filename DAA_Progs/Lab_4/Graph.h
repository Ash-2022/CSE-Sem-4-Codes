#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int val;
} GraphNode;

typedef struct node {
    GraphNode gNode;
    struct node * next;
} Node ;

typedef struct {
    GraphNode nodes[100];
    int tos;
} Stack;

typedef struct {
    int n;
    Node ** adjLists;
    GraphNode * nodes;
} Graph ;

typedef struct {
    GraphNode * nodes;
    int front,rear;
} Queue;

// void insertEnd(Node **, GraphNode );
// Graph createGraph(int);

void insertEnd(Node ** list, GraphNode node) {
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->gNode.val = node.val;
    new_node->gNode.index = node.index;
    new_node->next = NULL;
    if (*list == NULL) 
        * list = new_node;
    else {
        Node * temp = (Node *) malloc(sizeof(Node));
        temp = *list;
        while (temp->next != NULL) 
            temp = temp->next;
        temp->next = new_node;
    }
}

Graph createGraph(int n) {
    Graph g;
    g.n = n;
    int i,x,j;
    g.nodes = (GraphNode *) malloc(n * sizeof(GraphNode));
    g.adjLists = (Node **) malloc (n * sizeof(Node *));
    int ** adjMat = (int **) calloc(n,sizeof(int *)); 
    for (i = 0; i < n; i++) {
        adjMat[i] = (int *) calloc(n,sizeof(int));
        g.adjLists[i] = NULL;
        g.nodes[i].index = i;
        printf("Enter the value for vertex %d ",(i+1));
        scanf("%d",&(g.nodes[i].val));
    }
    for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if (i==j) 
				adjMat[i][i] = 0;
			else {
				if (adjMat[i][j] != 1 && adjMat[i][j] != -1) {
					printf("Is vertex %d (val %d) connected to vertex %d (val %d) ? Type 1 if yes, 0 if no ", (i+1), g.nodes[i].val, (j+1), g.nodes[j].val);
					scanf("%d",&x);
					if (x == 1) {
						insertEnd(&(g.adjLists[i]),g.nodes[j]);
						insertEnd(&(g.adjLists[j]),g.nodes[i]);
						adjMat[i][j] = 1;
						adjMat[j][i] = 1;
					}
					else {
						adjMat[i][j] = -1;
						adjMat[j][i] = -1;
					}
				}
			}
		}
	}
    return g;
} 
