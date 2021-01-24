#include "sort.h"

#include <utility>

void sort_insertion(sort_data_t *data, size_t length) {
  size_t i = 1;

  while (i < length) {
    size_t j = i;
    while (j > 0 && data[j - 1] > data[j]) {
      std::swap(data[j], data[j - 1]);
      j--;
    }
    i++;
  }
}
