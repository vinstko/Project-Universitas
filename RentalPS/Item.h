#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
public:
    string nama;
    int stok;
    int harga;

    Item(string nama, int stok, int harga);
    Item(); // diperlukan untuk load file
};

#endif