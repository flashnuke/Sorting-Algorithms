template <typename T>
void print_array(T* array_ptr, unsigned int array_len)
{
        for (unsigned int idx = 0; idx < array_len; idx++)
        {
                std::cout << array_ptr[idx] << std::endl;
        }
}
