export module SelectionSort;
import std;

export template <typename T, typename Compare>
constexpr void selection_sort(T* const arr, const std::size_t size, const Compare comp)
{
	if (size <= 1)
		return; // already sorted

	auto min = 0;

	for (auto i = 0; i < size; ++i)
	{
		min = i;

		for (auto j = i + 1; j < size; ++j)
		{
			if (comp(arr[j], arr[min]))
				min = j;
		}

		if (min != i)
		{
			const T temp = arr[min];

			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}