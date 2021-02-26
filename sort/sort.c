#include "sort.h"


static bool goes_before(void *item1, void *item2)
{
    /* Establecer la Relacion de Orden entre los elementos del array*/
    return true;
}

static void swap(void **array, u32 i, u32 j)
{
    void *tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

static void partition(void **array, u32 left, u32 rigth, u32 *pivot_ref)
{
    u32 i = left + 1u;
    u32 j = rigth;
    *pivot_ref = left;

    while (i <= j) {
        if (goes_before(array[i], array[*pivot_ref]))
            ++i;
        else if (goes_before(array[*pivot_ref], array[j]))
            --j;
        else {
            swap(array, i, j);
            ++i;
            --j;
        }
    }

    swap(array, *pivot_ref, j);
    *pivot_ref = j;
}

static void quick_sort_rec(void **array, u32 left, u32 right)
{
    u32 pivot;
    if (left < right) {
        partition(array, left, right, &pivot);
        quick_sort_rec(array, left, pivot ? pivot-1u : 0u);
        quick_sort_rec(array, pivot+1u, right);
    }
}

void array_quick_sort(void **array, u32 len)
{
    u32 right = len ? len-1u : 0u;
    quick_sort_rec(array, 0u, right);
}

bool array_is_sorted(void **array, u32 len)
{
    for (u32 i = 1u; i < len; ++i) {
        if (!goes_before(array[i-1u], array[i]))
            return false;
    }

    return true;
}