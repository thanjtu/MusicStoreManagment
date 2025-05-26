#include "MusicItem.h"

// Constructor
MusicItem::MusicItem(int id, std::string name, std::string artist, std::string category,
                     std::string type, double price, int quantity)
    : id(id), name(name), artist(artist), category(category),
      type(type), price(price), quantity(quantity) {}

// Getters
int MusicItem::getId() const { return id; }
std::string MusicItem::getName() const { return name; }
std::string MusicItem::getArtist() const { return artist; }
std::string MusicItem::getCategory() const { return category; }
std::string MusicItem::getType() const { return type; }
double MusicItem::getPrice() const { return price; }
int MusicItem::getQuantity() const { return quantity; }

// Setters
void MusicItem::setId(int i) { id = i; }
void MusicItem::setName(const std::string& n) { name = n; }
void MusicItem::setArtist(const std::string& a) { artist = a; }
void MusicItem::setCategory(const std::string& c) { category = c; }
void MusicItem::setType(const std::string& t) { type = t; }
void MusicItem::setPrice(double p) { price = p; }
void MusicItem::setQuantity(int q) { quantity = q; }
