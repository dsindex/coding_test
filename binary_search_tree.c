#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* left;
    struct node* right; 
};
typedef struct node node_t;

node_t* create_node(int key)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if( !node ) return NULL;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t* insert(node_t* root, int key)
{
    if( root == NULL ) return create_node(key);
    if( root->key > key ) root->left = insert(root->left, key);
    if( root->key < key ) root->right = insert(root->right, key);
    return root; // itself
}

void inorder(node_t* root)
{
    if( !root ) return;
    if( root->left ) inorder(root->left);
    fprintf(stdout, "%d ", root->key);
    if( root->right ) inorder(root->right);
}

void destroy(node_t* root)
{
    // using post-order traversal
    if( !root ) return;
    if( root->left ) destroy(root->left);
    if( root->right ) destroy(root->right);
    free(root);
}

node_t* find(node_t* root, int key)
{
    if( !root ) return NULL;
    if( root->key < key ) return find(root->right, key);
    if( root->key > key ) return find(root->left, key);
    return root;
}

node_t* find_smallest(node_t* root)
{
    node_t* node = root;
    if( !node ) return NULL;
    while( node->left ) {
        node = node->left;
    }
    // left-most child
    return node;
}

node_t* delete(node_t* root, int key)
{
    node_t* temp;
    if( !root ) return NULL;
    // find key first
    if( root->key < key ) root->right = delete(root->right, key);
    else if( root->key > key ) root->left = delete(root->left, key);
    else {
        // root->key == key
        // 0. root has no child
        if( !root->left && !root->right ) {
            free(root);
            return NULL;
        }
        // 1. root has left child only
        if( root->left && !root->right ) {
            temp = root->left;
            free(root);
            return temp;
        }
        // 2. root has right child only
        if( !root->left && root->right ) {
            temp = root->right;
            free(root);
            return temp;
        } 
        // 3. root has both child
        temp = find_smallest(root->right);
        // copy temp to root
        root->key = temp->key;
        // delete temp
        root->right = delete(root->right, temp->key);
    }
    return root;
}

int main(int argc, char** argv)
{
    node_t* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    inorder(root);
    fprintf(stdout, "\n");
    node_t* node;
    int        key;
    
    key = 9;
    node = find(root, key);
    if( node ) fprintf(stdout, "%d found\n", key);
    key = 0;
    node = find(root, key);
    if( node ) fprintf(stdout, "%d found\n", key);
    else fprintf(stdout, "%d not found\n", key);

    root = delete(root, 9);
    inorder(root);
    fprintf(stdout, "\n");
    root = delete(root, 1);
    inorder(root);
    fprintf(stdout, "\n");
    
    destroy(root);
    return 0;
}
