#ifndef SET_H
#define SET_H
#include "AVLTree.h"

//custom set class that uses AVLTree and the iterator functions from AVLTree as well
template <class T>
class set
{
    public:
        set();
        ~set();
        void insert(const T &insertItem);
        void erase(const T &deleteItem);
        void swap(set &other);
        void clear();
        size_t count(const T &searchItem) const;
        T *find(const T &searchItem) const;

        //public Iterator class
        class Iterator {
            public:
                //public iterator constructor and functions that return the avl tree iterator functions
                Iterator(typename AVLTree<T>::Iterator it) : avlIterator(it) {}
                bool hasNext() { return avlIterator.hasNext(); }
                T next() { return avlIterator.next(); }
            private:
                //private avl tree iterator
                typename AVLTree<T>::Iterator avlIterator;
        };

        Iterator begin() { return Iterator(tree.begin()); }

    private:
        AVLTree<T> tree;
};
        
template <class T>
set<T>::set()
{
}

template <class T>
set<T>::~set()
{
}

//Insert an item into the set. avl tree insert function uses
//the insertToAVL which only allows unique items to be inserted
template <class T>
void set<T>::insert(const T &insertItem)
{
    tree.insert(insertItem);
}

template <class T>
void set<T>::erase(const T &deleteItem){
    //tree.deleteNode(deleteItem);
}

/* Below I added some other functions found from the set class in the STL */

//swap the contents of two sets
template <class T>
void set<T>::swap(set<T> &other){
    AVLTree<T> temp = tree;
    tree = other.tree;
    other.tree = temp;
}

//clear the whole set
template <class T>
void set<T>::clear(){
    // for(int i = tree.begin(); i != tree.end(); i++){
    //     tree.deleteNode(*i);
    // }
}

//count the number of items, if found return 1 since there are no duplicates
template <class T>
size_t set<T>::count(const T &searchItem) const{
    for (typename AVLTree<T>::Iterator it = tree.begin(); it.hasNext();){
        if(it.next() == searchItem){
            return 1;
        }
    }
    return 0;
}

//find the item in the set
template <class T>
T *set<T>::find(const T &searchItem) const{
    for (typename AVLTree<T>::Iterator it = tree.begin(); it.hasNext();){
        T currentItem = it.next();
        if(currentItem == searchItem){
            return &currentItem;
        }
    }
    return nullptr;
}

#endif