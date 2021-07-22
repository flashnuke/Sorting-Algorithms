#include <iostream>
#include "utils.cpp"

template <typename T>
void insertion_sort(T* array_ptr, unsigned int array_len)
{
	T current_val;
	unsigned int to_swap;
	for (unsigned int idx = 1; idx < array_len; idx++)
	{
		current_val = array_ptr[idx];
		to_swap = idx - 1;
		while (to_swap >= 0 && array_ptr[to_swap] > current_val) // if prev val is bigger
		{
			array_ptr[to_swap + 1] = array_ptr[to_swap]; // move it forward
			--to_swap;
		}
		array_ptr[to_swap + 1] = current_val; // after all big elements have been moved forward, we are left with a duplicate value.
		// The first should be `current_val` that was overwritten
		// in the last last `to_swap + 1` because it gets decremented to -1 after the `while` loop
	}
}

int main()
{
	int arr[] = { -1, 6, 5, 9, 3, 7, 1, 0, 10 };
	insertion_sort<int>(arr, 9);
	print_array<int>(arr, 9);	

	return 0;
}
