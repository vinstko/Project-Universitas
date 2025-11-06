#include <iostream>
using namespace std;

/* Pertama tama perlu untuk mendeklarasikkan struct
dengan variabel-variabel yang di butuh kan sesuai pada soal,
antara lain, studentFName ( nama depan siswa ), studentLName ( nama belakang siswa ),
testScore ( score yang di peroleh siswa ), dan grade ( nilai yang didapatkan sesuai dengan testScore ). */
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// variabel array dengan nama siswa dengan tipe studentType dan berjumlah 20.
studentType siswa[20];
// anggap sebagai awalan nilai tertinggi adalah 0
int nilai_tertinggi  = 0;

// sebuah fungsi untuk mengambil data dari nama depan, nama belakang, dan score yang di dapat oleh siswa
void MengisiData ();

// sebuah fungsi untuk menentukkan grade yang di dapat dari siswa
void MenentukkanGrade ();

// sebuah fungsi untuk mencari nilai tertinggi
void MencariNilaiTertinggi ();

// Sebuah fungsi untuk mencetak nama siswa yang memiliki nilai tes tertinggi
void MencetakNilaitertinggi ();

/* Sebuah fungsi untuk menampilkan semua data siswa,
mulau dari nama depan, nama belakang, score, dan juga grade.*/
void MencetakSemuaData ();


// fungsi main
int main () {
    // fungsi dimulai dengan mengisi data siswa terlebih dahulu
     MengisiData();

     // dilanjutkan dengan menentukkan grade dari siswa
     MenentukkanGrade();

     // dilanjutkan dengan mencari nilai tertinggi
     MencariNilaiTertinggi();

     // dilanjutkan dengan mencetak siswa dengan nilai tertinggi
     MencetakNilaitertinggi();

     // diakhiri dengan mencetak semua data siswa
     MencetakSemuaData();

    return 0;
}


void MengisiData () {
    // variabel kondisi untuk perulangan while dalam memastikkan nilai yang di masukkan adalah dalam rentang 0 - 100
    bool kondisi = true;

    for (int i = 0; i < 20; i++) {

        // untuk mengubah kembali nilai kondisi menjadi true
        kondisi = true;

        cout << "Nama depan siswa dengan nomor [" << i + 1 << "] : ";
        cin >> siswa[i].studentFName;
        cout << "Nama belakang siswa dengan nomor [" << i + 1 << "] : ";
        cin >> siswa[i].studentLName;

        while (kondisi) {
            cout << "Score dari siswa dengan nomor [" << i + 1<< "] : ";
            cin >> siswa[i].testScore;

            // untuk memastikkan nilai yang di masukkan adalah dalam rentang 0 - 100
            if (siswa[i].testScore > 100) {
                cout << "Masukkan angka dari 0 sampai 100" << endl;
                kondisi = true;
            } else {
                kondisi = false;
                cout << endl;
            }
        }
    }
}

void MenentukkanGrade () {

    for (int i = 0; i < 20; i++) {
        if (siswa[i].testScore >= 0 && siswa[i].testScore <= 25) {
            siswa[i].grade = 'D';
        } else if (siswa[i].testScore >= 26 && siswa[i].testScore <= 50) {
            siswa[i].grade = 'C';
        } else if (siswa[i].testScore >= 51 && siswa[i].testScore <= 75) {
            siswa[i].grade = 'B';
        } else if (siswa[i].testScore >= 76 && siswa[i].testScore <= 100) {
            siswa[i].grade = 'A';
        }
    }
}

void MencariNilaiTertinggi () {
    // mencari nilai tertinggi dengan membandingkan nilai tiap siswa
    for (int i = 0; i < 20; i++) {
        if (siswa[i].testScore > nilai_tertinggi) {
            nilai_tertinggi = siswa[i].testScore;
        }
    }
}

void MencetakNilaitertinggi () {
    cout << "Siswa dengan nilai tertinggi :" << endl << "-------------------------------------" << endl;

    for (int i = 0; i < 20; i++) {
        if (siswa[i].testScore == nilai_tertinggi) {
            cout << siswa[i].studentLName << ", " 
                 << siswa[i].studentFName
                 << "       " << siswa[i].testScore
                 << "       " << siswa[i].grade << endl;
        }
    }

    cout << endl;
}

void MencetakSemuaData () {
    cout << "Data dari semua siswa : " << endl << "-------------------------------------" << endl;

    for (int i = 0; i < 20; i++) {
        cout << siswa[i].studentLName << ", " 
                 << siswa[i].studentFName
                 << "       " << siswa[i].testScore
                 << "   " << siswa[i].grade << endl;
    }

    cout << endl;
    cout << "-------------------------------------" << endl << "PROGRAM SELESAI" << endl;
}