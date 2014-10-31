/*
 * main.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: hiep
 */


#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class fix_size {
	int x[20];

} fs;

template <typename Cont>
struct insert_back {
	void operator () (Cont& c, long count) {
		for (long i = 0; i < count; i++) {
			c.push_back(fs);
		}
	}
	char* get_name() {
		return "Thao tac bo sung vao cuoi bo chua";
	}
};

template <typename Cont>
struct insert_front {
	void operator () (Cont& c, long count) {
		for (long i = 0; i < count; i++) {
			c.push_front(fs);
		}
	}
	char* get_name() {
		return "Thao tac bo sung vao dau bo chua";
	}
};

template <typename Cont>
struct insert_middle {
	void operator () (Cont& c, long count) {
		typename Cont::iterator it;
		long cnt = count / 10;
		for (long i = 0; i < cnt; i++) {
			it = c.begin();
			it++;
			c.insert(it, fs);
		}
	}
	char* get_name() {
		return "Thao tac bo sung vao giua bo chua";
	}
};

template <typename Cont>
struct random_access {
	void operator () (Cont& c, long count) {
		int cnt = count * 100;
		int sz = c.size();
		for (long i = 0; i < cnt; i++) {
			c[rand() % sz];
		}
	}
	char* get_name() {
		return "Thao tac truy cap ngau nhien tren bo chua";
	}
};
template <typename Cont>
struct travelsal {
	void operator () (Cont& c, long count) {
		for (long i = 0; i < count; i++) {
			typename Cont::iterator it = c.begin(), end = c.end();
			c.push_back(fs);
			while (it != end) it++;
		}
	}
	char* get_name() {
		return "Thao tac duyet bo chua";
	}
};
template <typename Cont>
struct Swap {
	void operator () (Cont& c, long count) {
		typename Cont::iterator it = c.begin(), mid = c.begin();
		it++;
		long cnt = count * 10;
		for(long i = 0; i < cnt; i++) {
			swap(*it, *mid);
		}
	}
	char* get_name() {
		return "Swap";
	}
};
template <typename Cont>
struct remove_middle {
	void operator () (Cont& c, long count) {
		long cnt = count / 10;
		if (cnt > c.size()) {
			cout << "Thao tac xoa o giua: not enough elements" << endl;
			return;
		}
		for(long i = 0; i < cnt; i++) {
			typename Cont::iterator it = c.begin();
			it++;
			c.erase(it);
		}
	}
	char* get_name() {
		return "Thao tac xoa o giua";
	}
};
template <typename Cont>
struct remove_back {
	void operator () (Cont& c, long count) {
		int cnt = count * 10;
		if (cnt > c.size()) {
			cout << "Thao tac xoa o cuoi: not enough elements" << endl;
			return;
		}
		for(long i = 0; i < cnt; i++) {
			c.pop_back();
		}
	}
	char* get_name() {
		return "Thao tac xoa o giua";
	}
};
template <typename Op, typename Container>
void measure_time(Op f, Container& c, long count) {
//	string id(typeid(f).name());
//	bool Deque = id.find("deque") != string::npos;
//	bool List = id.find("list") != string::npos;
//	bool Vector = id.find("vector") != string::npos;
//	string cont_type = Deque ? "deque" : List ? "list" : Vector ? "vector" : "unknown";
//	cout << f.get_name() << " tren " << cont_type << ": ";
	clock_t ticks = clock();
	f(c, count);
	ticks = clock() - ticks;
	cout << ticks << endl;
}
typedef deque<fix_size> DF;
typedef list<fix_size> LF;
typedef vector<fix_size> VF;
int main(int argc, char **argv) {
	srand(time(0));
	long count = 1000;
	if (argc >= 2)
		count = atoi(argv[1]);
	DF deq;
	LF lst;
	VF vec, vecres;
	vecres.reserve(count);
	cout << "So sanh thao tac bo sung vao cuoi bo chua:" << endl;
	measure_time(insert_back<VF>(), vec, count);
	measure_time(insert_back<VF>(), vecres, count);
	measure_time(insert_back<DF>(), deq, count);
	measure_time(insert_back<LF>(), lst, count);

/*
	cout << "So sanh thao tac bo sung vao dau bo chua(khong thuc hien tren vector):" << endl;
	measure_time(insert_front<DF>(), deq, count);
	measure_time(insert_front<LF>(), lst, count);

	cout << "So sanh thao tac bo sung vao giua bo chua:" << endl;
	measure_time(insert_middle<VF>(), vec, count);
	measure_time(insert_middle<VF>(), vecres, count);
	measure_time(insert_middle<DF>(), deq, count);
	measure_time(insert_middle<LF>(), lst, count);

	cout << "So sanh thao tac truy cap ngau nhien tren bo chua (khong thuc hien tren list):" << endl;
	measure_time(random_access<VF>(), vec, count);
	measure_time(random_access<DF>(), deq, count);

	cout << "So sanh thao tac duyet bo chua:" << endl;
	measure_time(travelsal<VF>(), vec, count);
	measure_time(travelsal<DF>(), deq, count);
	measure_time(travelsal<LF>(), lst, count);

	cout << "So sanh thao tac hoan doi noi dung giua tren bo chua:" << endl;
	measure_time(Swap<VF>(), vec, count);
	measure_time(Swap<DF>(), deq, count);
	measure_time(Swap<LF>(), lst, count);

	cout << "So sanh thao tac xoa bo phan tu o giua bo chua:" << endl;
	measure_time(remove_middle<VF>(), vec, count);
	measure_time(remove_middle<DF>(), deq, count);
	measure_time(remove_middle<LF>(), lst, count);

	cout << "So sanh thao tac xoa bo phan tu o cuoi bo chua:" << endl;
	measure_time(remove_back<VF>(), vec, count);
	measure_time(remove_back<DF>(), deq, count);
	measure_time(remove_back<LF>(), lst, count);
*/
	return 0;

}



















