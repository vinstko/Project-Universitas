#include "Item.h"

Item::Item(string nama, int stok, int harga) {
    this->nama = nama;
    this->stok = stok;
    this->harga = harga;
}

Item::Item() {
    nama = "";
    stok = 0;
    harga = 0;
}