#ifndef OBJECT_HPP
#define OBJECT_HPP

template<class Type> class Object {

public:
    Object(Type value);
    ~Object();
    Type getValue();
    void setValue(Type value);
private:
    Type value;
};

template<class Type>
Object<Type>::Object(Type value){
    this->value = value;
}

template<class Type>
Object<Type>::~Object(){}

template<class Type>
Type Object<Type>::getValue()
{
    return this->value;
}

template<class Type>
void Object<Type>::setValue(Type value)
{
    this->value = value;
}

#endif // OBJECT_HPP
