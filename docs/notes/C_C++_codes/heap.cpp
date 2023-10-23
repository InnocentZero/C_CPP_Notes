#include <array>
#include <bits/stdc++.h>
#include <cstdint>
#include <memory>
#include <utility>

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

template <typename key_, typename value_> class MinHeap {
    uint64_t capacity;
    uint64_t size;
    typedef Data<key_, value_> data_;
    data_ *array;
    void double_capacity() {
        data_ *temp = new data_[2 * capacity + 1];
        for (int64_t i = 0; i <= capacity; i++) {
            temp[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = temp;
    }

  public:
    MinHeap(uint64_t capacity = 8) {
        size = 0;
        capacity = 8;
        array = new data_[9];
    }
    ~MinHeap() { delete[] array; }
    void insert(data_ Node) {
        array[++size] = Node;
        if (size == capacity) {
            double_capacity();
        }
        uint64_t i = size;
        while (i > 1 && array[i / 2] < array[i]) {
            std::swap(array[i / 2], array[i]);
        }
    }
    const data_ &top() const { return array[1]; }
    void pop() {
        array[1] = std::move(array[size--]);
        uint64_t i = 1;
        while (2 * i <= size) {
            if (2 * i == size && array[2 * i] < array[i]) {
                std::swap(array[2 * i], array[i]);
            } else {
                uint64_t min_ =
                    array[2 * i] < array[2 * i + 1] ? 2 * i : 2 * i + 1;
                if (array[min_] < array[i]) {
                    std::swap(array[min_], array[i]);
                    i = min_;
                }
            }
        }
    }
};
