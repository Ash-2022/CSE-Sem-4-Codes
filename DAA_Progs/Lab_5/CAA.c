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

Node* CCA(Node* root, int p, int q) {
    if (root == NULL || root->val == p || root->val == q) {
        return root;
    }
    Node* left = CCA(root->left, p, q);
    Node* right = CCA(root->right, p, q);

    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { 
        return root;
    }

}


void main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    int inp;
    do{
        printf(" Enter 1 if you want to continue checking the ancestors , enter -1 to exit the program : ");
        scanf("%d" , &inp);
        if(inp == -1){
            break;
        }
        printf("Enter the node for  which the ancestors have to be found : ");
        int a , b;
        scanf("%d %d" , &a , &b);
        Node* result = CCA(tree , a , b);
        printf("The common Ancestor of %d and %d is %d \n" , a , b , result->val);
    }while(inp != -1);
}