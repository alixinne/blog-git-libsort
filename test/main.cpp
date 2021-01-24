#include "sort.h"

#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <vector>

template <typename Callable>
int test_sort_function(std::vector<sort_data_t> &working_vector,
                       const std::vector<sort_data_t> &source_vector,
                       const std::vector<sort_data_t> &sorted_vector,
                       Callable fn) {
  // Initialize working array with unsorted vector
  std::copy(source_vector.begin(), source_vector.end(), working_vector.begin());

  // Call sorting function
  fn(working_vector.data(), working_vector.size());

  // Compare sorted reference and our function
  for (size_t i = 0; i < sorted_vector.size(); ++i) {
    if (working_vector[i] != sorted_vector[i]) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int res = 0;
  const size_t Ns[] = {10, 100, 1000, 10000};

  for (auto &N : Ns) {
    std::vector<sort_data_t> source_vector(N, 0), working_vector(N, 0),
        sorted_vector(N, 0);

    std::generate(source_vector.begin(), source_vector.end(),
                  [=]() { return rand() % (2 * N); });

    std::copy(source_vector.begin(), source_vector.end(),
              sorted_vector.begin());
    std::sort(sorted_vector.begin(), sorted_vector.end());

    res += test_sort_function(working_vector, source_vector, sorted_vector,
                              sort_insertion);
    res += test_sort_function(working_vector, source_vector, sorted_vector,
                              sort_selection);
    res += test_sort_function(working_vector, source_vector, sorted_vector,
                              sort_merge);
    res += test_sort_function(working_vector, source_vector, sorted_vector,
                              sort_heap);
    res += test_sort_function(working_vector, source_vector, sorted_vector,
                              sort_quick);
  }

  return res;
}
