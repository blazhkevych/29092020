//асоціативні контейнери
//set 
//multiset
//pair (first, second)
//map (червоно чорне дерево)
#include <iostream>
#include <set>
#include <map>
using namespace std;

class MyComp {
public:
	bool operator()(int a, int b)const {
		return a > b;
	}
};

template <class T, class U>
ostream& operator << (ostream& os, set<T, U>& d) {
	for (auto el : d)
		cout << el << '\t'; cout << endl;
	return os;
}

bool Comp_func(int a, int b) {
	return a > b;
}

bool (*ptrF)(int a, int b) = Comp_func;

typedef bool (*Typetmp)(int a, int b);

auto fun = [](int a, int b) {return a > b; };

void Test1() {
	set<int> s1;
	set<int> s2{ 10, 50, 20, 30 };
	cout << s2;
}

void Test2() {
	set<int, MyComp> s3{ 3,10,5,20,-5 };
}

void Test3() {
	set<int, bool(*)(int a, int b)> s4(Comp_func);
	for (size_t i = 0; i < 10; i++) {
		s4.insert(rand() % 50);
	}
	cout << s4;
}

void Test4() {
	set<int, Typetmp>s4(Comp_func);
}

void Test5() {
	set <int, Typetmp>s5(fun);
	for (size_t i = 0; i < 10; i++) {
		s5.insert(rand() % 50);
	}
	cout << s5;
}

void Test6() {
	set <int, decltype (fun)>s6(fun);
	for (size_t i = 0; i < 10; i++) {
		s6.insert(rand() % 50);
	}
	cout << s6;
}

void Test7() {
	set<int> s10{ 10,5,30,20,15 };
	s10.erase(30);//видалення елементу
	cout << s10; cout << endl;
	s10.erase(s10.begin());
	cout << s10; cout << endl;
}

void Test8() {
	set<int> s10{ 10,5,30,20,15 };
	int k = s10.count(30);
	cout << k; cout << endl;
}

void Test9() {
	set<int> s10{ 10,5,30,20,15 };
	auto it = s10.find(10);
	s10.erase(it, s10.end()); // з 10 до кінця
	cout << s10; cout << endl;
}

void Test10() {
	set<int> s10{ 10,5,30,20,15 };
	auto it = s10.find(16);
	if (it == s10.end())
		cout << "Not founded";
}

void Test11() {
	set<int> s10{ 10,5,30,20,15 };
	auto p = s10.equal_range(60);// повертаємо елемент слідуючий за ним, якщо є
	cout << *p.first; cout << endl;
	cout << *p.second; cout << endl;
}

void Test12() {
	set<int> s10{ 10,5,30,20,15 };
	auto it = s10.lower_bound(16);
	cout << *it; cout << endl;
}

void Test13() {
	set<int> s10{ 10,5,30,20,15 };
	auto it = s10.upper_bound(16);
	cout << *it; cout << endl;
}

void Test14() {
	set <int> sr;
	for (size_t i = 0; i < 1000000; i++)
		sr.insert(rand());
	cout << sr.size() << endl; // 32768
	cout << sr << endl; //32767
}

void Test15() {
	map<string, int> m;// ключ, значення, компаратор
	m["Piter"] = 10;
	m["Peter"] = 20;
	auto it = m.insert(pair<string, int>("Ira", 10));
	for (auto a : m)
		cout << a.first << " " << a.second << endl;
	if (it.second == false)
		cout << "Element vzhe e" << endl;
}

int main() { //вказівник на текстову строку, кількість параметрів
	Test15();
}