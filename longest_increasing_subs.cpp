#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cassert>

using namespace std;

static const int dbg=0;
static const int inf=1<<30;
#define dout if(dbg)cout

template<typename T>
int longest_increasing_subsequence_length(T begin, T end){
	vector<int> d(distance(begin, end)+1, inf);
	for(auto it = begin; it != end; ++it){
		*(lower_bound(d.begin(), d.end(), *it)) = *it;
	}
	return distance(d.begin(),lower_bound(d.begin(), d.end(), inf));
}

template<typename T>
void find_and_print_longest_increasing_subsequence(T begin, T end) {
	size_t length = distance(begin,end);
	vector<int> d(length+1, inf);
	vector<stack<pair<int,int>>> parents(length+1);
	auto current = d.begin();
	int offset = 0;
	for(auto it = begin; it != end; ++it){
		current = lower_bound(d.begin(), d.end(), *it);
		*current = *it;
		offset = distance(d.begin(), current);
		if(offset > 0) {
			parents.at(offset-1).push(pair<int, int>(*it,d[offset-1]));
		}
	}
	offset = distance(d.begin(),lower_bound(d.begin(), d.end(), inf));
	printf("%d\n", offset);
	int back_track_step = d[offset-1];
	stack<int> solution;
	solution.push(back_track_step);
	offset--;
	while(offset>0) {
		dout << offset << endl;
		offset--;
		assert(!parents.at(offset).empty());
		while(!parents.at(offset).empty()) {
			pair<int,int> step_candidate = parents.at(offset).top();
			parents.at(offset).pop();
			if(step_candidate.first==back_track_step) {
				solution.push(step_candidate.second);
				back_track_step = step_candidate.second;
				break;
			}
		}
	}
	while(!solution.empty()) {
		printf("%d ", solution.top());
		solution.pop();
	}
	printf("\n");
}



int main(){
	int n;
	while(scanf("%d", &n)==1) {
		vector<int> v(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &v[i]);
		}
		//printf("length %d\n", longest_increasing_subsequence_length(v.begin(), v.end()));
		find_and_print_longest_increasing_subsequence(v.begin(), v.end());
	}
}