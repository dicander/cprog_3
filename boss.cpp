struct Boss {
    Test * recall(Bil * & b, Test * tests, size_t nrOfTests) {
        for (size_t i = 0; i < nrOfTests; i+= 1) {
            if (tests[i] == false) {
                Protocol * important_protocol = new Protocol();
                important_protocol->note(tests[i]);
                Test * new_tests = new Test[nrOfTests];
                white_wash(new_tests);
                return new_tests;
            }
        }
        // all tests are good, replace the car
        b = new Bil();
        return tests;
    }
};
