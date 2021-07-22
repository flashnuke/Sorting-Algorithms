#include <iostream>
#include <cmath>
#include "utils.cpp"

template <typename T>
void merge(T* array_ptr, unsigned int first_idx, unsigned int second_idx, unsigned int array_len) // params: array, start index of first array, start index of second array, and array length
{
	// this method iterates over both the sub arrays and creates a new sorted one. Important to pass in this method indices of two already sorted arrays
	unsigned int len_first = second_idx - first_idx; 
	unsigned int len_second = array_len - second_idx; 

	T first_arr[len_first];
	T second_arr[len_second];

	for (unsigned int count = 0; count < len_first; count++) // create new arrays from sub arrays
	{
		first_arr[count] = array_ptr[first_idx + count];
	}
	for (unsigned int count = 0; count < len_second; count++)
	{
		second_arr[count] = array_ptr[second_idx + count]; 
	}
	
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = first_idx; // because we start merging into the beginning of the first array

	while (i < len_first && j < len_second) // while any elements are left in both of the arrays, afterwards insert remainder
	{
		if (first_arr[i] > second_arr[j]) // if array two is smaller
		{
			array_ptr[k] = second_arr[j]; // insert from array two
			j++; // increment array two iteration
		}
		else // array one is smaller
		{
			array_ptr[k] = first_arr[i]; // insert array one
			i++; // increment array one iteration
		}
		k++; // after insertion, increment iteration over the sorted part of the original array
	}

	if (i < len_first) // remaining into array
	{
		array_ptr[k] = first_arr[i];
		i++;
		k++;
	}
	else if (j < len_second) // remaining into array
	{
		array_ptr[k] = second_arr[j];
		j++;
		k++;
	} 
} 

template <typename T>
void merge_sort(T* array_ptr, unsigned int array_len, unsigned int start_idx = 0)
{
        unsigned int div_idx = std::floor(array_len / 2);
       	std::cout << div_idx + start_idx << std::endl;
	 if (div_idx > 1)
        {
                merge_sort<T>(array_ptr, div_idx, start_idx);
                merge_sort<T>(array_ptr, array_len - div_idx, start_idx + div_idx);
        }
        else
        {
                merge<T>(array_ptr, start_idx, start_idx + div_idx, array_len);
        }
}

int main()
{
	int arr[] = { -1, 6, 5, 9, 3, 7, 1, 0, 10 };
	merge_sort<int>(arr, 9);
	print_array<int>(arr, 3);
	
	return 0;
}
