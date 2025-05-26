#include "InventoryService.h"

InventoryService::InventoryService(IMusicRepository* repo)
    : repository(repo) {}

void InventoryService::addNewItem(const MusicItem& item) {
    repository->addMusic(item);
}

void InventoryService::editItem(const MusicItem& item) {
    repository->updateMusic(item);
}

void InventoryService::removeItem(int id) {
    repository->deleteMusic(id);
}

MusicItem InventoryService::searchItem(int id) {
    return repository->findMusicById(id);
}

std::vector<MusicItem> InventoryService::listAllItems() {
    return repository->getAllMusic();
}
