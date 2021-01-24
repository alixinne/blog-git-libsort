#include "sort.h"

#include <utility>

void sort_selection(sort_data_t *data, size_t length) {
  for (size_t i = 0; i < length - 1; ++i) {
    size_t j_min = i;
    for (size_t j = i + 1; j < length; ++j) {
      if (data[j] < data[j_min])
        j_min = j;
    }

    if (j_min != i)
      std::swap(data[i], data[j_min]);
  }
}
