//
// Created by yilbe on 27/07/2023.
//

#include "Videogame.h"

const string &Videogame::getIdvideogame() const {
    return idvideogame;
}

void Videogame::setIdvideogame(const string &idvideogame) {
    Videogame::idvideogame = idvideogame;
}

const string &Videogame::getName() const {
    return name;
}

void Videogame::setName(const string &name) {
    Videogame::name = name;
}

const string &Videogame::getCategory() const {
    return category;
}

void Videogame::setCategory(const string &category) {
    Videogame::category = category;
}

int Videogame::getPrice() const {
    return price;
}

void Videogame::setPrice(int price) {
    Videogame::price = price;
}

Videogame::Videogame(const string &idvideogame, const string &name, const string &category, int price) : idvideogame(
        idvideogame), name(name), category(category), price(price) {}

Videogame::~Videogame() {

}

Videogame::Videogame() {}

ostream &operator<<(ostream &os, const Videogame &videogame) {
    os << "idvideogame: " << videogame.idvideogame << " name: " << videogame.name << " category: " << videogame.category
       << " price: " << videogame.price;
    return os;
}
