#include "RentalSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

// ================================
// Constructor (Load Data)
// ================================
RentalSystem::RentalSystem() {
    loadData();

    // Jika file kosong → masukkan default item
    if (items.empty()) {
        items.push_back(Item("PlayStation 3", 5, 30000));
        items.push_back(Item("PlayStation 4", 5, 35000));
        items.push_back(Item("PlayStation 5", 3, 40000));
        items.push_back(Item("Nintendo Switch", 4, 45000));
        items.push_back(Item("Xbox", 4, 30000));
    }
}

// ================================
// MENU UTAMA
// ================================
void RentalSystem::menuUtama() {
    int pilih;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Add Item Sewa\n";
        cout << "2. Edit Item Sewa\n";
        cout << "3. View Item Sewa\n";
        cout << "4. Menu Rental\n";
        cout << "5. Save Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1: addItem(); break;
            case 2: editItem(); break;
            case 3: viewItem(); break;
            case 4: menuRental(); break;
            case 5: saveData(); break;
            case 6: saveData(); return;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

// ================================
// ADD ITEM
// ================================
void RentalSystem::addItem() {
    cout << "\n===== ADD ITEM SEWA =====\n";
    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i].nama
             << " | stok: " << items[i].stok
             << " | harga: Rp" << items[i].harga << endl;
    }

    int pilih;
    cout << "\nPilih item: ";
    cin >> pilih;

    if (pilih < 1 || pilih > items.size()) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    int index = pilih - 1;
    int jumlah, lama;

    cout << "Jumlah: ";
    cin >> jumlah;

    if (jumlah > items[index].stok) {
        cout << "Stok tidak cukup!\n";
        return;
    }

    cout << "Lama sewa (hari): ";
    cin >> lama;

    keranjang.push_back(CartItem(items[index].nama, jumlah, lama));

    items[index].stok -= jumlah;

    cout << "Item berhasil ditambahkan!\n";
}

// ================================
// EDIT ITEM
// ================================
void RentalSystem::editItem() {
    if (keranjang.empty()) {
        cout << "\nKeranjang kosong.\n";
        return;
    }

    viewItem();

    int pilih;
    cout << "\nPilih item untuk diedit: ";
    cin >> pilih;

    if (pilih < 1 || pilih > keranjang.size()) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    int baru;
    cout << "Jumlah baru: ";
    cin >> baru;

    keranjang[pilih - 1].jumlah = baru;

    cout << "Item berhasil diedit!\n";
}

// ================================
// VIEW ITEM
// ================================
void RentalSystem::viewItem() {
    cout << "\n===== LIST ITEM DISEWA =====\n";

    if (keranjang.empty()) {
        cout << "Keranjang kosong.\n";
        return;
    }

    for (int i = 0; i < keranjang.size(); i++) {
        cout << i + 1 << ". " << keranjang[i].nama
             << " | jumlah: " << keranjang[i].jumlah
             << " | lama: " << keranjang[i].lama << " hari\n";
    }
}

// ================================
// MENU RENTAL
// ================================
void RentalSystem::menuRental() {
    int pilih;
    while (true) {
        cout << "\n===== MENU RENTAL =====\n";
        cout << "1. Sewa Sekarang\n";
        cout << "2. Kembalikan Barang\n";
        cout << "3. Lihat Transaksi\n";
        cout << "4. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: sewaItem(); break;
            case 2: kembalikanItem(); break;
            case 3: viewTransaksi(); break;
            case 4: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

// ================================
// SEWA ITEM
// ================================
void RentalSystem::sewaItem() {
    if (keranjang.empty()) {
        cout << "\nKeranjang kosong!\n";
        return;
    }

    int total = 0;

    cout << "\n===== DETAIL SEWA =====\n";

    for (auto &c : keranjang) {
        int harga = 0;
        for (auto &it : items)
            if (it.nama == c.nama)
                harga = it.harga;

        int biaya = harga * c.jumlah * c.lama;
        total += biaya;

        cout << "- " << c.nama << " x" << c.jumlah
             << " | " << c.lama << " hari"
             << " | biaya: Rp" << biaya << endl;
    }

    cout << "\nTOTAL BAYAR: Rp" << total << endl;
}

// ================================
// KEMBALIKAN ITEM
// ================================
void RentalSystem::kembalikanItem() {
    cout << "\nBarang berhasil dikembalikan!\n";
}

// ================================
// VIEW TRANSAKSI
// ================================
void RentalSystem::viewTransaksi() {
    cout << "\n===== RIWAYAT TRANSAKSI =====\n";
    viewItem();
}

// ================================
// SAVE DATA
// ================================
void RentalSystem::saveData() {
    ofstream file("rental_data.txt");

    file << items.size() << endl;
    for (auto &it : items) {
        file << it.nama << endl;
        file << it.stok << endl;
        file << it.harga << endl;
    }

    file << keranjang.size() << endl;
    for (auto &c : keranjang) {
        file << c.nama << endl;
        file << c.jumlah << endl;
        file << c.lama << endl;
    }

    cout << "\nData berhasil disimpan!\n";
}

// ================================
// LOAD DATA
// ================================
void RentalSystem::loadData() {
    ifstream file("rental_data.txt");
    if (!file.is_open()) return;

    items.clear();
    keranjang.clear();

    int n;
    file >> n;
    file.ignore();

    for (int i = 0; i < n; i++) {
        string nama;
        int stok, harga;

        getline(file, nama);
        file >> stok;
        file >> harga;
        file.ignore();

        items.push_back(Item(nama, stok, harga));
    }

    int m;
    file >> m;
    file.ignore();

    for (int i = 0; i < m; i++) {
        string nama;
        int jumlah, lama;

        getline(file, nama);
        file >> jumlah;
        file >> lama;
        file.ignore();

        keranjang.push_back(CartItem(nama, jumlah, lama));
    }

    cout << "Data berhasil dimuat.\n";
}
