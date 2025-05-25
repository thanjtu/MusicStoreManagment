#ifndef _IMUSICREPO_H_
#define _IMUSICREPO_H_
#include <vector>
#include "MusicItem.h"

class IMusicRepository {
public:
    virtual void addMusic(const MusicItem& item) = 0;
    virtual void updateMusic(const MusicItem& item) = 0;
    virtual void deleteMusic(int id) = 0;
    virtual MusicItem findMusicById(int id) = 0;
    virtual std::vector<MusicItem> getAllMusic() = 0;
    virtual ~IMusicRepository() {}
};
#endif
