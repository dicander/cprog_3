struct Act {
    float calc(int a) {
        return 1.1 * a;
    }
};
struct Bureau {
    // Members variables
    int x;
    int & y; // reference

    // Constructors
    Bureau() {
        x = 1;
        y = x;
    }


    Bureau(int & a) : x(1), y(a) {
    }


    Bureau(int a, const int & b) : x(a), y(b) {
    }


    // Member methods
    float foo(Bureau b, const Act & a) const {
        return a.calc(*this + b);
    }



    float bar(Act & a) {
        return a.calc(*this + x); // implicit constructor call
    }



    int operator+(Bureau b) const {
        return x + b.x;
    }
};
int main() {
    return 0;
}
