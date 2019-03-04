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
}