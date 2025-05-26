#include "OrderService.h"

OrderService::OrderService(IMusicRepository* repo)
    : repository(repo) {}

bool OrderService::processOrder(int itemId, int quantity) {
    MusicItem item = repository->findMusicById(itemId);
    if (item.getId() == 0 || item.getQuantity() < quantity) {
        return false;
    }
    item.setQuantity(item.getQuantity() - quantity);
    repository->updateMusic(item);
    return true;
}
