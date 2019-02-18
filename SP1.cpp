// RAII - (resource acquisition is initiation) - захват - это инициализация(неправда);
// rce resource is destruction - правильно - освобождение при уничтожении

// g++ -Wall -Werror -std=gnu++17 str.cpp -str
// -g???
//-o2???
//-o3????

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

//uniform initializer
int size;
struct String //не должно быть class?? - все поля private 
{
    // UI 
    //size_t size{};
    //char *str{};
    //МАЙНКРАААААААФТ ЭТО МОЯ ЖИЗНЬ!!!!!!!!!!
private:
    size_t size = 0;
    char *str = nullptr;
public:   
    /*
                String()// String *this | в реальности один параметр this для реализации, можно опускать для удобства
                {
                    /*
                        //локальные переменные - параметр-если часть класса там
                        int size = 10;
                        this->size = 0;
                        //String:: - квалификатор области видимости
                        //String:: size
                        ::size = 100; // к глобальной

                        str = nullptr; // нулевой указатель; тип nullptr_t

                    
                    printf("String()\n");
    }

    */
    String() = default; // говорим явно чтоб сделал конструктор по умолчанию, delete удалить конструктор по умолчанию
    String(const char *str)
    {
        if (str) {
            String:: size = strlen(str);
            String:: str = new char[String:: size + 1];
            memcpy(String:: str, str, String:: size + 1); // узнай что это и не используй(побайтовое низкоуровневое), std::copy
        }
    }
            // String(const String &s) = delete; // запрещаем копирование, default -  по умолчанию, не делай
            //ссылка: УТОЧНИ! указатель без звездочкии
    String(const String &s) :size {s.size}, str{s.str} // перекрыввет инициализацию идут в том же порядке можно опустить,
            // НУЖНЫ ДЛЯ ВЫЗОВА ЛЮБОГО КОНСТРУКТОРА ВЛОЖЕННОГО ОБЪЕКТА
            // String *this, const String &s
    {
        // size = s.size;
        // str = s.str;
        if (str) {
            str = new char[size + 1];
            memcpy(str, s.str, size + 1);
        }

    }
    // delete запретили присваивание
    /*
                    String &operator =(const String &s)
                    {
                        // Присваивание самому себе ыыыы
                        if (this == &s) return *this;
                        //деструктор
                        delete[] str;
                        //конструктор
                        str = s.str;
                        size = s.size;
                        if (str) {
                            str = new char[size + 1];
                            memcpy(str, s.str, size + 1);
                        }
                        return *this; //звездочка - для согласование типов: ссылка и указатель
                    } 
    */
    void swap(String &s)
    {
        std::swap(size, s.size);
        std::swap(str, s.str);
    }
    //ИДИОМА copy & swap 
    //КОЛДУНСТВО
    String &operator =(String s) // передача по значению вызовет конструктор копирования(содаст ДП и тд)
    {
        swap(s); // поменяли строку и this
        //уничтожаем s при выходе из блока, тем самым вызывая деструктор для объекта
        return *this;
    }
   // \КОЛДУНСТВО
    ~String()
    {   // деструкторы вызываются в порядке обратном вызове конструкторе
        delete[] str;// скобки не забудь ибо delete/new != delete[]/new[]
    }

    //если const то const String *this; применимы к константным объектам, неконстантные только к неконстантным объектам

    size_t get_size() const
    {
        return size;
    }
    const char *c_str() 
    {
        return str;
    }

    void append(char c);
    void append(char c, int cnt);
    void append(char c);

    void append(const char *str);
};

String f(String str) {
    printf("%s\n", str.str);
    return str;
}

void init_string(String *dst, const char *str)
{
    dst->str = strdup(str); // выделение памяти в куче. расшарить функцию
    dst->size = strlen(str);
}

String s2;

int main()
{   
    String s1;
    init_string(&s1, "abc");
    String *s4 = new String; //new - атомарная комбинация маллока и вызова конструктона на выделенную память

    String s5[16]; //локально память, конструктор для каждого
    String *s6 = new String[8]; // освобождать надо явно!!!!!!!!! с помощью delete[]


    static String s7{"7"}; //!!!! если внутри блока конструктор вызывается когда управление попадает первый раз в эту точку!!!!

    free(s1.str);
    //конструктор с параментрамиЖ
    String s8("abbb");
    String s9 = String("Asafadfc");
    String s10{xxx};

    f(s[10]); //упадет
    String s11 = s9;
    String s12 = f(s7);
    //ситуация копирование объекта в другой объект - конструктор копирования
    s11 = s8;
    s7 = s7;
    return 0;
}