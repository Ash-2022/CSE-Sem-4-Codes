#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

void AVLSuccessorPredecessor(Node**tree , int x){
    Node* curr = *tree;
    int predecessor_val = curr->left->val;
    int curr_val = curr->val;
    int successor_val = curr->val;
    while(curr_val != x &&(curr != NULL)){
        if(x > curr->val){
            successor_val = curr->val;
            curr = curr->right;
            curr_val = curr->val;
            if (curr->left !=NULL){
                predecessor_val = curr->left->val;
            }
            else if (curr->left == NULL && curr->right == NULL && curr->val!=x){
                printf("\nKey Not Found\n");
                return;
            }
            // else{
            //     printf("\n No Predecessor of the Node exsists since the key is a leaf node");
            //     break;
            // }
        }
        else if (x < curr->val){
            successor_val = curr->val;
            curr = curr->left;
            curr_val = curr->val;
            if (curr->left !=NULL){
                predecessor_val = curr->left->val;
            }
            else if (curr->left == NULL && curr->right == NULL && curr->val!=x){
                printf("\nKey Not Found\n");
                return;
            }
            // else{
            //     printf("\n No Predecessor of the Node exsists since the key is a leaf node");
            //     break;
            // }
        }
        else{
            curr_val = curr->val;
        }
    }
    printf("The Current Key is : %d\n Its Successor is : %d \n Its Predecessor is %d\n" , curr_val , successor_val , predecessor_val);

}

void main() {
    int n,i,x,key;
    Node * tree = (Node *) malloc(sizeof(Node));
    tree = NULL;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for (i=0;i<n;i++) {
        printf("Enter element ");
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    printf("Inorder traversal: ");
    inOrder(tree);
    printf("\nEnter the key : ");
    scanf("%d",&key);
    AVLSuccessorPredecessor(&tree , key);
}