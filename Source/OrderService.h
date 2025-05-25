#ifdef _ORDERSERVICE_H_
#define _ORDERSERVICE_H_
#include "IMusicRepository.h"

class OrderService {
private:
    IMusicRepository* repository;

public:
    OrderService(IMusicRepository* repo);

    bool processOrder(int itemId, int quantity);
};

#endif
