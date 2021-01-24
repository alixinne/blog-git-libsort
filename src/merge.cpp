#include "sort.h"

#include <algorithm>
#include <vector>

void merge(sort_data_t *a, size_t i_begin, size_t i_middle, size_t i_end, sort_data_t *b) {
    size_t i = i_begin, j = i_middle;

    for (size_t k = i_begin; k < i_end; ++k) {
        if (i < i_middle && (j >= i_end || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
    }
}

void split_merge(sort_data_t *b, size_t i_begin, size_t i_end, sort_data_t *a) {
    if (i_end - i_begin <= 1)
        return;

    size_t i_middle = (i_end + i_begin) / 2;
    split_merge(a, i_begin, i_middle, b);
    split_merge(a, i_middle, i_end, b);
    merge(b, i_begin, i_middle, i_end, a);
}

void sort_merge(sort_data_t *data, size_t length) {
    std::vector<sort_data_t> b(length);
    std::copy(data, data + length, b.begin());
    split_merge(b.data(), 0, length, data);
}
