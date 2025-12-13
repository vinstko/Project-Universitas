#include "CartItem.h"

CartItem::CartItem(string n, int j, int l) {
    nama = n;
    jumlah = j;
    lama = l;
}

CartItem::CartItem() {
    nama = "";
    jumlah = 0;
    lama = 0;
}