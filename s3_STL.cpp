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

class MyVector
{
	int buf[10];
	int size;
public:
	MyVector(std::initializer_list<int> val) 
	{
		int i = 0;

		for (auto elem : val)
		{
			buf[i] = elem;
			++i;
		}
		size = val.size();
	}

	int *begin()
	{
		return buf;
	}

	int *end()
	{
		return buf + size;
	}
};

int main() {
	std::vector<int> v = {1, 4, 5}; //v(3)

	for(auto  elem: v) 
	{
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

	for(auto  elem: v) 
	{
		std::cout << elem;
	}
	std::cout << endl;
	MyVector v1{1, 4, 3};

	for (auto elem: v1)
	{
		std::cout << elem;
	}
	std::cout << endl;

	std::sort(v1.begin(), v1.end());

	for (auto elem: v1)
	{
		std::cout << elem;
	}
	std::cout << endl;

	//reverse

	std::sort(v.rbegin(), v.rend());
	for (auto elem: v)
	{
		std::cout << elem;
	}
	std::cout << endl;


	for(auto it = v.begin(); it < v.end(); it += 3)
	{
		std::cout << *it;
	}
	std::cout << endl;
//=
//=
	for(vector<int>::const_iterator it = v.begin(); it < v.end(); it += 3)
	{
		std::cout << *it;
	}
	std::cout << endl;

	auto it = v.beign();
	v.push_back(5);
	std::cout << *it;
	
	return 0;
}