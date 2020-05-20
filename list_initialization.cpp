//
// Created by Marcus Dicander on 2020-05-18.
//

#include <iostream>
using namespace std;


class point {
public:
    int x, y;
};


int main() {
    point p{1, 2};
    point p2;
    cout << p.x << " " << p.y << endl;
}