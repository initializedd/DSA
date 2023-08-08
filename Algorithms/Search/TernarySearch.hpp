#ifndef TERNARY_SEARCH_HPP
#define TERNARY_SEARCH_HPP

#include <cstddef>
#include <optional>

template <typename T, const std::size_t N>
[[nodiscard]] auto ternary_search(const T (&arr)[N], T value) noexcept -> const std::optional<const std::size_t>
{
	std::size_t left_index = 0;
	auto right_index = N;

	while (right_index > 0)
	{
		auto left_middle = left_index + (right_index - 1) / 3;
		auto right_middle = right_index - (right_index - 1) / 3;

		if (arr[left_middle] == value)
			return left_middle;
		
		if (arr[right_middle] == value)
			return right_middle;

		if (arr[left_middle] > value)
		{
			right_index = right_middle - 1;
			continue;
		}
		
		if (arr[right_middle] < value)
		{
			left_index = left_middle + 1;
			continue;
		}

		left_index = left_middle + 1;
		right_index = right_middle - 1;
	}

	return std::nullopt;
}

#endif // !TERNARY_SEARCH_HPP