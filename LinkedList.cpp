//
// Created by Jairo Riaño on 17/07/23.
//

#include "LinkedList.h"

template<class T>
std::vector<T> LinkedList<T>::getLinkedList(bool sw) {
    std::vector<T> vecOut;
    Node<T>* aux = sw ? head : last;
    while( aux != NULL ){
        vecOut.push_back( aux->info );
        aux = sw ? aux->next : aux->previous;
    }

    return vecOut;
}

template<class T>
void LinkedList<T>::addLast(T info) {
    if( isEmpty()){
        head = last = new Node<T>( info );
    }else{
        Node<T>* newNode = new Node<T>(info);

       last->next = newNode;
       newNode->previous = last;
       last = newNode;
    }
}

template<class T>
Node<T> *LinkedList<T>::findNode(const std::string &idvideogame) {
    Node<T> *aux = head;
    while (aux!=NULL){
        if (aux->info.getIdvideogame().compare(idvideogame)==0){

            return  aux;
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
void LinkedList<T>::addNodeAfterTo(const std::string& targetId, T info) {
    Node<T>* targetNode = findNode(targetId);
    if (targetNode == nullptr) {
        throw std::invalid_argument("Error: El nodo con el idvideogame especificado no se encontró en la lista.");
    }

    Node<T>* newNode = new Node<T>(info);
    newNode->next = targetNode->next;
    newNode->previous = targetNode;
    if (targetNode->next != nullptr) {
        targetNode->next->previous = newNode;
    }
    targetNode->next = newNode;
}
template<class T>
void LinkedList<T>::addNodeBeforeTo(const std::string& targetId, T info) {
    if (head == nullptr) {
        throw std::runtime_error("Error: La lista está vacía. No se puede agregar antes del nodo inexistente.");
    }

    Node<T>* targetNode = findNode(targetId);
    if (targetNode == nullptr) {
        throw std::invalid_argument("Error: El nodo con el idvideogame especificado no se encontró en la lista.");
    }

    Node<T>* newNode = new Node<T>(info);
    newNode->next = targetNode;
    newNode->previous = targetNode->previous;
    if (targetNode->previous != nullptr) {
        targetNode->previous->next = newNode;
    } else {
        head = newNode;
    }
    targetNode->previous = newNode;
}



template<class T>
void LinkedList<T>::addFirst(T info) {
    if( isEmpty()){
        head = last = new Node<T>( info );
    }else{
        Node<T>* newNode = new Node<T>(info);

        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
LinkedList<T>::LinkedList() {
    head = last = NULL;
}

template<class T>
T LinkedList<T>::getFirstByPosition(int position) {
    if (isEmpty() || position < 0) {
        throw std::out_of_range("Error: Lista vacía o posición inválida.");
    }

    Node<T>* currentNode = head;
    int currentIndex = 0;

    while (currentNode != nullptr && currentIndex < position) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentNode == nullptr) {
        throw std::out_of_range("Error: Posición fuera del rango de la lista.");
    }

    return currentNode->info;
}











template<class T>
T LinkedList<T>::deleteNode(Node<T> *node) {
    T nodeOut = node->info;
    if (node==head){
        head = head->next;
    }else{
        Node<T>* aux = head;
        while (aux->next!=node){
            aux = aux->next;
        }
        aux->next = node->next;
    }
    delete(node);
    return nodeOut;

}

template<class T>
T  *LinkedList<T>::findinfo(const std::string &idvideogame) {
    Node<T> *aux = head;
    while (aux!=NULL){
        if (aux->info.getIdvideogame().compare(idvideogame)==0){

            return  aux->info;
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
int LinkedList<T>::countObjects() {
    if (isEmpty()) {
        cout << "La lista está vacía." << endl;
        return 0;
    }

    int count = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}





template<class T>
void LinkedList<T>::addSorted(T info) {
    if( isEmpty() ){
        head = last = new Node<T>(info);
    }else if( info.getIdvideogame().compare(head->info.getIdvideogame()) < 0 ){
        addFirst( info );
    }else if( info.getIdvideogame().compare(last->info.getIdvideogame()) > 0){
        addLast( info );
    }else{
        Node<T>* act = head;
        Node<T>* ant = NULL;
        while( act->info.getIdvideogame().compare(info.getIdvideogame()) < 0 ){
            ant = act;
            act = act->next;
        }
        Node<T>* newNode = new Node<T>(info);
        ant->next = newNode;
        newNode->previous = ant;
        newNode->next = act;
        act->previous = newNode;
    }







}

