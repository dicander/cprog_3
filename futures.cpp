#include <iostream>
#include <future>
#include <vector>
using namespace std;

static const int N_FUTURES = 10000;

int print_and_return_value(int value) {
	cout << value << " ";
	return value;
}

int main() {
	cin.sync_with_stdio(false);
	vector<future<int>> v(N_FUTURES);
	for(int i=0; i<N_FUTURES; ++i) {
		v[i]=async(launch::async, &print_and_return_value, i);
	}
	for(int i=0; i<N_FUTURES; ++i) {
		v[i].get();
	}
	cout.flush();
	cout << endl;
}
