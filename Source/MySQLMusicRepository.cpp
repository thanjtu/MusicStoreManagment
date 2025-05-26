#include "MySQLMusicRepository.h"
#include <iostream>

MySQLMusicRepository::MySQLMusicRepository() {
    connect();
}

MySQLMusicRepository::~MySQLMusicRepository() {
    disconnect();
}

void MySQLMusicRepository::connect() {
    conn = mysql_init(nullptr);
    if (!conn) {
        std::cerr << "MySQL init failed\n";
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "root", "", "MusicStore_DB", 0, nullptr, 0)) {
        std::cerr << "Connection failed: " << mysql_error(conn) << "\n";
        exit(1);
    }
}

void MySQLMusicRepository::disconnect() {
    if (conn) {
        mysql_close(conn);
        conn = nullptr;
    }
}

MYSQL_RES* MySQLMusicRepository::executeQuery(const std::string& query) {
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Query failed: " << mysql_error(conn) << "\n";
        return nullptr;
    }
    return mysql_store_result(conn);
}

void MySQLMusicRepository::addMusic(const MusicItem& item) {
    std::string query = "INSERT INTO MusicItem (id, name, artist, category, type, price, quantity) VALUES (" +
        std::to_string(item.getId()) + ", '" + item.getName() + "', '" + item.getArtist() + "', '" +
        item.getCategory() + "', '" + item.getType() + "', " +
        std::to_string(item.getPrice()) + ", " + std::to_string(item.getQuantity()) + ")";
    executeQuery(query);
}

void MySQLMusicRepository::updateMusic(const MusicItem& item) {
    std::string query = "UPDATE MusicItem SET name='" + item.getName() +
        "', artist='" + item.getArtist() +
        "', category='" + item.getCategory() +
        "', type='" + item.getType() +
        "', price=" + std::to_string(item.getPrice()) +
        ", quantity=" + std::to_string(item.getQuantity()) +
        " WHERE id=" + std::to_string(item.getId());
    executeQuery(query);
}

void MySQLMusicRepository::deleteMusic(int id) {
    std::string query = "DELETE FROM MusicItem WHERE id=" + std::to_string(id);
    executeQuery(query);
}

MusicItem MySQLMusicRepository::findMusicById(int id) {
    std::string query = "SELECT * FROM MusicItem WHERE id=" + std::to_string(id);
    MYSQL_RES* res = executeQuery(query);
    if (!res) return MusicItem();

    MYSQL_ROW row = mysql_fetch_row(res);
    if (!row) return MusicItem();

    MusicItem item(
        std::stoi(row[0]), row[1], row[2], row[3], row[4],
        std::stod(row[5]), std::stoi(row[6])
    );
    mysql_free_result(res);
    return item;
}

std::vector<MusicItem> MySQLMusicRepository::getAllMusic() {
    std::vector<MusicItem> items;
    MYSQL_RES* res = executeQuery("SELECT * FROM MusicItem");
    if (!res) return items;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        items.emplace_back(
            std::stoi(row[0]), row[1], row[2], row[3], row[4],
            std::stod(row[5]), std::stoi(row[6])
        );
    }
    mysql_free_result(res);
    return items;
}
