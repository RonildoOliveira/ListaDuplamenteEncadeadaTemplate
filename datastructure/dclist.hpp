#ifndef DCLIST_HPP
#define DCLIST_HPP

#include "node.hpp"
#include <iostream>

template<class Type>
class DCList
{
public:
    DCList();
    void pushFront(Type value);
    void pushBack(Type value);

    void popFront();
    void popBack();

    bool find(Type value);
    bool isEmpty();
    void show();

    Node<Type> * getHeadNode();
    Node<Type> * getTailNode();

private:
    Node<Type> * head_node = nullptr;
    Node<Type> * tail_node = nullptr;
};

template<class Type>
DCList<Type>::DCList()
{
    this->head_node  = nullptr;
    this->tail_node  = nullptr;
}

template<class Type>
void DCList<Type>::pushFront(Type value)
{
    Node<Type> * node = new Node<Type>(value);

    /** Empty list **/
    if(this->head_node == nullptr){
        head_node = node;
        tail_node = node;
    }
    else if(this->head_node != nullptr){
        tail_node->setNext(node);
        node->setPrevious(tail_node);
        tail_node = node;
    }
}

template<class Type>
void DCList<Type>::pushBack(Type value)
{
    Node<Type> * node = new Node<Type>(value);

    /** Empty list **/
    if(this->head_node == nullptr){
        head_node = node;
        tail_node = node;
    }
    else if(this->head_node != nullptr){
        head_node->setPrevious(node);
        node->setNext(head_node);
        head_node = node;
    }
}

template<class Type>
void DCList<Type>::popFront()
{
    Node<Type> * node = tail_node->getPrevious();
    node->setNext(nullptr);
    tail_node = node;
}

template<class Type>
void DCList<Type>::popBack()
{
    Node<Type> * node = head_node->getNext();
    head_node->setNext(nullptr);

    head_node = node;
}


template<class Type>
bool DCList<Type>::find(Type value)
{
    Node<Type> * node = head_node;

    if(node != nullptr){
        while (node != nullptr) {
            if(node->getObject()->getValue() == value){
                return true;
            }
            node = node->getNext();
        }
    }

    return false;
}

template<class Type>
bool DCList<Type>::isEmpty()
{
    if(head_node == nullptr){
        return true;
    }
    return false;
}

template<class Type>
void DCList<Type>::show()
{
    Node<Type> * node = head_node;

    if(this->isEmpty()){
        std::cerr << "empty"<< std::endl;
    }else{
        while (node != nullptr) {
            std::cout << node->getObject()->getValue() << std::endl;
            node = node->getNext();
        }
    }
}

template<class Type>
Node<Type> *DCList<Type>::getHeadNode()
{
    return this->head_node;
}

template<class Type>
Node<Type> *DCList<Type>::getTailNode()
{
    return this->tail_node;
}

#endif // DCLIST_HPP
