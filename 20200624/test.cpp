#include <iostream>
using namespace std;

class Person {
public:
	void Print() {
		cout << _id << "\t" << _age << endl;
	}

protected:
	int _id = 10;
	int _age = 20;
};

class Student :public Person {
public:
	void show() {
		cout << _id << "\t" << _age << endl;
	}
private:
	int _num;
};

void test() {
	Person p;
	Student st;
	
	//子类对象可以赋值给父类对象/指针/引用
	p = st;
	Person& rs = st;
	Person* ptrs = &st;
	//基类对象不能给派生类对象赋值
	//st = p;
	//基类对象强制类型转换赋值给派生类指针/引用  可能存在越界访问
	//一般不进行强制类型转换，而是采用动态转换 dynamic_cast
	Student& ps = (Student&)p;
	Student* ptr = (Student*)&p;
	//基类的指针可以通过强制类型转换赋值给派生类的指针
	Student& ps2 = (Student&)rs;
	Student* ptr2 = (Student*)ptrs;
}

int atoi(char* str) {
	int number = 0;
	while (*str != 0) {
		number = number * 10 + *str - '0';
		++str;
	}
	return number;
}

class Person {
public:
	//构造函数
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{

	}
	//基类拷贝构造函数
	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{

	}
	//基类的赋值运算符
	Person& operator=(const Person& p) {
		if (this != &p) {
			_id = p._id;
			_age = p._age;
		}
		return *this;
	}
protected:
	int _id;
	int _age;
};
class Student : public Person {
public:
	//子类构造函数
	Student(int id = 20, int age = 40)
		:Person(id, age)
		, _num(id)
	{

	}
	//子类的拷贝构造
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{

	}
	//子类的运算符重载
	Student& operator=(const Student& s) {
		if (this != &s) {
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

protected:
	int _num;
};
int main() {
	/*Person p;
	p.Print();
	Student st;
	st.show();*/
	const char* str = "0325";
	int ret = atoi(str);
	cout << ret << endl;
	return 0;
}
