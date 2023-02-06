#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* addNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = addNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = addNode(root->right, data);
    }
    return root;
}

struct Node* minNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = removeNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/*TODO: add queue system for level order traversal (i.e. each layer of the tree)*/
void levelOrder(struct Node* root) {
    if (root != NULL) {
    }
}

/*TODO: add depth first search*/
void DFS(struct Node* root){

}

/*TODO: add breadth first search*/
void BFS(struct Node* root){

}

int main() {
    struct Node* root = NULL;
    /* You can test the code here by adding and removing nodes */
    /* I.E.  root = add(root, 69); */
    /* I.E.  root = removeNode(root, 69)*/
    return 0;
}