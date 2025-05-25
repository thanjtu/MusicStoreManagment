#ifndef _INVENTORYSERVICE_H_
#define _INVENTORYSERVICE_H_
#include "IMusicRepository.h"

class InventoryService {
private:
    IMusicRepository* repository;

public:
    InventoryService(IMusicRepository* repo);

    void addNewItem(const MusicItem& item);
    void editItem(const MusicItem& item);
    void removeItem(int id);
    MusicItem searchItem(int id);
    std::vector<MusicItem> listAllItems();
};
#endif