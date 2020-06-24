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
	
	//���������Ը�ֵ���������/ָ��/����
	p = st;
	Person& rs = st;
	Person* ptrs = &st;
	//��������ܸ����������ֵ
	//st = p;
	//�������ǿ������ת����ֵ��������ָ��/����  ���ܴ���Խ�����
	//һ�㲻����ǿ������ת�������ǲ��ö�̬ת�� dynamic_cast
	Student& ps = (Student&)p;
	Student* ptr = (Student*)&p;
	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
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
	//���캯��
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{

	}
	//���࿽�����캯��
	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{

	}
	//����ĸ�ֵ�����
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
	//���๹�캯��
	Student(int id = 20, int age = 40)
		:Person(id, age)
		, _num(id)
	{

	}
	//����Ŀ�������
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{

	}
	//��������������
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
