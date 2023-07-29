//
// Created by Jairo Riaño on 17/07/23.
//

#ifndef LINKDOUBLE_NODE_H
#define LINKDOUBLE_NODE_H

#include <cstdio>

template <class T> class LinkedList;

template <class T>
class Node {
    friend class LinkedList<T>;
public:
    Node() {
        Node::next = NULL;
        Node::previous = NULL;
    }

    explicit Node(T info) : info(info) {
        Node::next = NULL;
        Node::previous = NULL;
    }

    virtual ~Node() {

    }

    Node<T>* next;
private:
    T info;
    Node<T>* previous;

};


#endif //LINKDOUBLE_NODE_H
