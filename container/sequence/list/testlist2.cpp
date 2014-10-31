/*
 * main.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: hiep
 */

// list::unique
#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <iterator>
// a binary predicate implemented as a function:
bool same_integral_part(double first, double second) {
	return (int(first) == int(second));
}

// a binary predicate implemented as a class:
struct is_near {
	bool operator()(double first, double second) {
		return (fabs(first - second) < 5.0);
	}
};

int main() {
	double mydoubles[] = { 12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
	std::ostream_iterator<double> out(std::cout, " ");
	std::list<double> mylist(mydoubles, mydoubles + 10);

//	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35
	std::copy(mylist.begin(), mylist.end(), out);
	std::cout << std::endl;

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
	std::copy(mylist.begin(), mylist.end(), out);
	std::cout << std::endl;

	mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15, 15.3,  72.25, 73.0
	std::copy(mylist.begin(), mylist.end(), out);
	std::cout << std::endl;

	mylist.unique(is_near());           //  2.72, 12.15, 72.25
	std::copy(mylist.begin(), mylist.end(), out);
	std::cout << std::endl;

	std::cout << "mylist contains:";
	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
