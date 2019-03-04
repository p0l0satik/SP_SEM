#include <iostream>
#include <string>

struct Rational {
private:
    int a, b;
    int gcd (int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
    void shrt() {
        if (a < 0 && b < 0) {
            a = -a;
            b = -b;
        }
        int divider = gcd(abs(this->a), abs(this->b));
        if (divider) {
            this->a /= divider;
            this->b /= divider;
        }


    }
public:
    Rational (int x = 0, int y = 1): a(x), b(y) {
        shrt();
    }

    Rational & Add(const Rational &q) {
        a = a * q.b + b * q.a;
        b *= q.b;
        shrt();
        return *this;
    }

    Rational & Substract(const Rational &q) {
        a = a * q.b - b * q.a;
        b *= q.b;
        shrt();
        return *this;
    }

    Rational & Multiply(const Rational &q) {
        a = a * q.a;
        b = b * q.b;
        shrt();
        return *this;
    }

    Rational & Divide(const Rational &q) {
        int tmp_ch = a * q.b;
        int tmp_zn = b * q.a;

        a = tmp_ch;
        b = tmp_zn;
        shrt();
        return *this;
    }

    std::string ToString() const {
        return std::to_string(a) + ":" + std::to_string(b);
    }

    bool EqualTo(const Rational &q) const {

        return (a == q.a && b == q.b) || (a == -q.a && b == -q.b);
    }
    int CompareTo(const Rational &q) const {
        if ((b > 0 && q.b > 0) || (b < 0 && q.b < 0)) {
            return a * q.b - b * q.a;
        }
        return b * q.a - a * q.b;
    }
    bool IsInteger() const {
        return b == 1 || b == -1;
    }

};
