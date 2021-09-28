#include <iostream>
#include <vector>
#include <memory>
 
struct FindTree {
    std::unique_ptr<FindTree> left;
    std::unique_ptr<FindTree> right;
    int value;
};
 
std::unique_ptr<FindTree> buildTree(const std::vector<int> &array, int left, int right) {
    if (left == right) {
        return std::unique_ptr<FindTree>(nullptr);
    }
 
    auto out = std::make_unique<FindTree>();
    int middle = (left + right) / 2;
    out->value = array[middle];
    out->left = buildTree(array, left, middle);
    out->right = buildTree(array, middle + 1, right);
 
    return out;
}
 
void printTree(std::unique_ptr<FindTree> &tree) {
    if (tree->left.get() != nullptr) {
        std::cout << tree->value << " -left> " << tree->left->value << std::endl;
        printTree(tree->left);
    }
    if (tree->right.get() != nullptr) {
        std::cout << tree->value << " -right> " << tree->right->value << std::endl;
        printTree(tree->right);
    }
}
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
 
    for(int &i : array) {
        std::cin >> i;
    }
 
    auto tree = buildTree(array, 0, n);
    printTree(tree);
}
 
int main() {
    std::iostream::sync_with_stdio(false);
    std::cout.tie(nullptr);
 
    solve();
 
    return 0;
}
 