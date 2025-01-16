# ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, int length, void (*func)(T&))
{
    for (int i = 0; i < length; ++i) 
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T* array, int length, void (*func)(const T&)) 
{
    for (int i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif