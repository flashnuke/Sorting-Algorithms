#include <iostream>
#include "utils.cpp"

template <typename T>
void quiok_sort(T* array_ptr, unsigned int array_len)
{}

int main()
{
	int arr[] = { -1, 6, 5, 9, 3, 7, 1, 0, 10 };
	quick_sort<int>(arr, 9);
	print_array<int>(arr, 9);

	return 0;
}
