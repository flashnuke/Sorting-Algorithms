#include <iostream>
#include "utils.cpp"


// TODO 
// 1. return int
// 2. test case where pivot was not moved at all

template <typename T>
int partition(T* array_ptr, unsigned int array_len, unsigned int idx_start) // return int of division point
{
	T* pivot_ptr = &array_ptr[idx_start + array_len - 1]; // always rightmost element
	T* swap_ptr = nullptr; // TODO &array_ptr[idx_start]; 
	T* last_swap_ptr = nullptr; // swap this with pivot at last
	int div_loc = -1; // return value

	T* array_itr = &array_ptr[idx_start];
	while (array_itr < pivot_ptr) // iterate over array
	{
		if (*array_itr <= *pivot_ptr) // if smaller than pivot
		{
			if (swap_ptr) // and found bigger value previously
			{
				std::swap(*array_itr, *swap_ptr); // swap with previously found bigger value
				array_itr = swap_ptr; // set iterator to swapped position to start iterating anew from there - for values that were ignored due to an existing swap ptr
				last_swap_ptr = swap_ptr + 1; // set pivot here at last
				swap_ptr = nullptr; // reset swap_ptr for smaller
			}
		}
		else
		{
			if (!swap_ptr)
			{
				swap_ptr = array_itr; // if smaller is bigger and no swap_ptr was previously set - then set
				last_swap_ptr = swap_ptr;	
			}
		}
		array_itr++;
	}
	if (last_swap_ptr) // swap pivot and return div location only of needed
	{
		std::swap(*last_swap_ptr, *pivot_ptr); // swap if needed. if pivot is bigger than all, no swapping takes place
		div_loc = last_swap_ptr - array_ptr; // return index of division
	}
	return div_loc;
}

template <typename T>
void quick_sort(T* array_ptr, unsigned int array_len, unsigned int idx_start = 0)
{
std::cout << "@" << idx_start << std::endl;
	if (array_len > 1)
	{
		int div_loc = partition<T>(array_ptr, array_len, idx_start);
		if (div_loc > -1)
		{
			quick_sort<T>(array_ptr, div_loc, idx_start);
			quick_sort<T>(array_ptr, array_len - div_loc - idx_start - 1, div_loc);
		}
		else quick_sort<T>(array_ptr, array_len - 1, idx_start);
	}
}

int main()
{
	int arr[] = { -1, 6, 5, 9, 10, -2, 1, 0, 3, 7 };
	//partition<int>(arr, 10, 0);
	quick_sort<int>(arr, 10);
	print_array<int>(arr, 10); 
//	int arrr[] = {2, 1};
//	partition<int>(arrr, 2, 0);
//	print_array<int>(arrr, 2);	

	return 0;
}
