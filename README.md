## Questão 01
Nesta questão deve-se implementar em C++ uma lista duplamente encadeada, com a suas devidas operações básicas:

## Node
Nó de uma lista duplamente encadeada:
- `void setObject(Object<Type> * object);`
    - Atribui um tipo genérico como valor do nó.
- `Object<Type> * getObject();`
    - Retona objeto-valor.
- `void setPrevious(Node * previous);`
    - Atribui referência a nó anterior.
- `Node<Type> *getPrevious();`
    - Retorna referência a nó anterior.
- `void setNext(Node * next);`
    - Atribui referência a nó seguinte.
- `Node<Type> *getNext();`
    - Retorna referência a nó seguinte.
- `bool hasNext();`
    - Verifica se o nó possui um elemento próximo.

### DCList
Lista duplamente encadeada:
- `void pushFront(Type value);`
    - Insere elemento no fim da lista.
- `void pushBack(Type value);`
    - Insere elemento no início da lista.
- `void popFront();`
    - Remove elemento do fim da lista.
- `void popBack();`
    - Remove elemento do início da lista.
- `bool find(Type value);`
    - Busca elemento.
- `bool isEmpty();`
    - Verifica se a lista está vazia.
- `void show();`
    - Exibe todos os elementos da lista.
- `Node<Type> * getHeadNode();`
    - Retorna primeiro elemento da lista.
- `Node<Type> * getTailNode();`
    - Retorna último elemento da lista.

## JsonParser
Parser JSON <-> Lista
- `DCList<Type> * jsonFileToDSList(std::string jsonFile);`
    - Carrega valores do arquivo JSON e retorna uma lista populada com esses valores.
- `void DSListToJson();`
    - Armazena valores da lista num arquivo JSON.
- `void put_int(int value);`
    - Template specialization (int)
- `void put_float(float value);`
    - Template specialization (float)
- `void put_string(std::string value);`
    - Template specialization (string)

(Qt Creator 4.8.2) Based on Qt 5.9.8 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6), 64 bit).