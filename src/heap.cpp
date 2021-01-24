#include "sort.h"

#include <utility>

#define parent(i) ((i - 1) / 2)
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

void sift_down(sort_data_t *data, size_t start, size_t end) {
    size_t root = start;

    while (left(root) <= end) {
        size_t child = left(root);
        size_t swap = root;

        if (data[swap] < data[child])
            swap = child;
        if (child + 1 <= end && data[swap] < data[child + 1])
            swap = child + 1;
        if (swap == root)
            return;
        else {
            std::swap(data[root], data[swap]);
            root = swap;
        }
    }
}

void heapify(sort_data_t *data, size_t length) {
    ptrdiff_t start = parent(length - 1);

    while (start >= 0) {
        sift_down(data, start, length - 1);
        start--;
    }
}

void sort_heap(sort_data_t *data, size_t length) {
    heapify(data, length);

    size_t end = length - 1;
    while (end > 0) {
        std::swap(data[end], data[0]);
        end--;
        sift_down(data, 0, end);
    }
}
