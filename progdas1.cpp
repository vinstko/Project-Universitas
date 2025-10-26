#include <iostream>
using namespace std;

int main() {
    int n;
    int total = 0;
    bool bukan_bilangan_pertama = false;
    cout << "\nNama : Muhammad Kevin Setiko \n" << "Prodi : Teknik Elektro\n" << "NIM : 25/560376/TK/63287" << endl << endl;
    cout << "MENCARI BILANGAN PRIMA DAN DIJUMLAHKAN" << endl << endl;
    cout << "Masukkan batas bilangan: ";
    cin >> n;

    // cek setiap bilangan dari 2 sampai n
    for (int angka = 2; angka <= n; angka++) {
        bool prima = true;

        // cek apakah angka habis dibagi bilangan lain
        for (int i = 2; i < angka; i++) {
           if (angka == 2) {
            prima = true;
            break;
           } else if (angka % i == 0) {
                prima = false;
                break;
            }
        }

        // jika prima, tampilkan
        if (prima) {
         if (bukan_bilangan_pertama) {
            cout << " + ";
         }
         cout << angka;
         bukan_bilangan_pertama = true;
         total += angka;
        }  
    }

    cout << " = " << total << endl;
    return 0;
}
