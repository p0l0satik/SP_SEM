#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Контейнеры
// vector
// list - двусвязный список
// forward_list
// deque  - и в начало и в конец можно добавлять

// array -  фиксированный на этапе компиляции массив
// string
// элементы с одинаковыми значением[multi]set - двоичное дерево поиска(обычно - красночерное); множество
// map - ассоциативный массив, тож массив
// unordered_set[map] хэщ таблички - нужны хэши, сравнение на эквивалентность

class MyVector {
	std::string *buf;
	int size, capacity;
  public:
	MyVector() {
		size = 0;
		capacity = 0;
	}

	void push_back(const std::string& s) {
		if (size >= capacity) {
			//bad code
			capacity = 2 * capacity + 1;
			// std::string *buf = new std::string[capacity]; //создать capacity новых объектов - ЗЛО!
			std:: string *tmp = malloc(sizeof(std::string) * capacity);
			for (int i = 0; t < size; ++i) {
				new(tmp + i) std::string(buf[1]);// над куском выделяем конструктор
				// tmp[i] = buf[i]; // c malloc так нельзя
			}
			//основная идея - не вызывать контсруктор для пустой памяти!!!
			for (int i = 0; i < size; ++i) {
				buf[i].~string();
			}
			free(buf)
			// delete[] buf;
			buf = tmp;
		}
		new (buf + size) string(s);
	}
	int *begin() {
		return buf;
	}

	int *end() {
		return buf + size;
	}
};

int main() {
	std::vector<int> v = {1, 4, 5}; //v(3)

	for (auto  elem : v) {
		std::cout << elem;
	}
	std::cout << endl;
	v.push_back(4);//O(n) выделить больше кусок, скопировать, добавить элемент. место есть 0(1). Итого 0(1)
	//в середину О(N)
	// в списке O(1)
	//в array нельзя добавить
	//

	/*итераторы
	// [) полуоткрытые диапазаоны
	// begin, end - указатели на начало ик онец контейнера
	//
	it = v.begin()
	it++;

		RundomAccessIter
		Iter
		++
		--
		*
		+=
		<

		Bidirectional
		для списка
		++
		--
		*
		-------------
		+= запрещенно чтоб ты не думал что O(1)



		Forward
		++*


		реверс итератор
		rbegin
		rend

		input/output итераторы - что це за


		итератор может указывать только на элемент или на следующий с конца, иначе undefined behaviour
	*/

	for (auto  elem : v) {
		std::cout << elem;
	}
	std::cout << endl;

	MyVector v1;

	/*
	struct t
	{
		int a, b;
	};
	v1.push_back(t{1,2});
	v1.emplace_back(1, 2); // не хотим временный объект

	*/

	for (auto elem : v1) {
		std::cout << elem;
	}
	std::cout << endl;

	std::sort(v1.begin(), v1.end());

	for (auto elem : v1) {
		std::cout << elem;
	}
	std::cout << endl;

	//reverse

	std::sort(v.rbegin(), v.rend());
	for (auto elem : v) {
		std::cout << elem;
	}
	std::cout << endl;


	for (auto it = v.begin(); it < v.end(); it += 3) {
		std::cout << *it;
	}
	std::cout << endl;
//=
//=
	for (vector<int>::const_iterator it = v.begin(); it < v.end(); it += 3) {
		std::cout << *it;
	}
	std::cout << endl;

	auto it = v.begin();
	for (int i = 0; i < 100; ++i) {
		v.push_back(5);
	}
	// std::cout << *it; - он стал говном ибо память съъехала


	std::cout << v.size() << std::endl; //number of elemnts
	std::cout << v.capacity() << std::endl; //size of array

	v.reserve(1000); // выделяет доп память под элементы чтоб добавлять хорошо
	v.resize(10); // изменяет размер - с удалением - но память от резерва остается
	v.shrink_to_fit(); // возращает резер памяти
	std::cout << v.capacity() << std::endl; //size of array


	// стандартные алгоритмы не меняют режимы контейнеров
	//ы
	return 0;
}