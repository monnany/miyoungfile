#include <iostream>
#include <list>

using namespace std;

int main(){

	list<int> l;

	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);

	l.pop_back();

	l.push_front(4);
	l.push_front(3);
	l.push_front(1);
	l.push_front(0);

	l.pop_front();

	cout << "list front value : " << l.front() << '\n';
	cout << "list end value : " << l.back() << '\n';
	cout << "list size : " << l.size() << '\n';
	cout << "Is it empty? : " << (l.empty() ? "Yes" : "No") << '\n';

	list<int>::iterator begin_iter = l.begin(); // auto begin_iter = l.begin()도 가능
	list<int>::iterator end_iter = l.end(); // auto end_iter = l.end()도 가능

	begin_iter++; // 2번째를 가리키는 iterator
	l.insert(begin_iter, 2);

	end_iter--; // 마지막 원소를 가리키는 iterator
	l.erase(end_iter);

	// *iterator : 원소 접근
	cout << "list "<< distance(l.begin(), begin_iter)+ 1 << " element : " << *begin_iter << '\n';

	return 0;

}