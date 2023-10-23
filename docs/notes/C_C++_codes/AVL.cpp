#include <bits/stdc++.h>
#include <cstdint>

template <typename key_, typename value_> struct Data {
    key_ key;
    value_ value;
    Data(key_ key__, value_ value__) : key(key__), value(value__) {}
    bool operator>(Data<key_, value_> D) { return key > D->key; }
    bool operator<(Data<key_, value_> D) { return key < D->key; }
    bool operator>=(Data<key_, value_> D) { return key >= D->key; }
    bool operator<=(Data<key_, value_> D) { return key <= D->key; }
    bool operator==(Data<key_, value_> D) { return key == D->key; }
    bool operator!=(Data<key_, value_> D) { return key != D->key; }
};

template <typename key_, typename value_> class BSTNode {
    Data<key_, value_> dat;
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
    int64_t height;
    BSTNode(key_ key__, value_ value__)
        : dat(Data<key_, value_>(key__, value__)) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        height = 0;
    };
    BSTNode(Data<key_, value_> dat_) : dat(dat_) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        height = 0;
    };
    template <typename> friend class BST;
};

template <typename key_, typename value_> class BST {
  private:
    typedef BSTNode<key_, value_> data_;
    data_ *root;
    void remove_(key_ key, data_ *&ptr) {
        if (ptr == nullptr) {
            return;
        } else if (ptr->dat.key > key) {
            remove_(key, ptr->left);
        } else if (ptr->dat.key < key) {
            remove_(key, ptr->right);
        } else if (ptr->right != nullptr && ptr->left != nullptr) {
            data_ *min = min_(ptr->right);
            ptr->dat = min->dat;
            remove_(ptr->dat.key, ptr->right);
        } else {
            data_ *oldNode = ptr;
            ptr->left != nullptr ? ptr = ptr->left : ptr->right;
            if (ptr != nullptr) {
                ptr->parent = ptr->parent->parent;
            }
            delete oldNode;
        }
        balance(ptr);
    }
    data_ *max_(data_ *ptr) {
        if (ptr == nullptr) {
            return nullptr;
        }
        while (ptr->right != nullptr) {
            ptr = ptr->right;
        }
        return ptr;
    }
    data_ *min_(data_ *ptr) {
        if (ptr == nullptr) {
            return nullptr;
        }
        while (ptr->left != nullptr) {
            ptr = ptr->left;
        }
        return ptr;
    }
    void right_rot(data_ *&ptr) {
        data_ *right_child = ptr->right;
        ptr->right = right_child->left;
        right_child->left = ptr;
        right_child->parent = ptr->parent;
        ptr->parent = right_child;
        ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
        right_child->height = max(height(right_child->right), ptr->height) + 1;
        ptr = right_child;
    }
    void left_rot(data_ *&ptr) {
        data_ *left_child = ptr->left;
        ptr->left = left_child->right;
        left_child->right = ptr;
        left_child->parent = ptr->parent;
        ptr->parent = left_child;
        ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
        left_child->height = max(height(left_child->left), ptr->height) + 1;
        ptr = left_child;
    }
    int64_t height(data_ *ptr) const {
        return ptr == nullptr ? -1 : ptr->height;
    }
    void balance(data_ *&ptr) {
        if (ptr == nullptr)
            return;

        if (height(ptr->left) - height(ptr->right) > 1) {
            if (height(ptr->left->left) >= height(ptr->left->right)) {
                left_rot(ptr);
            } else {
                right_rot(ptr->left);
                left_rot(ptr);
            }
        } else if (height(ptr->right) - height(ptr->left) > 1) {
            if (height(ptr->right->right) >= height(ptr->right->left)) {
                right_rot(ptr);
            } else {
                left_rot(ptr->right);
                right_rot(ptr);
            }
        }
    }

  public:
    BST() { root = nullptr; }
    void insert(key_ key, value_ value) {
        if (root == nullptr) {
            root = new data_(key, value);
            return;
        }
        data_ *node = root;
        data_ *ins = new data_(key, value);
        while (node != nullptr) {
            if (node->dat > ins->dat && node->left == nullptr) {
                node->left = ins;
                ins->parent = node;
                return;
            } else if (node->dat < ins->dat && node->right == nullptr) {
                node->right = ins;
                ins->parent = node;
                return;
            } else if (node->dat > ins->dat) {
                node = node->left;
            } else if (node->dat < ins->dat) {
                node = node->right;
            } else {
                return;
            }
        }
    }
    void insert(Data<key_, value_> dat) {
        if (root == nullptr) {
            root = new data_(dat);
            return;
        }
        data_ *node = root;
        data_ *ins = new data_(dat);
        while (node != nullptr) {
            if (node->dat > ins->dat && node->left == nullptr) {
                node->left = ins;
                ins->parent = node;
                return;
            } else if (node->dat < ins->dat && node->right == nullptr) {
                node->right = ins;
                ins->parent = node;
                return;
            } else if (node->dat > ins->dat) {
                node = node->left;
            } else if (node->dat < ins->dat) {
                node = node->right;
            } else {
                return;
            }
        }
        balance(node);
    }
    data_ *search(key_ key) {
        data_ *search_ = root;
        while (search_ != nullptr) {
            if (search_->dat.key > key) {
                search_ = search_->left;
            } else if (search_->dat.key < key) {
                search_ = search_->right;
            } else if (search_->dat.key == key) {
                return search_;
            }
        }
        return nullptr;
    }
    void remove(key_ key) { remove_(key, root); }
    data_ *max() { return max_(root); }
    data_ *min() { return min_(root); }
};

int main(int argc, char *argv[]) {
    BST<int, int> B;
    return 0;
}
