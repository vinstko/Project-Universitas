#include "User.h"
#include <iostream>

User::User() {}

void User::registerUser() {
    cout << "===== REGISTER USER =====\n";
    cout << "Buat Username : ";
    getline(cin, username);

    cout << "Buat Password : ";
    getline(cin, password);

    cout << "Masukkan Nama       : ";
    getline(cin, nama);

    cout << "Masukkan Alamat     : ";
    getline(cin, alamat);

    cout << "Masukkan Nomor HP   : ";
    getline(cin, nomorHp);

    cout << "\nRegistrasi berhasil!\n\n";
}

bool User::login() {
    string u, p;
    cout << "===== LOGIN =====\n";
    cout << "Username : ";
    getline(cin, u);

    cout << "Password : ";
    getline(cin, p);

    return (u == username && p == password);
}