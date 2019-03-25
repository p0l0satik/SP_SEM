struct A
{
    virtual bool equals(A *pa) = 0;
};

struct B : A
{
    int value;
    // void fight(B *pb) - нельзя ибо другая функиция
    bool equals(A *pa) override{
        if(!pa) {
            return false;
        } else if (B *pb = dynamic_cast<B *>(pa); pb){ //есди приведется то не нулль - иф проверяет
            return value == pb->value;
        } else {
            return false;
        }

    }

};
