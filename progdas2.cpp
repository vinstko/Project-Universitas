#include <iostream>  
#include <algorithm>
using namespace std; 

void kalkulator () {
    float a, b, hasil = 0;
    bool kondisi = true;
    char operasi; 

    cout << "\nMasukkan bilangan pertama: ";
    cin >> a;

    while (kondisi) {
    cout << "\nPenjumlahan : + , Pengurangan : -, perkalian : x, pembagian : /" << endl;
	cout << "Masukkan operasi: ";
    cin >> operasi;

    if (operasi == '+' || operasi == '-' || operasi == 'x' || operasi == '/') {
		cout << "\nMasukkan bilangan kedua: ";
        cin >> b;
       switch (operasi) {
    case '+':
        hasil = a + b;
        kondisi = false;
        break;
    case '-':
        hasil = a - b;
        kondisi = false;
        break;
    case 'x':
        hasil = a * b;
        kondisi = false;
        break;
    case '/':
        hasil = a / b;
        kondisi = false;
        break;
}

} else {

    cout << "Operasi tidak valid!" << endl;

    }

}

    cout << "\nHasilnya adalah: " << hasil << endl;

}

int main() {  
    bool kondisi = true;
    string ApakahLanjut;

    cout << "\nNama : Muhammad Kevin Setiko \n" << "Prodi : Teknik Elektro\n" << "NIM : 25/560376/TK/63287" << endl << endl;
    cout << "TUGAS PROGDAS" << endl;
    cout << "KALKULATOR SEDERHANA" << endl;
    
    kalkulator();


    while (kondisi) {
        cout << "\n Apakah lanjut (yes/no) : ";
        cin >> ApakahLanjut;
         transform(ApakahLanjut.begin(), ApakahLanjut.end(), ApakahLanjut.begin(), ::tolower);

         if (ApakahLanjut == "yes") {
            kalkulator();
         } else if (ApakahLanjut == "no") {
            kondisi = false;
         } else {
            cout << "informasi tidak valid" << endl;
         }
        }
	

    return 0;
}