#include <iostream>
#include "utils.cpp"

template <typename T>
void bubble_sort(T* array_ptr, unsigned int array_len)
{
	unsigned int iterations{ 0 };
	while(iterations < array_len)
	{
		for (unsigned int idx = 0; idx < array_len - 1 - iterations; idx++) // array_len - 1
		{
			if(array_ptr[idx] > array_ptr[idx + 1]) std::swap(array_ptr[idx], array_ptr[idx + 1]);
		}
	++iterations;
	}
}

template <typename T>
void bubble_sort_efficient(T* array_ptr, unsigned int array_len)
{
        bool has_swapped = false;
	unsigned int iterations{ 0 };
        while(iterations < array_len)
        {
		has_swapped = false;
                for (unsigned int idx = 0; idx < array_len - 1 - iterations; idx++) // array_len - 1
                {
                        if(array_ptr[idx] > array_ptr[idx + 1])
			{
				std::swap(array_ptr[idx], array_ptr[idx + 1]);
               			has_swapped = true;
			}
		 }
	if (!has_swapped) break;
        ++iterations;
        }
}

int main()
{
	int arr[] = { -1, 6, 5, 9, 3, 7, 1, 0, 10 };
	bubble_sort<int>(arr, 9);
	print_array<int>(arr, 9);
	
	return 0;
}
