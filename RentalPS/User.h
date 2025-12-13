#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string nama;
    string alamat;
    string nomorHp;

public:
    User();
    void registerUser();
    bool login();
};

#endif