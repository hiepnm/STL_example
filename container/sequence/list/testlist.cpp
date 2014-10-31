/*
 * main.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: hiep
 */

#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

class student {

public:
	static int number_student;
	static int number_constructor_call;
	static int number_copy_constructor_call;
	static int number_destructor_call;
private:
	int student_no;
public:
	student():student_no(++number_student) {
		++number_constructor_call;
	}
	student(int id) {
		student_no=id;
	}
	student(const student& s) {
		student_no = s.student_no;
		++number_copy_constructor_call;
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
		++number_destructor_call;
	}
	int operator == (const student& s) {
		return student_no == s.student_no;
	}
	int operator != (const student& s) const{
		return student_no != s.student_no;
	}
	bool operator > (const student& s) const {
		return bool(this->student_no < s.student_no);
	}
	friend std::ostream& operator << (std::ostream& out, const student& s);
};
std::ostream& operator << (std::ostream& out, const student& s) {
	return out << s.student_no;
}

int student::number_student = 0;
int student::number_constructor_call = 0;
int student::number_copy_constructor_call = 0;
int student::number_destructor_call = 0;

int main(int argc, char **argv) {
	std::ostream_iterator<student> out(std::cout, " ");
//	std::greater<student> student_comp;
	student student_array[5] = {student(1), student(1), student(3), student(9), student(7)};
	int student_array_size = sizeof(student_array) / sizeof(*student_array);
	std::list<student> list_student(student_array, student_array+student_array_size);
	std::cout << "Danh sach ban dau: ";
	std::copy(list_student.begin(), list_student.end(), out);
	std::cout << std::endl;
/*
	std::cout << "xoa student co id != 5. Danh sach: ";
	std::binder2nd<std::not_equal_to<student> > student_diff(std::not_equal_to<student>(), student(5));
	list_student.remove_if(student_diff);
//	list_student.remove(student(5));
	std::copy(list_student.begin(), list_student.end(), out);
*/
	list_student.unique(std::not_equal_to<student>());
	std::cout << "Sau khi unique(): ";
	copy(list_student.begin(), list_student.end(), out);
/*
	std::list<student> student_list1(student_array, student_array + student_array_size);
	std::list<student> student_list2(student_array, student_array + student_array_size);
	std::list<student> student_list3, student_list4;
	for (int i = 0; i < 5; ++i) {
		student_list3.push_back(student(2*i));
		student_list4.push_back(student(2*i));
	}

	student_list1.splice(student_list1.begin(), student_list3);
	student_list2.merge(student_list4, student_comp);
	std::cout << "ket qua ham splice: " << std::endl;
	std::copy(student_list1.begin(), student_list1.end(), out);
	std::cout << std::endl;
	std::cout << "ket qua ham merge: " << std::endl;
	std::copy(student_list2.begin(), student_list2.end(), out);
*/
/*
	std::list<student> student_list(student_array, student_array + student_array_size);

	student_list.sort(student_comp);
	std::copy(student_list.begin(), student_list.end(), out);
*/
/*
	std::cout << "Truoc khi goi ham reverse " << std::endl;
	std::cout << "So lan goi cau tu sao chep: " << student::number_constructor_call << std::endl;
	std::cout << "So lan goi huy tu: " << student::number_destructor_call << std::endl;
	student_list.reverse();
	std::cout << "Sau khi goi ham reverse thanh phan" << std::endl;
	std::cout << "So lan goi cau tu sao chep: " << student::number_copy_constructor_call << std::endl;
	std::cout << "So lan goi huy tu: " << student::number_destructor_call << std::endl;

	std::reverse(student_list.begin(), student_list.end());
	std::cout << "Sau khi goi ham reverse khai luoc	" << std::endl;
	std::cout << "So lan goi cau tu sao chep: " << student::number_copy_constructor_call << std::endl;
	std::cout << "So lan goi huy tu: " << student::number_destructor_call << std::endl;
*/

	return 0;
}













