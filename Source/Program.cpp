#include "Program.h"

Program::Program()
    : repository(), inventoryService(&repository),
      orderService(&repository), consoleUI(&inventoryService, &orderService) {}

void Program::config() {
}

void Program::run() {
    consoleUI.handleUserInput();
}
