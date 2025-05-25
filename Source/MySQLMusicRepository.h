#ifndef _MYSQLMUSICREPOSITPTY_H_
#define _MYSQLMUSICREPOSITPTY_H_
#include "IMusicRepository.h"
#include <mysql.h>

class MySQLMusicRepository : public IMusicRepository {
private:
    MYSQL* conn;

public:
    MySQLMusicRepository();
    ~MySQLMusicRepository();

    void addMusic(const MusicItem& item) override;
    void updateMusic(const MusicItem& item) override;
    void deleteMusic(int id) override;
    MusicItem findMusicById(int id) override;
    std::vector<MusicItem> getAllMusic() override;

private:
    void connect();
    void disconnect();
    MYSQL_RES* executeQuery(const std::string& query);
};
#endif