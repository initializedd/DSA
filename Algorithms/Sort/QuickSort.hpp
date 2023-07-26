#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <cstdint>

template <typename T, typename Compare>
constexpr void quick_sort(T* const arr, const std::int64_t left_index, const std::int64_t right_index, const Compare comp)
{
    if (left_index >= right_index)
        return;

    auto pivot = [&arr, left_index, right_index, &comp]() -> std::int64_t
    {
        auto i = left_index - 1;
        auto pivot = arr[right_index];

        for (auto j = left_index; j < right_index; ++j)
        {
            if (comp(arr[j], pivot))
            {
                T temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        T temp = arr[++i];
        arr[i] = arr[right_index];
        arr[right_index] = temp;

        return i;
    }();

    quick_sort(arr, left_index, pivot - 1, comp);
    quick_sort(arr, pivot + 1, right_index, comp);
}

#endif // !QUICK_SORT_HPP