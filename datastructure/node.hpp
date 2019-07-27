#ifndef NODE_HPP
#define NODE_HPP

#include "template/object.hpp"

template<class Type>
class Node
{
public:
    Node(Type value);

    void setObject(Object<Type> * object);
    Object<Type> * getObject();

    void setPrevious(Node * previous);
    Node<Type> *getPrevious();

    void setNext(Node * next);
    Node<Type> *getNext();

    bool hasNext();

private:
    Object<Type> * object  = nullptr;
    Node * previous  = nullptr;
    Node * next  = nullptr;
};

template<class Type>
Node<Type>::Node(Type value)
{
    Object<Type> * object = new Object<Type>(value);
    this->setObject(object);
    this->setNext(nullptr);
    this->setPrevious(nullptr);
}

/** Previous **/
template<class Type>
void Node<Type>::setPrevious(Node * previous)
{
    this->previous = previous;
}

template<class Type>
Node<Type> * Node<Type>::getPrevious()
{
    return this->previous;
}

/** Next **/
template<class Type>
void Node<Type>::setNext(Node * next)
{
    this->next = next;
}

template<class Type>
Node<Type> * Node<Type>::getNext()
{
    return this->next;
}


/** Checking **/
template<class Type>
bool Node<Type>::hasNext()
{
    if(this->getNext() == nullptr){
        return false;
    }
    return true;
}

/** Object **/
template<class Type>
void Node<Type>::setObject(Object<Type> * object)
{
    this->object = object;
}

template<class Type>
Object<Type> * Node<Type>::getObject()
{
    return this->object;
}

#endif // NODE_HPP
