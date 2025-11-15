#ifndef TRADS
#define TRADS

#include <vector>
#include <concepts>
#include <algorithm>
#include <type_traits>
using namespace std;


static constexpr size_t THRESHOLD = 24;

template<typename T, typename Comp>
concept Comparator = requires(Comp comp, T a, T b) {
    { comp(a, b) } -> std::convertible_to<bool>;
};

template<typename T, Comparator<T> compare>
void insertionSort(T* arr, const size_t left, const size_t right, compare cmp) noexcept {
    for(size_t i = left + 1; i <= right; ++i) {
        size_t j = i - 1;
        T key = arr[i];
        while(j >= left && cmp(key, arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
void insertionSort(T* arr, const size_t left, const size_t right) noexcept {
    for(size_t i = left + 1; i <= right; ++i) {
        size_t j = i - 1;
        T key = arr[i];
        while(j >= left && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<typename T, Comparator<T> compare>
inline void insertionSort(T* arr, const size_t size, compare cmp) noexcept {
    insertionSort(arr, 0, size - 1, cmp);
}
template<typename T>
inline void insertionSort(T* arr, const size_t size) noexcept {
    insertionSort(arr, 0, size - 1);
}


template<typename T, Comparator<T> compare>
void quickSort(T* arr, const size_t left, const size_t right, compare cmp) {
    if (right - left < THRESHOLD) {
        insertionSort(arr, left, right, cmp);
        return;
    }

    const size_t mid = (left + right) >> 1;
    if (cmp(arr[right], arr[left]))
        swap(arr[left],arr[right]);
    if (cmp(arr[mid],   arr[left]))
        swap(arr[mid], arr[left]);
    if (cmp(arr[mid],   arr[right]))
        swap(arr[mid], arr[right]);

    size_t i = left, j = right;
    const T pivot = arr[right];
    
    while (true) {
        while (cmp(arr[++i], pivot));
        while (cmp(pivot, arr[--j]));
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    
    swap(arr[i], arr[right]);

    quickSort(arr, left,  i - 1, cmp);
    quickSort(arr, i + 1, right, cmp);
}

template<typename T>
void quickSort(T* arr, const size_t left, const size_t right) {
    if (right - left < THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }

    const size_t mid = (left + right) >> 1;
    if (arr[right] < arr[left])
        swap(arr[left],arr[right]);
    if (arr[mid]   < arr[left])
        swap(arr[mid], arr[left]);
    if (arr[mid]   < arr[right])
        swap(arr[mid], arr[right]);

    size_t i = left, j = right;
    const T pivot = arr[right];
    
    while (true) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    
    swap(arr[i], arr[right]);

    quickSort(arr, left,  i - 1);
    quickSort(arr, i + 1, right);
}

template<typename T, Comparator<T> compare>
inline void quickSort(T* arr, const size_t size, compare cmp) noexcept {
    if(size > 1)
    	quickSort(arr, 0, size - 1, cmp);
}
template<typename T, Comparator<T> compare>
inline void quick_sort(T* arr, const size_t size, compare cmp) noexcept {
    if(size > 1)
    	quickSort(arr, 0, size - 1, cmp);
}
template<typename T>
inline void quickSort(T* arr, const size_t size) noexcept {
    if (size > 1)
    	quickSort(arr, 0, size - 1);
}
template<typename T>
inline void quick_sort(T* arr, const size_t size) noexcept {
    if (size > 1)
    	quickSort(arr, 0, size - 1);
}


template<typename T>
void mergeSort(T* arr, const size_t n) noexcept {
	if (n <= THRESHOLD + 8) {
		insertionSort(arr, 0, n - 1);
		return;
	}

	size_t i = 0;
    for (; i < n - THRESHOLD; i +=THRESHOLD)
    	insertionSort(arr, i, i + THRESHOLD - 1);
    if  (i < n)
    	insertionSort(arr, i, n - 1);

    T* buffer = new T[n];
    T* src = arr, *dst = buffer;
    
    for (size_t width = THRESHOLD; width < n; width <<= 1) {
        for (i = 0; i < n; i += (width << 1)) {
            const size_t mid = std::min(i + width, n), right = std::min(mid + width, n);
            size_t r = mid;
            size_t l = i, current = i;

            while (l < mid && r < right)
                dst[current++] = (src[l] < src[r] ? src[l++] : src[r++]);
            while (l < mid)
                dst[current++] = src[l++];
            while (r < right)
                dst[current++] = src[r++];
        }

        T* tmp = src;
	       src = dst;
	       dst = tmp;
    }

    if (src != arr)
        memcpy(arr, buffer, n * sizeof(T));

	delete[] buffer;
}

template<typename T>
inline void merge_sort(T* arr, const size_t n) noexcept {
	mergeSort(arr, n);
}


template<typename T>
void heapSort(T* arr, const size_t n) noexcept {
    for(size_t i = (n >> 1) - 1; i >= 0; --i) {
        size_t parent = i, child = (i << 1) + 1;
        const T temp = arr[parent];

        while (child < n) {
            if(child + 1 < n && arr[child + 1] > arr[child])
                ++child;
            if(arr[child] <= temp)
                break;

            arr[parent] = arr[child];
            parent = child;
            child = parent * 2 + 1;
        }
        arr[parent] = temp;
    }

    for(size_t i = n - 1; i; --i) {
        const T temp = arr[i];
        arr[i] = arr[0];
        size_t parent = 0, child = 1;

        while (child < i) {
            if(child + 1 < i && arr[child + 1] > arr[child])
                ++child;
            if(arr[child] <= temp)
                break;

            arr[parent] = arr[child];
            parent = child;
            child = (parent << 1) + 1;
        }
        arr[parent] = temp;
    }
}

template<typename T>
inline void heap_sort(T* arr, const size_t n) noexcept {
	heapSort(arr, n);
}

#endif
