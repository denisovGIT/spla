#include "defines.cl"

// memory bank conflict-free address and local buffer size
#ifdef LM_NUM_MEM_BANKS
    #define LM_ADDR(address) (address + ((address) / LM_NUM_MEM_BANKS))
    #define LM_SIZE(size)    (size + (size) / LM_NUM_MEM_BANKS)
#endif

#define SWAP_KEYS(x, y) \
    uint tmp1 = x;      \
    x         = y;      \
    y         = tmp1;

#define SWAP_VALUES(x, y) \
    TYPE tmp2 = x;        \
    x         = y;        \
    y         = tmp2;

// nearest power of two number greater equals n
uint ceil_to_pow2(uint n) {
    uint r = 1;
    while (r < n) r *= 2;
    return r;
}

// find first element in a sorted array such x <= element
uint lower_bound(const uint           x,
                 uint                 first,
                 uint                 size,
                 __global const uint* array) {
    while (size > 0) {
        int step = size / 2;

        if (array[first + step] < x) {
            first = first + step + 1;
            size -= step + 1;
        } else {
            size = step;
        }
    }
    return first;
}