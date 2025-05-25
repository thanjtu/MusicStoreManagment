#ifndef _PROGRAM_H_
#define _PROGRAM_H_
#include "ConsoleUI.h"
#include "InventoryService.h"
#include "OrderService.h"
#include "MySQLMusicRepository.h"

class Program {
private:
    MySQLMusicRepository repository;
    InventoryService inventoryService;
    OrderService orderService;
    ConsoleUI consoleUI;

public:
    Program();
    void config();
    void run();
};

#endif