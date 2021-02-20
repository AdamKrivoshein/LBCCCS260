template <typename T>
struct Node {
    T val;
    Node* left;
    Node* right;

    Node(T val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};