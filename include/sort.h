#ifndef _SORT_H_
#define _SORT_H_

#include <cstddef>

typedef int sort_data_t;

void sort_insertion(sort_data_t *data, size_t length);
void sort_selection(sort_data_t *data, size_t length);
void sort_merge(sort_data_t *data, size_t length);
void sort_heap(sort_data_t *data, size_t length);
void sort_quick(sort_data_t *data, size_t length);

#endif /* _SORT_H_ */
