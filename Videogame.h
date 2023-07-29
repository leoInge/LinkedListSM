//
// Created by yilbe on 27/07/2023.
//
#include "string"
#include "iostream"

#ifndef LINKDOUBLE_VIDEOGAME_H
#define LINKDOUBLE_VIDEOGAME_H
using namespace std;


class Videogame {

private:

    string idvideogame;
    string name;
    string category;
public:
    Videogame();

    friend ostream &operator<<(ostream &os, const Videogame &videogame);

    virtual ~Videogame();

public:
    Videogame(const string &idvideogame, const string &name, const string &category, int price);

private:

    int price;
public:
    const string &getIdvideogame() const;

    void setIdvideogame(const string &idvideogame);

    const string &getName() const;

    void setName(const string &name);

    const string &getCategory() const;

    void setCategory(const string &category);

    int getPrice() const;

    void setPrice(int price);


};


#endif //LINKDOUBLE_VIDEOGAME_H
