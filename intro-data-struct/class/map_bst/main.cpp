#include <iostream>
#include <assert.h>
#include "map_bst.h"

int main() {
	CP::map_bst<int, int> mp;
	mp.insert({5, 0});
	mp.insert({1, 0});
	mp.insert({6, 0});
	mp.insert({2, 0});
	mp.insert({3, 0});
	mp.insert({4, 0});
	mp.insert({11, 0});
	mp.insert({7, 0});
	mp.print();
	mp.erase(5);
	mp.print();
}