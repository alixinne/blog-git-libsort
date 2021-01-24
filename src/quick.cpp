#include "sort.h"

#include <utility>

ptrdiff_t partition(sort_data_t *data, ptrdiff_t lo, ptrdiff_t hi) {
    auto pivot = data[hi];
    ptrdiff_t i = lo;
    for (ptrdiff_t j = lo; j < hi; ++j) {
        if (data[j] < pivot) {
            std::swap(data[i], data[j]);
            i++;
        }
    }
    std::swap(data[i], data[hi]);
    return i;
}

void quicksort(sort_data_t *data, ptrdiff_t lo, ptrdiff_t hi) {
    if (lo < hi) {
        ptrdiff_t p = partition(data, lo, hi);
        quicksort(data, lo, p - 1);
        quicksort(data, p + 1, hi);
    }
}

void sort_quick(sort_data_t *data, size_t length) { quicksort(data, 0, length - 1); }
