#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

Node *buatNode(int nilai) {
    Node *nodeBaru = new Node();
    if (!nodeBaru) {
        cout << "Kesalahan memori\n";
        return nullptr;
    }
    nodeBaru->data = nilai;
    nodeBaru->kiri = nodeBaru->kanan = nullptr;
    return nodeBaru;
}

Node *sisipNode(Node *root, int nilai) {
    if (root == nullptr) {
        root = buatNode(nilai);
        return root;
    }

    if (nilai < root->data) {
        root->kiri = sisipNode(root->kiri, nilai);
    } else {
        root->kanan = sisipNode(root->kanan, nilai);
    }

    return root;
}

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->kiri);
    preOrder(root->kanan);
}

void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

void postOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

int main() {
    Node *root = nullptr;
    int nilai[] = {12, 16, 20, 24, 32};

    for (int n : nilai) {
        root = sisipNode(root, n);
    }

    cout << "Traversal pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "Traversal in-order: ";
    inOrder(root);
    cout << endl;

    cout << "Traversal post-order: ";
    postOrder(root);
    cout << endl;

    return 0;
}
