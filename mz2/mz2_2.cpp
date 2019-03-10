#include <stdio.h>
#include <math.h>
namespace numbers
{
    
    class complex_stack
    {
        complex* arr;
        size_t size_arr;
        size_t len;
        enum
        {
            MULTIPLIER = 2
        };

        void extend()
        {
            size_arr *= MULTIPLIER ;
            complex *new_arr = new complex[size_arr];
            for (size_t t = 0; t < len; ++t)
            {
                new_arr[t] = arr[t];
            }

            delete[] arr;
            arr = new_arr;
            
        }
    public:
        complex_stack(): size_arr(1), len(0)
        {
            arr = new complex[1];
        } 

        complex_stack(const complex_stack &cpy)
        {
            size_arr = cpy.size_arr;
            len = cpy.len;
            arr = new complex[size_arr];
            for (size_t t = 0; t < len; ++t)
            {
                arr[t] = cpy.arr[t];
            }
        }

        complex_stack operator = (const complex_stack &cpy)
        {
            if (this != &cpy) 
            {
                delete[] arr;
                size_arr = cpy.size_arr;
                len = cpy.len;
                arr = new complex[size_arr];
                for (size_t t = 0; t < len; ++t)
                {
                    arr[t] = cpy.arr[t];
                }
            }
            return *this;
        }

        size_t size() const
        {
            return len;
        }

        complex &operator[](size_t n) const
        {
            return arr[n];
        }

        ~complex_stack(){
            delete[] arr;
        }

        

        complex_stack operator <<(complex elem) const 
        {
            complex_stack n_stack = *this;
            if (size_arr == len)
            {
                n_stack.extend();
            }

            n_stack.arr[n_stack.len] = elem;
            ++n_stack.len;
            return n_stack;
        }

        complex & operator +() const
        {
            return arr[len - 1];
        }

        complex_stack operator ~() const
        {
            complex_stack n_stack = *this;
            --n_stack.len;
            return n_stack;
        }
        
    };
}
