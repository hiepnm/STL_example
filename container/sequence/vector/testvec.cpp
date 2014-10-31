/*
 * main.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: hiep
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
class student {
private:
	static int number_student;
	int student_no;
public:
	student():student_no(++number_student) {

	}
	student(int id) {
		student_no = id;
		++number_student;
	}
	student(const student& s) {
		student_no = s.student_no;
		std::cout << "Sao chep: student co Id: " << student_no << std::endl;

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
		std::cout << "Huy: student co id " << student_no << std::endl;
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
/*	std::vector<int> int_vector1, int_vector2(10);
	int_vector1.reserve(10);
	std::cout << "Vector1: dung luong " << int_vector1.capacity() << ", kich thuoc " << int_vector1.size() << std::endl;
	std::cout << "Vector2: dung luong " << int_vector2.capacity() << ", kich thuoc " << int_vector2.size() << std::endl;
	std::vector<int>::iterator it;
	for (it = int_vector2.begin(); it != int_vector2.end(); ++it) {
		std::cout << *it << " ";
	}
*/
/*
	std::vector<student> student_vector;
	for (int i = 0; i < 10; ++i) {
		student s;
		student_vector.push_back(s);
	}
*/
//	std::copy(student_vector.begin() + 3, student_vector.begin() + 8, std::ostream_iterator<student>(std::cout, "\n"));
/*	std::cout << "xoa cac sv: ";
	while (!student_vector.empty()) {
		(student_vector.end() - 1)->showId();
		std::cout << " ";
		student_vector.pop_back();
	}
*/
/*
	int pos;
	std::cout << "Vi tri trong danh sach cua sinh vien moi: ";
	std::cin >> pos;
	student_vector.insert(student_vector.begin() + pos - 1, student(3));
	std::cout << "Cac sinh vien torng danh sach: ";
	std::copy(student_vector.begin(), student_vector.end(), std::ostream_iterator<student>(std::cout, " "));
	std::cout << std::endl;
	int id;
	std::cout << "Nhap vao dinh danh cua sinh vien muon xoa: ";
	std::cin >> id;
	student s(id);
	std::vector<student>::iterator find_res = std::find(student_vector.begin(), student_vector.end(), s);
	if (find_res == student_vector.end()) {
		std::cout << "Khong co sinh vien co dinh danh " << id << " trong danh sach" << std::endl;
		return 1;
	}
	student_vector.erase(find_res);
	std::cout << "Sinh vien da duoc xoa khoi danh sach" << std::endl;
	std::cout << "Cac sinh vien torng danh sach: ";
	std::copy(student_vector.begin(), student_vector.end(), std::ostream_iterator<student>(std::cout, " "));
	std::cout << std::endl;
*/
/*
	std::vector<student> students;
//	students.reserve(3);
	for (int i = 0; i < 3; ++i) {
		std::cout << "Lan goi push_back thu " << i + 1 << std::endl;
		students.push_back(student());
	}
	std::cout << "Ket thuc chuong trinh" << std::endl;
*/
	std::vector<int> vi(10, 0);
	std::ostream_iterator<int> out(std::cout, " ");
	copy(vi.begin(), vi.end(), out);
	std::vector<int>::iterator i = vi.begin();
	std::cout << "\ni: " << long(&*i)  << std::endl;
	*i = 47;
	copy(vi.begin(), vi.end(), out);
	vi.resize(vi.capacity() + 1);
	std::cout << "\ni: " << long(&*i) << std::endl;
	std::cout << "vi.begin(): " << long(&*vi.begin()) << std::endl;
	*i = 48;															//i thanh con tro lac
	copy(vi.begin(), vi.end(), out);
	std::cout << "\ni: " << long(&*i) << std::endl;
	return 0;
}


