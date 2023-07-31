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
    void addNodeAfterTo(Node<T>* node, T info);
    LinkedList<T> suma(LinkedList<T>);
    void  getSize();
    int countObjects();
    void  getObject(int pos);
    void addNodeBeforeTo(Node<T>* node, T info);
    T deleteNode(Node<T>* node);
    Node<T>* findNode(const std::string &id);
    T* findinfo(const std::string &id);
    bool isEmpty();

    void addFirst( T info );

    void addLast( T info );

    std::vector<T> getLinkedList( bool sw );

    void addSorted( T info );

    void addNodeAfterTo(const string &targetId, T info);

private:
    Node<T>* head;
    Node<T>* last;
public:


    void addNodeBeforeTo(const string &targetId, T info);

    T getFirstByPosition(int position);
};



#endif //LINKDOUBLE_LINKEDLIST_H
