#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include <string>
#include "Item.h"
#include "CartItem.h"

class RentalSystem {
private:
    std::vector<Item> items;
    std::vector<CartItem> keranjang;

public:
    RentalSystem();

    void menuUtama();
    void addItem();
    void editItem();
    void viewItem();
    void menuRental();
    void sewaItem();
    void kembalikanItem();
    void viewTransaksi();

    // SAVE & LOAD
    void saveData();
    void loadData();
};

#endif
