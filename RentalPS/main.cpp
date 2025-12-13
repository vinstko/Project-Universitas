#include <iostream>
#include "User.h"
#include "RentalSystem.h"
using namespace std;

int main() {
    User user;
    user.registerUser();

    cout << "\n=== Silakan Login ===\n";
    while (!user.login()) {
        cout << "Login gagal! Coba lagi.\n";
    }

    cout << "\nLogin berhasil!\n";

    RentalSystem rental;
    rental.menuUtama();

    return 0;
}