//
// Created by Jairo Riaño on 17/07/23.
//

#ifndef LINKDOUBLE_LINKEDLIST_H
#define LINKDOUBLE_LINKEDLIST_H

#include <vector>
#include "Videogame.h"
#include "Node.h"
#include "string"
template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList<T> suma(LinkedList<T>);
    T deleteNode(Node<T>* node);
    Node<T>* findNode(const std::string &id);
    bool isEmpty();

    void addFirst( T info );

    void addLast( T info );

    std::vector<T> getLinkedList( bool sw );

    void addSorted( T info );

private:
    Node<T>* head;
    Node<T>* last;
public:


private:

};



#endif //LINKDOUBLE_LINKEDLIST_H
