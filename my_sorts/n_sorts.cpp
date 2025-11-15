#ifndef COUNTS
#define COUNTS

#include <cstring>
#include <algorithm>
#include <type_traits>
#include <cstdint>
using namespace std;


static constexpr size_t MAX_ELEM_LIMIT = 5000, MIN_ELEM_LIMIT = 0, HIST_SIZE = 256;

template<typename T>
void counting_sort(T* arr, size_t n, const size_t min_lim = MIN_ELEM_LIMIT, const size_t max_lim = MAX_ELEM_LIMIT) noexcept {
    if (n < 2)
        return;

    size_t r = max_lim - min_lim + 1;
    size_t* count = new size_t[r];
    memset(count, 0, r * sizeof(size_t));

    while (n--)
        count[arr[n] - min_lim]++;

    T* write = arr;
    for (size_t i = 0; i < r; ++i) {
        T val = i + min_lim;

        while (count[i] >= 8) {
            write[0] = write[1] = write[2] = write[3] = write[4] = write[5] = write[6] = write[7] = val;
            write += 8;
            count[i] -= 8;
        }

        // fall
        switch (count[i]) {
            case 7: *write++ = val;
            case 6: *write++ = val;
            case 5: *write++ = val;
            case 4: *write++ = val;
            case 3: *write++ = val;
            case 2: *write++ = val;
            case 1: *write++ = val;
        }
    }
    delete[] count;
}

template<typename T>
inline void countingSort(T* arr, size_t n, const size_t min_lim = MIN_ELEM_LIMIT, const size_t max_lim = MAX_ELEM_LIMIT) noexcept {
	counting_sort(arr, n, min_lim, max_lim);
}


template<typename T>
void radixSort(T* arr, const size_t n) {
    if (n < 2)
        return;

    constexpr bool is_signed = std::is_signed<T>::value;
    using UnsignedT = typename std::make_unsigned<T>::type;

    constexpr size_t num_passes = sizeof(T) - 1;

    T* buffer = new T[n];
    size_t histogram[HIST_SIZE];
    T* src = arr, *dst = buffer;

    for (size_t pass = 0; pass < num_passes; ++pass) {
        memset(histogram, 0, sizeof(histogram));

        for (size_t i = 0; i < n; ++i) {
            UnsignedT value = static_cast<UnsignedT>(src[i]);
            uint8_t digit = (value >> (pass << 3)) & 0xFF;
            histogram[digit]++;
        }

        size_t pos = 0;
        for(size_t i = 0; i < HIST_SIZE; ++i) {
            size_t tmp = histogram[i];
            histogram[i] = pos;
            pos += tmp;
        }

        for (size_t i = 0; i < n; ++i) {
            UnsignedT value = static_cast<UnsignedT>(src[i]);
            uint8_t digit = (value >> (pass << 3)) & 0xFF;
            dst[histogram[digit]] = src[i];
            histogram[digit]++;
        }

        swap(src, dst);
    }

    memset(histogram, 0, sizeof(histogram));
    
    for (size_t i = 0; i < n; ++i) {
        UnsignedT value = static_cast<UnsignedT>(src[i]);
        uint8_t digit = (value >> ((num_passes) << 3)) & 0xFF;

        if constexpr (is_signed) {
            digit ^= 0x80;
        
        histogram[digit]++;
    }

    size_t pos = 0;
    for(size_t i = 0; i < HIST_SIZE; ++i) {
        size_t tmp = histogram[i];
        histogram[i] = pos;
        pos += tmp;
    }

    for (size_t i = 0; i < n; ++i) {
        UnsignedT value = static_cast<UnsignedT>(src[i]);
        uint8_t digit = (value >> ((num_passes) << 3)) & 0xFF;

        if constexpr (is_signed)
            digit ^= 0x80;
        
        dst[histogram[digit]] = src[i];
        histogram[digit]++;
    }

    if (num_passes & 1)
        memcpy(arr, dst, n * sizeof(T));

    delete[] buffer;
}

template<typename T>
inline void radix_sort(T* arr, const size_t n) noexcept {
	radixSort(arr, n);
}


#endif
