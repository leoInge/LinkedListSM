//
// Created by Jairo Riaño on 17/07/23.
//

#include "Dish.h"

Dish::Dish() {}

Dish::Dish(const std::string &id, const std::string &name, double value) : id(id), name(name), value(value) {}

const std::string &Dish::getId() const {
    return id;
}

void Dish::setId(const std::string &id) {
    Dish::id = id;
}

const std::string &Dish::getName() const {
    return name;
}

void Dish::setName(const std::string &name) {
    Dish::name = name;
}

double Dish::getValue() const {
    return value;
}

void Dish::setValue(double value) {
    Dish::value = value;
}

std::ostream &operator<<(std::ostream &os, const Dish &dish) {
    os << "id: " << dish.id << " name: " << dish.name << " value: " << dish.value;
    return os;
}

Dish::~Dish() {

}
