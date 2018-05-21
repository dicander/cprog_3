#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(true);
    vector<int> v;
    int just_read;
    while(cin>>just_read) {
        v.push_back(just_read);
    }
    sort(v.begin(), v.end());
    int count = v[0];
    bool all_there = true;
    for(auto it=v.begin(); it!=v.end(); ++it) {
        if(count!=*it) {
            cout << "expected " << count << " found " << *it << endl;
            all_there = false;
        }
        count++;
    }
    if(all_there) {
        cout << "Found " << v.size() << " ordered numbers" << endl;
    }

}
