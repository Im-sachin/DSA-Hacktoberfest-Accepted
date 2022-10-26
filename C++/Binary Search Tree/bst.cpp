#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* getNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserts into the binary tree
Node* insert(Node* root, int data){
    if (root == NULL)
    {
        root = getNode(data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Searches for a node in the binary tree
bool search(Node* root, int data){
    if (root == NULL)
    {
        cout << data << " cannot be found in the tree..\n";
        return false;
    }
    if (root->data == data)
    {
        cout << data << " found in the tree..\n";
        return true;
    }
    else if (root->data > data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Searches for the maximum node in the binary tree
int max_tree(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// Searches for the maximum value in the binary tree using recursion
int max_tree_recursion(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return max_tree_recursion(root->right);
}

// Searches for the minimum value in the binary tree
int min_tree(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// Searches for the minimum value in the binary tree using recursion
int min_tree_recursion(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return min_tree_recursion(root->left);
}

// Returns the maximum height of the tree
int height_of_bst(Node* root){
    if (root == NULL)
    {
        return -1;
    }
    return max(height_of_bst(root->left), height_of_bst(root->right)) + 1;
}

// Breadth First Search - BFS or Level Order Traversal of binary tree
void bfs(Node* root){
    if (root == NULL)
    {
        cout << "Empty tree..\n";
        return ;
    }
    
    list<Node*> q;
    q.push_back(root);
    while (!q.empty())
    {
        Node* current = q.front();
        cout << current->data << " ";
        if(current->left!=NULL) q.push_back(current->left);
        if(current->right!=NULL) q.push_back(current->right);
        q.pop_front();
    }
    cout << "\n";
}

// Depth First Search - DFS or Preorder Traversal
void preorder(Node* root){
    if (root == NULL) return ;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Depth First Search - DFS or Inorder Traversal
void inorder(Node* root){
    if (root == NULL) return ;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Depth First Search - DFS or Postorder Traversal
void postorder(Node* root){
    if (root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Checks if all the nodes in a subtree are lesser than a given value
bool islesser(Node* root, int val){
    if(root == NULL) return true;
    if (root->data < val && islesser(root->left, val)
        && islesser(root->right, val))
    {
        return true;
    }
    return false;
}

// Checks if all the nodes in a subtree are higher than a given value
bool ishigher(Node* root, int val){
    if(root == NULL) return true;
    if (root->data > val && ishigher(root->left, val)
        && ishigher(root->right, val))
    {
        return true;
    }
    return false;
}

// METHOD-1: Checks if a binary tree is BST
bool is_bst(Node* root){
    if (root == NULL)
    {
        return true;
    }
    if (islesser(root->left, root->data) && ishigher(root->right, root->data)
        && is_bst(root->left) && is_bst(root->right))
    {
        return true;
    }
    return false;
}

// METHOD-2: Checks if a binary tree is BST
bool is_bst_util(Node* root, int lt, int rt){
    if(root == NULL) return true;
    if (root->data>lt && root->data<rt 
        && is_bst_util(root->left, lt, root->data) 
        && is_bst_util(root->right, root->data, rt))
    {
        return true;
    }
    return false;
}

bool isBst(Node* root){
    return is_bst_util(root, INT_MIN, INT_MAX);
}

// Returns the node having minimum value in the tree
Node* findMin(Node* root){
    if(root == NULL) return NULL;
    else if(root->left == NULL) return root;
    return findMin(root->left);
}

// Deletes a node from binary tree
Node* deleteNode(Node* root, int data){
    if(root == NULL) return root;
    else if(root->data < data) root->right = deleteNode(root->right,data);
    else if(root->data > data) root->left = deleteNode(root->left,data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Returns the address of the node in the binary tree
Node* searchBst(Node* root, int data){
    if(root == NULL) return NULL;
    else if(root->data < data) root->right = searchBst(root->right, data);
    else if(root->data > data) root->left = searchBst(root->right, data);
    else return root;
}

// Return the successor of a node in inorder traversal of binary tree
Node* getSuccessor(Node* root, int data){
    Node* current = searchBst(root, data);
    if(current == NULL) return NULL;

    // Case-1: Node has right subtree
    if(current->right != NULL) return findMin(root->right);
    else
    {
        
        // Case-2: No right subtree - O(h)
        Node* successor = NULL;
        Node* ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;        
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 26);
    root = insert(root, 75);
    root = insert(root, 20);
    cout << search(root, 20) << "\n";
    cout << search(root, 10) << "\n";
    cout << search(root, 60) << "\n";
    cout << search(root, 40) << "\n";
    cout << "Minimum element in tree is: " << min_tree(root) << "\n";
    cout << "Maximum element in tree is: " << max_tree(root) << "\n";
    cout << "Minimum element in tree is: " << min_tree_recursion(root) << "\n";
    cout << "Maximum element in tree is: " << max_tree_recursion(root) << "\n";
    bfs(root);
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    if (is_bst(root))
    {
        cout << "The given binary tree is a binary search tree..\n";
    }
    else
    {
        cout << "The given binary tree is not a binary search tree..\n";
    }
    deleteNode(root, 4);
    inorder(root);
    return 0;
}
