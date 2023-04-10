#include <iostream>

using namespace std;

struct Node{
	Node* left,
		* right;
	int info;
};

Node* insert(Node* root, int data);
int countNodes(Node* root);
void printTree(Node* root);

int main(){
    Node* root = NULL;
    int N;
    cout << "Enter count: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }
    printTree(root);
    cout << endl << endl;
    cout << countNodes(root) << endl;


    return 0;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = new Node;
        root->info = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data <= root->info) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);

    cout << root->info << " ";

    printTree(root->right);
}