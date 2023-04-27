#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root ==NULL){
    return;
  }
  traverseInOrder(root->left);
  cout<< root->key<<" ";
  traverseInOrder(root ->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node==NULL){}
    node = new struct node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
  if(key>node->key){
    node->right = insertNode(node->right,key);
  }else if(key<=node->key){
    node->left = insertNode(node->left,key);
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}