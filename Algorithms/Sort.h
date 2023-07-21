#ifndef SORT_H
#define SORT_H

template <typename T, typename Compare>
constexpr void insertion_sort(T* const arr, const size_t size, const Compare comp)
{
	for (auto i = 1; i < size; ++i)
	{
		const T key = arr[i];
		auto j = i - 1;

		while (j >= 0 && !comp(arr[j], key))
		{
			arr[j + 1] = arr[j];
			arr[j--] = key;
		}
	}
}

template <typename T, typename Compare>
constexpr void merge_sort(T* const arr, const size_t left_index, const size_t right_index, const Compare comp)
{
	if (left_index >= right_index)
		return; // zero or one element

	const auto q = (left_index + right_index) / 2;

	merge_sort(arr, left_index, q, comp); // beginning - middle of arr
	merge_sort(arr, q + 1, right_index, comp); // middle - end of arr

	[](T* const arr, const size_t left, const size_t mid, const size_t right, const Compare comp)
	{
		const auto n1 = mid - left + 1;
		const auto n2 = right - mid;

		// create temp arrays
		T* const left_arr = new T[n1];
		T* const right_arr = new T[n2];

		// copy data to temp left array
		for (auto i = 0; i < n1; ++i)
			left_arr[i] = arr[left + i];

		// copy data to temp right array
		for (auto j = 0; j < n2; ++j)
			right_arr[j] = arr[mid + 1 + j];

		auto i = 0, j = 0;
		auto k = left;

		// merge the temp arrays back into arr[left..right]
		while (i < n1 && j < n2)
		{
			if (comp(left_arr[i], right_arr[j]))
				arr[k++] = left_arr[i++];
			else
				arr[k++] = right_arr[j++];
		}

		// copy the remaining elements of left array
		while (i < n1)
			arr[k++] = left_arr[i++];

		// copy the remaining elements of right array
		while (j < n2)
			arr[k++] = right_arr[j++];

		delete[] left_arr;
		delete[] right_arr;
	}(arr, left_index, q, right_index, comp);
}

#endif // !SORT_H