#include <stdio.h>
#include <math.h>
namespace numbers
{
    class complex
    {   
    private:
        double real, imag;
    public:
        complex(double a = 0, double b = 0): real(a), imag(b){}
        explicit complex(const char *string)
        {
            sscanf(string, "(%lf,%lf)", &real, &imag);
        }
        double get_re() const
        {
            return real;
        }
        double get_im() const
        {
            return imag;
        }
        double abs2() const
        {
            return (real * real + imag * imag);
        }
        double abs() const
        {
            return sqrt(abs2());
        }
        void to_string(char *buf, size_t size) const
        {
            snprintf(buf, size, "(%.10g,%.10g)", real, imag);
        }
        friend complex operator + (const complex &a, const complex &b);
        friend complex operator - (const complex &a, const complex &b);
        friend complex operator * (const complex &a, const complex &b);
        friend complex operator / (const complex &a, const complex &b);
        friend complex operator ~ (const complex &a);
        friend complex operator - (const complex &a);
        
    };
    complex operator ~ (const complex &a)
    {
        return complex(a.real, -a.imag);
    }

    complex operator - (const complex &a)
    {
        return complex(-a.real, -a.imag);
    }

    complex operator+(const complex &a, const complex &b)
    {
        return complex(a.real + b.real, a.imag + b.imag);
    }
    complex operator - (const complex &a, const complex &b)
    {
        return complex(a.real - b.real, a.imag - b.imag);
    }
    complex operator * (const complex &a, const complex &b)
    {
        return complex(a.real * b.real - a.imag * b.imag, a.imag * b.real + b.imag * a.real);
    }
    complex operator / (const complex &a, const complex &b)
    {
        return complex((a.real * b.real + a.imag * b.imag) / b.abs2(), (b.real * a.imag - a.real * b.imag) / b.abs2());
    }

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

    complex eval(char **args, const complex &z)
    {
        int t = 0;
        complex_stack stack;
        while(args[t])
        {
            switch (args[t][0])
            {
                case 'z':
                {
                    stack = stack << z;
                    break;
                }
                case '+':
                {
                    complex arg2 = +stack;
                    stack = ~stack;
                    complex arg1 = +stack;
                    stack = ~stack;
                    stack = stack << (arg1 + arg2);
                    break;
                }
                case '-':
                {
                    complex arg2 = +stack;
                    stack = ~stack;
                    complex arg1 = +stack;
                    stack = ~stack;
                    stack = stack << (arg1 - arg2);
                    break;
                }  
                case '*':
                {
                    complex arg2 = +stack;
                    stack = ~stack;
                    complex arg1 = +stack;
                    stack = ~stack;
                    stack = stack << (arg1 * arg2);
                    break;
                } 
                case '/':
                {
                    complex arg2 = +stack;
                    stack = ~stack;
                    complex arg1 = +stack;
                    stack = ~stack;
                    stack = stack << (arg1 / arg2);
                    break;
                } 
                case '!':
                {
                    stack = stack << (+stack); 
                    break;
                } 
                case ';':
                {
                    stack = ~stack;
                    break;
                } 
                case '~':
                {
                    complex temp = +stack;
                    stack = ~stack;
                    stack = stack << ~temp;
                    break;
                } 
                case '#':
                {
                    complex temp = +stack;
                    stack = ~stack;
                    stack = stack << -temp;
                    break;
                } 
                default:
                {
                    stack = stack << complex(args[t]);
                }

            }
            t++;
        }
        return +stack;
    }
}
double get_arg(int k, int n){
    return ((double) k + 1/2) * 2 * M_PI / n;
}

int main(int argc, char **argv) {
    numbers::complex c(argv[1]);
    double r;
    sscanf(argv[2], "%lf", &r);
    int n;
    sscanf(argv[3], "%d", &n);
    numbers::complex koef(2 * M_PI * r / n, 0);
    numbers::complex sum;

    for (int k = 0; k < n; k++) 
    {
        double arg = get_arg(k, n);
        numbers::complex z(r * cos(arg), r * sin(arg));
        z = z + c;
        sum = sum + numbers::eval(argv + 4, z) * numbers::complex(-sin(arg), cos(arg)); 
    }
    sum = sum * koef;    
    printf("%lf %lf", sum.get_re(), sum.get_im());
    return 0;
}



