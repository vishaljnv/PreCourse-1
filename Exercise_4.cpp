#include <iostream> 
#include <queue> 
using namespace std; 
//new one
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right; 
}; 
  
/* function to create a new node of tree and
   return pointer */
struct Node* newNode(int key) 
{ 
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;

    return node;
} 
  
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
    if (!temp) { 
        return; 
    }

    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
  
/*function to insert element in binary tree */
void insert(struct Node* temp, int key) 
{ 
    queue<Node *> q;
    q.push(temp);

    while (!q.empty()) {
        Node *front = q.front();
        q.pop();

        if (!front->left) {
            front->left = newNode(key);
            break;
        } else {
            q.push(front->left);
        }

        if (!front->right) {
            front->right = newNode(key);
            break;
        } else {
            q.push(front->right);
        }
    }
}

// Driver code 
int main() 
{ 
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
 
    cout << endl; 
    int key = 12; 
    insert(root, key); 
  
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
    cout << endl; 
  
    return 0; 
} 
