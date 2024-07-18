 #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
public:
    BST() : root(NULL) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    bool search(int data) {
        return searchRec(root, data);
    }

    void deleteNode(int data) {
        root = deleteRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else if (data > node->data) {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    bool searchRec(Node* node, int data) {
        if (node == NULL) {
            return false;
        }
        if (data == node->data) {
            return true;
        } else if (data < node->data) {
            return searchRec(node->left, data);
        } else {
            return searchRec(node->right, data);
        }
    }

    Node* deleteRec(Node* node, int data) {
        if (node == NULL) {
            return node;
        }
        if (data < node->data) {
            node->left = deleteRec(node->left, data);
        } else if (data > node->data) {
            node->right = deleteRec(node->right, data);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void inorderRec(Node* node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    BST bst;
    int choice, value;

    while (true) {
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << value << " found in the BST.\n";
                } else {
                    cout << value << " not found in the BST.\n";
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.deleteNode(value);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                bst.inorder();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
