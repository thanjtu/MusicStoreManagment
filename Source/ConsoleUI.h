#pragma once
#include "InventoryService.h"
#include "OrderService.h"

class ConsoleUI {
private:
    InventoryService* inventory;
    OrderService* order;

public:
    ConsoleUI(InventoryService* inv, OrderService* ord);

    void showMainMenu();
    void handleUserInput();
    void displayAllItems();
    void createOrder();
};
