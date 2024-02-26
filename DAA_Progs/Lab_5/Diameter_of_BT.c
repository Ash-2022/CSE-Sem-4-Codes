#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

typedef struct {
    Node * nodes[100];
    int tos;
} Stack;

void push(Stack * s, Node * x) {
    s->nodes[++(s->tos)] = x;
}

Node * pop(Stack * s) {
    return (s->nodes[(s->tos)--]);
}

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void createBT(Node ** tree) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));
    Stack nodeStack;
    nodeStack.tos = -1;
    iter = NULL;
    int x;
    int inp = 0;
    printf("Enter value of root ");
    scanf("%d",&x);
    iter = createNode(x);
    push(&nodeStack,iter);
    root = iter;
    *tree = iter;

    printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");

    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            push(&nodeStack,iter);
            iter->left = temp;
            iter = iter->left;
            printf("Moved left");
        }
        else if (inp == 2) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            Node * temp = createNode(x);
            push(&nodeStack,iter);
            iter->right = temp;
            iter = iter->right;
            printf("Moved right");
        }
        else if (inp == 3) {
            if (nodeStack.tos == 0) {
                printf("Already at root");
            }
            else {
                iter = pop(&nodeStack);
                printf("Moved up");
            }
        }
        else 
            inp = -1;
    } while(inp != -1);
}

int maximum(int a, int b) {
    return a > b ? a : b;
}

int height(Node * root) {
    if (root == NULL)
        return 0;
    return 1 + maximum(height(root->left), height(root->right));
}

int diameter(Node * root, int * h) {
    if (root == NULL)
        return 0; 

    int lHeight = 0, rHeight = 0;

    int lDia = diameter(root->left, &lHeight);
    int rDia = diameter(root->right, &rHeight);

    *h = maximum(lHeight, rHeight) + 1;

    int temp = maximum(lDia, rDia);

    return maximum(lHeight + rHeight + 1, temp);

}

void main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    int height = 0;
    printf("Diameter of the given binary tree is %d\n",diameter(tree,&height));
}