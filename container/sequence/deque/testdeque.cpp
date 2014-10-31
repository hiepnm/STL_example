/*
 * main.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: hiep
 */

#include <deque>
#include <iostream>
#include <vector>
class student {
private:
	static int number_student;
	int student_no;
public:
	student():student_no(++number_student) {}
	student(int id) {
		student_no = id;
		++number_student;
	}
	student(const student& s) {
		student_no = s.student_no;
//		std::cout << "Sao chep: student co Id: " << student_no << std::endl;
	}
	void showId () {
		std::cout << student_no;
	}
	int getId() const {
		return student_no;
	}
	void setId(int id) {
		student_no = id;
	}
	virtual ~student() {
//		std::cout << "Huy: student co id " << student_no << std::endl;
	}
	int operator == (const student& s) {
		return student_no == s.student_no;
	}

	friend std::ostream& operator << (std::ostream& out, const student& s);
};
std::ostream& operator << (std::ostream& out, const student& s) {
	return out << s.student_no;
}
int student::number_student = 0;
int main(int argc, char **argv) {
	std::deque<student> student_deque;
	for (int i = 0; i < 3; ++i) {
		student_deque.push_back(student());
	}
	for (int i = 0; i < 3; ++i) {
		student_deque.push_front(student());
	}
//	for (std::vector<student>::iterator i = student_deque.begin(); i != student_deque.end(); ++i) {
	for (std::deque<student>::iterator i = student_deque.begin(); i != student_deque.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return 0;
}



