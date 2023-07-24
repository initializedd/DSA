export module InsertionSort;
import std;

export template <typename T, typename Compare>
constexpr void insertion_sort(T* const arr, const std::size_t size, const Compare comp)
{
	if (size <= 1)
		return; // already sorted

	for (auto i = 1; i < size; ++i)
	{
		const T key = arr[i];
		auto j = i - 1;

		while (j >= 0 && comp(key, arr[j]))
		{
			arr[j + 1] = arr[j];
			arr[j--] = key;
		}
	}
}