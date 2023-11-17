#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include <execution>
#include <omp.h>

using namespace std;

int RandFilling()
{
	return (-500 + rand() % 1500);
}

template <typename T>
void fill_container(T& container)
{
	generate(container.begin(), container.end(), RandFilling);
}

template <typename T>
void print(T& container)
{
	for (auto i = container.cbegin(); i != container.cend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

bool is_negative(int n) { return n < 0; }

void List(int size)
{
	list <int> new_list(size, 0);
	clock_t start = clock();
	fill_container(new_list);
	//print(new_list);

	//std::execution::par - дл€ параллельного выполнени€
	//std::execution::seq - дл€ поледовательного выполнени€ 
	//stg::execution::par_unseq - векторизированное (параллельно и векторно)

	new_list.erase(remove_if(new_list.begin(), new_list.end(), is_negative), new_list.end());

	clock_t end = clock();
	//print(new_list);
	cout << "¬рем€ выполени€ дл€ List = " << double(end - start) / CLOCKS_PER_SEC << " c" << endl;
}

int main()
{
	int n = 1000000;
	setlocale(LC_ALL, "ru");
	srand(time(0));

	//int size;
	cout << "¬ведите размер:  "<< n << endl;
	//cin >> size;

	cout << "„исло потоков: " << omp_get_num_procs() << endl;

	List(n);

	return 0;
}