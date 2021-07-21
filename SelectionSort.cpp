#include <iostream>
#include "utils.cpp"

template <typename T>
void selection_sort(T* array_ptr, unsigned int array_len)
{
	T min_val_idx;
	for (unsigned int idx = 0; idx < array_len - 1; idx++)
	{
		min_val_idx = idx;
		for (unsigned int i_idx = idx + 1; i_idx < array_len; i_idx++)
		{
			if (array_ptr[i_idx] < array_ptr[min_val_idx]) min_val_idx = i_idx;	
		}
		std::swap(array_ptr[idx], array_ptr[min_val_idx]);
	}
}

int main()
{
	int arr[] = { -1, 6, 5, 9, 3, 7, 1, 0, 10 };
	selection_sort<int>(arr, 9);
	print_array<int>(arr, 9);

	return 0;
}
