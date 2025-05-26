#include "ConsoleUI.h"
#include <iostream>

ConsoleUI::ConsoleUI(InventoryService* inv, OrderService* ord)
    : inventory(inv), order(ord) {}

void ConsoleUI::showMainMenu() {
    std::cout << "\n--- Music Store Management ---\n";
    std::cout << "1. Hiển thị tất cả mặt hàng\n";
    std::cout << "2. Thêm mặt hàng mới\n";
    std::cout << "3. Cập nhật mặt hàng\n";
    std::cout << "4. Xoá mặt hàng\n";
    std::cout << "5. Đặt hàng\n";
    std::cout << "0. Thoát\n";
    std::cout << "Chọn: ";
}

void ConsoleUI::handleUserInput() {
    int choice;
    while (true) {
        showMainMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                displayAllItems();
                break;
            case 2: {
                int id, quantity;
                double price;
                std::string name, artist, category, type;
                std::cout << "Nhập ID, Tên, Nghệ sĩ, Thể loại, Loại, Giá, Số lượng:\n";
                std::cin >> id >> name >> artist >> category >> type >> price >> quantity;
                inventory->addNewItem(MusicItem(id, name, artist, category, type, price, quantity));
                break;
            }
            case 3: {
                int id, quantity;
                double price;
                std::string name, artist, category, type;
                std::cout << "Nhập ID cần cập nhật và thông tin mới:\n";
                std::cin >> id >> name >> artist >> category >> type >> price >> quantity;
                inventory->editItem(MusicItem(id, name, artist, category, type, price, quantity));
                break;
            }
            case 4: {
                int id;
                std::cout << "Nhập ID cần xoá: ";
                std::cin >> id;
                inventory->removeItem(id);
                break;
            }
            case 5:
                createOrder();
                break;
            case 0:
                std::cout << "Thoát chương trình.\n";
                return;
            default:
                std::cout << "Lựa chọn không hợp lệ.\n";
        }
    }
}

void ConsoleUI::displayAllItems() {
    auto items = inventory->listAllItems();
    std::cout << "\nDanh sách mặt hàng:\n";
    for (const auto& item : items) {
        std::cout << item.getId() << " | " << item.getName() << " | " << item.getArtist()
                  << " | " << item.getCategory() << " | " << item.getType()
                  << " | " << item.getPrice() << " | " << item.getQuantity() << "\n";
    }
}

void ConsoleUI::createOrder() {
    int id, quantity;
    std::cout << "Nhập ID mặt hàng và số lượng cần đặt: ";
    std::cin >> id >> quantity;
    if (order->processOrder(id, quantity)) {
        std::cout << "Đặt hàng thành công!\n";
    } else {
        std::cout << "Đặt hàng thất bại. Kiểm tra ID hoặc số lượng tồn kho.\n";
    }
}
