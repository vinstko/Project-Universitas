#include <iostream>
#include <cmath>
using namespace std;

// Deklarasi variabel konstan yaitu Phi = 3.1416
const double phi = 3.1416;

// Deklarasi Prototype fungsi jarak, jari-jari, keliling, dan luas
double mencari_jarak(int x1, int x2, int y1, int y2);
double mencari_jari_jari(int x1, int x2, int y1, int y2);
double mencari_keliling(double r);
double mencari_luas(double r);


int main () {
    // Deklarasi variabel titik x dan y
    int pusat_x1;
    int pusat_y1;
    int titik_x2;
    int titik_y2;

    double jari_jari;

    // user memasukkan titik x dan y
    cout << "pusat x1 : ";
    cin >> pusat_x1;
    cout << "pusat y1 : ";
    cin >> pusat_y1;
    cout << "titik x2 : ";
    cin >> titik_x2;
    cout << "titik y2 : ";
    cin >> titik_y2;
    cout << endl;

    // mencari jari jari dengan memanggil fungsi yang menghitung jari jari
    jari_jari = mencari_jari_jari(pusat_x1, titik_x2, pusat_y1, titik_y2);
    cout << "Jari-jari : " << jari_jari << endl;

    // menampilkan diameter, dimana diameter adalah dua kali dari jari_jari
    cout << "Diameter : " << jari_jari * 2 << endl;

    // mencari keliling dengan memanggil fungsi yang menghitung keliling
    cout << "Keliing : " << mencari_keliling(jari_jari) << endl;

    // mencari luas dengan memanggil fungsi yang menghitung luas
    cout << "Luas : " << mencari_luas(jari_jari) << endl;

    

    return 0;
}

double mencari_jarak(int x1, int x2, int y1, int y2)
{
    double jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return jarak;
}

double mencari_jari_jari(int x1, int x2, int y1, int y2)
{
    return mencari_jarak(x1, x2, y1, y2);
}

double mencari_keliling(double r)
{
    return 2 * phi * r;
}

double mencari_luas(double r)
{
    return phi * pow(r, 2);
}
