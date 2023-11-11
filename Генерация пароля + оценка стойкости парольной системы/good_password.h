#ifndef GOOD_PASSWORD_H
#define GOOD_PASSWORD_H

#include <string>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;

namespace My_Password {
    class PasswordGenerator {
    public:
        string generatePassword(int length);
        long long calculatePasswordAttempts(int V, int T, int periodChoice);
        void run();
    };
}

#endif

