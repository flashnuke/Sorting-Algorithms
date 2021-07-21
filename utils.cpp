template <typename T>
void print_array(T* arr_ptr, unsigned int arr_len)
{
        for (unsigned int idx = 0; idx < arr_len; idx++)
        {
                std::cout << arr_ptr[idx] << std::endl;
        }
}
