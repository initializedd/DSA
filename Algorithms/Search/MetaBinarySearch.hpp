#ifndef META_BINARY_SEARCH_HPP
#define META_BINARY_SEARCH_HPP

#include <cstddef>
#include <cmath>
#include <optional>

template <typename T, const std::size_t N>
[[nodiscard]] auto meta_binary_search(const T (&arr)[N], const T value) noexcept -> const std::optional<const std::size_t>
{
	int lg = std::log2(N - 1) + 1;
	auto index = 0;

	for (auto i = lg; i >= 0; --i)
	{
		if (arr[index] == value)
			return index;

		auto new_index = index | (1 << i);

		if (new_index < N && arr[new_index] <= value)
			index = new_index;
	}

	if (arr[index] == value)
		return index;

	return std::nullopt;
}

#endif // !META_BINARY_SEARCH_HPP