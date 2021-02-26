#ifndef SORT
#define SORT

#include "../macros.h"

void array_quick_sort(void **array, u32 len);

bool array_is_sorted(void **array, u32 len);

#endif /* SORT */