#ifndef _MUSICITEM_H_
#define _MUSICITEM_H_
#include <string>

class MusicItem {
private:
    int id;
    std::string name;
    std::string artist;
    std::string category;
    std::string type;
    double price;
    int quantity;

public:
    MusicItem() = default;
    MusicItem(int id, std::string name, std::string artist, std::string category,
              std::string type, double price, int quantity);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getArtist() const;
    std::string getCategory() const;
    std::string getType() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setId(int);
    void setName(const std::string&);
    void setArtist(const std::string&);
    void setCategory(const std::string&);
    void setType(const std::string&);
    void setPrice(double);
    void setQuantity(int);
};
#endif