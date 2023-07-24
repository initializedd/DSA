export module MergeSort;
import std;

export template <typename T, typename Compare>
constexpr void merge_sort(T* const arr, const std::size_t left_index, const std::size_t right_index, const Compare comp)
{
	if (left_index >= right_index)
		return; // zero or one element

	const auto q = (left_index + right_index) / 2;

	merge_sort(arr, left_index, q, comp); // beginning - middle of arr
	merge_sort(arr, q + 1, right_index, comp); // middle - end of arr

	[&arr, left_index, right_index, &comp](const std::size_t mid)
	{
		const auto n1 = mid - left_index + 1;
		const auto n2 = right_index - mid;

		// create temp arrays
		T* const left_arr = new T[n1];
		T* const right_arr = new T[n2];

		// copy data to temp left array
		for (auto i = 0; i < n1; ++i)
			left_arr[i] = arr[left_index + i];

		// copy data to temp right array
		for (auto j = 0; j < n2; ++j)
			right_arr[j] = arr[mid + 1 + j];

		auto i = 0, j = 0;
		auto k = left_index;

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
	}(q);
}