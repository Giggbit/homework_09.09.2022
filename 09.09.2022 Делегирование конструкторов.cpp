#include <iostream>
using namespace std;

class Book {
	char* name;
	int pages;
public:
	Book();
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};

Book::Book() {
	name = nullptr;
	pages = 0;
}
Book::Book(const char* n) :Book() {
	int str = strlen(n) + 1;
	name = new char[str];
	strcpy_s(name, str, n);

	pages = 0;
}
Book::Book(const char* n, int p) :Book(n) {
	pages = p;
}
void Book::Print() {
	cout << "Name: " << '"' << name << '"' << "\nPages: " << pages << " p." << endl;
}
Book::~Book() {
	delete[] name;
}




class Student {
private:
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	void Print();
};

Student::Student() :step(0) {
	name = nullptr;
}
Student::Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages) {
	int strn = strlen(n) + 1;
	name = new char[strn];
	strcpy_s(name, strn, n);
}
void Student::Print() {
	cout << "Student: " << name << "\nStepuha: " << step << "\n";
}



int main() {
	Book s("We are", 255);
	s.Print();

	cout << endl;

	Student st("Daniil", 1500, "We are", 255);
	st.Print();

}
