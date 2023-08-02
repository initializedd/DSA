#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <cstddef>
#include <optional>

template <typename T, const std::size_t N>
const std::optional<const std::size_t> binary_search(const T (&arr)[N], const T value)
{
    std::size_t left_index = 0;
    std::size_t right_index = N - 1;

    while (left_index <= right_index)
    {
        auto middle = (left_index + right_index) / 2;

        if (arr[middle] > value)
        {
            right_index = middle - 1;
        }
        else if (arr[middle] < value)
        {
            left_index = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return std::nullopt;
}

#endif // !BINARY_SEARCH_HPP