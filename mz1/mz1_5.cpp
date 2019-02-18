struct Rational
{
    int a, b;
    Rational (int a, int b) {
        this->a = a;
        this->b = b;
    }

    void Add(Rational q) {
        this->a += q.a;
        this->b += q.b;
        shrt(q);
    }

    void Substract(Rational q) {
        this->a -= q.a;
        this->b -= q.b;
        shrt(q);
    }
    
    void Substract(Rational q) {
        this->a -= q.a;
        this->b -= q.b;
        shrt(q);
    }

private:
    int gcd (int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
    void shrt(Rational &q) 
    {
        int divider = gcd(q.a, q.b);
        q.a /= divider;
        q.b /= divider;
    }
}