export module BubbleSort;
import std;

export template <typename T, typename Compare>
constexpr void bubble_sort(T* const arr, const std::size_t size, const Compare comp)
{
	if (size <= 1)
		return; // already sorted

	bool swapped = false;

	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size - i - 1; ++j)
		{
			if (comp(arr[j + 1], arr[j]))
			{
				const T temp = arr[j];

				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				swapped = true;
			}
		}

		if (!swapped)
			break; // no elements were swapped
	}
}