//
// Created by Jairo Riaño on 17/07/23.
//

#ifndef LINKDOUBLE_DISH_H
#define LINKDOUBLE_DISH_H

#include <string>
#include <ostream>


class Dish {
public:
    Dish();

    Dish(const std::string &id, const std::string &name, double value);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getValue() const;

    void setValue(double value);

    friend std::ostream &operator<<(std::ostream &os, const Dish &dish);

    virtual ~Dish();

private:
    std::string id;

    std::string name;

    double value;
};


#endif //LINKDOUBLE_DISH_H
