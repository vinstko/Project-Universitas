#ifndef CARTITEM_H
#define CARTITEM_H

#include <string>
using namespace std;

class CartItem {
public:
    string nama;
    int jumlah;
    int lama;

    CartItem(string n, int j, int l);
    CartItem(); // untuk load file
};

#endif