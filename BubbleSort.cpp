#include <iostream>

template <typename T>
void print_array(T* array_ptr, unsigned int array_len)
{
	for (unsigned int idx = 0; idx < array_len; idx++)
	{
		std::cout << array_ptr[idx] << std::endl;
	}
}

template <typename T>
void bubble_sort(T* array_ptr, unsigned int array_len)
{
	for (unsigned int idx = 0; idx < array_len - 1; idx++) // array_len - 1
	{
		if(array_ptr[idx] > array_ptr[idx + 1]) std::swap(array_ptr[idx], array_ptr[idx + 1]);
	}
}

int main()
{
	int arr[] = { 6, 3, 7, 9, 8, 11 };
	bubble_sort<int>(arr, 6);
	print_array<int>(arr, 6);
	
	return 0;
}
