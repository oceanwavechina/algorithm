/*
 * disjoin_set.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: liuyanan
 */


#include <sstream>
#include <vector>
#include <cmath>
#include <iostream>


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


class DisjoinSet {

public:
	DisjoinSet() {
		_parent.resize(10);
		_rank.resize(10);
	}

public:
	void MakeSet(long i) {
		_parent[i] = i;
		_rank[i] = 0;
	}

	long Find(long i) {
		// runtime: O(height of the tree)
		while(i != _parent[i])
			_parent[i] = Find(_parent[i]);

		return _parent[i];
	}

	void Union(long i, long j) {
		long i_id = Find(i);
		long j_id = Find(j);

		if (i_id == j_id) {
			return;
		}

		if (_rank[i_id] > _rank[j_id])
		{
			_parent[j_id] = i_id;
		}
		else
		{
			_parent[i_id] = j_id;

			// 这是两棵树等高的时候
			if (_rank[i_id] ==  _rank[j_id])
				_rank[j_id] = _rank[j_id] + 1;
		}
	}

	void output() {
		std::cout << "parent: " << display(_parent) << std::endl;
		std::cout << "__rank: " << display(_rank) << std::endl;
	}

private:
	std::vector<long> _parent;
	std::vector<long> _rank;
};



int main(int argc, char **argv) {
	DisjoinSet s = DisjoinSet();

	s.MakeSet(0);
	s.MakeSet(1);
	s.MakeSet(2);
	s.MakeSet(3);
	s.MakeSet(4);
	s.MakeSet(5);
	s.MakeSet(6);

	std::cout << "origin:" << std::endl;
	s.output();

	std::cout << std::endl;
	s.Union(2,4);
	std::cout << "after union 2,4:" << std::endl;
	s.output();

	std::cout << std::endl;
	s.Union(5, 2);
	std::cout << "after union 5,2:" << std::endl;
	s.output();

	std::cout << std::endl;
	s.Union(3, 1);
	std::cout << "after union 3,1:" << std::endl;
	s.output();

	std::cout << std::endl;
	s.Union(2, 3);
	std::cout << "after union 2,3:" << std::endl;
	s.output();

	std::cout << std::endl;
	s.Union(2, 6);
	std::cout << "after union 2,6:" << std::endl;
	s.output();

}

