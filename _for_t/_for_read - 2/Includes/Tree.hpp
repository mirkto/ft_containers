//
// Created by 1 on 01.12.2020.
//

#ifndef CONTAINERS_TREE_HPP
#define CONTAINERS_TREE_HPP

#include <utility>
#include <functional>
//#include <bits/allocator.h>
//#include <crtdbg.h>
#include <iostream>

template<typename Key, typename T>
struct s_tree {
    std::pair<Key, T> *pair;
    s_tree *left;
    s_tree *right;
    s_tree *parent;
    bool isEnd;
};


class MapIterator;

template<class Key, class T, class Compare, class Alloc = std::allocator<std::pair<Key, T> > >
class Tree
{

private:
    s_tree<Key, T> *root;
    s_tree<Key, T> *end;
    s_tree<Key, T> *begin;
    bool 	isAddPair;
    Compare comp;
    int tabs;
    size_t size;
    Alloc allocator;

public:

	bool isAdd() const
	{
		return isAddPair;
	}

	Compare getComp() const {
        return comp;
    }

    size_t getSize() const {
        return size;
    }

    virtual ~Tree()
    {
    	allocator.deallocate(begin->pair, 1);
    	allocator.deallocate(end->pair, 1);
    	delete begin;
    	delete end;
    }

    Tree  *operator=(Tree *other)
    {
        this->size = other->size;
        this->end = new s_tree<Key, T>();
        this->begin = new s_tree<Key, T>();
        this->iter = new s_tree<Key, T>();
        std::pair<Key, T> *pair1 = allocator.allocate(1);
        std::pair<Key, T> *pair2 = allocator.allocate(1);
        std::pair<Key, T> *pair3 = allocator.allocate(1);
        this->end->pair = pair1;
        this->begin->pair = pair2;
        this->iter->pair = pair3;
        this->allocator = other->allocator;
        this->comp = other->comp;
        this->root = other->root;
        return (this);
    }

    Tree(const Compare comp = Compare(), const Alloc allocator = Alloc())
    {
        root = NULL;
        init_begin_end();
        tabs = 0;
        size = 0;
        this->comp = comp;
        this->allocator = allocator;
    }

    s_tree<Key, T> *getAnEnd() const {
        return end;
    }

    s_tree<Key, T> *getBegin() const {
        return begin;
    }

    s_tree<Key, T> *getRoot() const {
        return root;
    }

    void    init_begin_end()
    {
        end = new s_tree<Key, T>();
        begin = new s_tree<Key, T>();
        end->isEnd = true;
        begin->isEnd = true;
        std::pair<Key, T> *pair1 = allocator.allocate(1);
        std::pair<Key, T> *pair2 = allocator.allocate(1);
        end->pair = pair1;
        begin->pair = pair2;
    }

    s_tree<Key, T> *new_node(Key key, T val = T()) {
        s_tree<Key, T> *new_node = new s_tree<Key, T>();
        std::pair<Key, T> *pair = allocator.allocate(1);
        *pair = std::make_pair(key, val);
        new_node->pair = pair;
        new_node->isEnd = false;
        new_node->right = NULL;
        new_node->left = NULL;
        return (new_node);
    }

    void    setBorders()
    {
        s_tree<Key, T> *max = findMax();
        max->right = end;
        end->parent = max;
        s_tree<Key, T> *min = findMin();
        min->left = begin;
        begin->parent = min;
    }

    s_tree<Key, T> 	*add(Key key, T val) {
        isAddPair = false;
        if (!root) {
            root = new_node(key, val);
            root->parent = NULL;
            size++;
            isAddPair = true;
            setBorders();
            return (root);
        }
        s_tree<Key, T> *tree = root;
		s_tree<Key, T> *t = NULL;
        while (tree && !tree->isEnd) {
            if (!comp(key, tree->pair->first) && key != tree->pair->first) {
                if (tree->right != NULL && !tree->right->isEnd)
                    tree = tree->right;
                else {
                    t = new_node(key, val);
                    tree->right = t;
                    t->parent = tree;
                    size++;
                    isAddPair = true;
                    break;
                }
            } else if (comp(key, tree->pair->first)) {
                if (tree->left != NULL && !tree->left->isEnd)
                    tree = tree->left;
                else {
                    t = new_node(key, val);
                    tree->left = t;
                    size++;
                    isAddPair = true;
                    t->parent = tree;
                    break;
                }
            } else {
				isAddPair = false;
				return (tree);
            }
        }
        if (isAddPair)
            setBorders();
        return (t);
    }

        s_tree<Key, T> *add(s_tree<Key, T> *position, Key key, T val)
        {
            (void)position;
            if (!root) {
                root = new_node(key, val);
                root->parent = NULL;
                size++;
                setBorders();
                return (root);
            }
            s_tree<Key, T> *tree = root;
            s_tree<Key, T> *t = NULL;
            while (tree && !tree->isEnd) {
                if (!comp(key, tree->pair->first) && key != tree->pair->first) {
                    if (tree->right != NULL && !tree->right->isEnd)
                        tree = tree->right;
                    else {
                        t = new_node(key, val);
                        tree->right = t;
                        t->parent = tree;
                        size++;
                        break;
                    }
                } else if (comp(key, tree->pair->first)) {
                    if (tree->left != NULL && !tree->left->isEnd)
                        tree = tree->left;
                    else {
                        t = new_node(key, val);
                        tree->left = t;
                        size++;
                        t->parent = tree;
                        break;
                    }
                } else {
                    t = tree;
                    break ;
                }
            }
            setBorders();
            return (t);
        }

        s_tree<Key, T>  *findNode(const Key k)
        {
            s_tree<Key, T> *tree = root;
            while (tree && !tree->isEnd)
            {
                if (tree->pair->first == k)
                    return (tree);
                if (!comp(k, tree->pair->first))
                {
                    if (tree->right != NULL && !tree->right->isEnd)
                        tree = tree->right;
                    else
                        break ;
                }
                else if (comp(k, tree->pair->first))
                {
                    if (tree->left != NULL && !tree->left->isEnd)
                        tree = tree->left;
                    else
                        break ;
                }
            }
            return (NULL);
        }

    T   &find(Key key) {
        if (!root) {
            root = new_node(key);
            root->parent = NULL;
            size++;
            setBorders();
            return (root->pair->second);
        }
        s_tree<Key, T> *tree = root;
        s_tree<Key, T> *t = NULL;
        while (tree && !tree->isEnd) {
            if (tree->pair->first == key)
                return (tree->pair->second);
            if (!comp(key, tree->pair->first)) {
                if (tree->right != NULL && !tree->right->isEnd)
                    tree = tree->right;
                else {
                    t = new_node(key);
                    tree->right = t;
                    size++;
                    t->parent = tree;
                    break;
                }
            } else if (comp(key, tree->pair->first)) {
                if (tree->left != NULL && !tree->left->isEnd)
                    tree = tree->left;
                else {
                    t = new_node(key);
                    tree->left = t;
                    size++;
                    t->parent = tree;
                    break;
                }
            }
        }
        setBorders();
        return (t->pair->second);
    }

    bool    remakeRoot(s_tree<Key, T> *curr)
    {
        if (size > 0 && size <= 3 && curr == root)
        {
            s_tree<Key, T> *tmp = root;
            if (curr->right != end)
            {
				s_tree<Key, T> *min = findMin(curr->right);
                min->left = root->left;
                curr->left->parent = curr->right;
                curr->right->parent = NULL;
                root = curr->right;
            }
            else if (curr->left && curr->right == end)
            {
                curr->left->right = root->right;
                curr->left->parent = NULL;
                root = curr->left;
            }
            allocator.deallocate(tmp->pair, 1);
            delete tmp;
            tmp = NULL;
            size--;
            if (size == 0)
                root = NULL;
            return (true);
        }
        return (false);
    }

    void    remove(s_tree<Key, T> *curr)
    {
        //если root один
        if (remakeRoot(curr))
            return ;
        if (curr && !curr->left && !curr->right)
        {
            if (curr->parent->left == curr)
                curr->parent->left = NULL;
            else if (curr->parent->right == curr)
                curr->parent->right = NULL;
        }
        //усли узел имеет левое поддерево, но не имеет правого
        // (тут же случай для min указывающего на begin)(если min лист)
        if (curr && curr->left  && (!curr->right)) {
            if (curr->parent->right == curr)
                curr->parent->right = curr->left;
            else if (curr->parent->left == curr)
                curr->parent->left = curr->left;
            curr->left->parent = curr->parent;
        }
        //есть правое поддерево, но нет левого
        //(тут же случай для max указывающнего на end(если max лист)
        if (curr && curr->right  && (!curr->left)) {
            if (curr->parent->right == curr)
                curr->parent->right = curr->right;
            else if (curr->parent->left == curr)
                curr->parent->left = curr->right;
            curr->right->parent = curr->parent;
        }

        //если есть дети надо перецепить самый минимум по правой ветке на место удаляемой ноды
        if(curr && curr->right && curr->left) {
            s_tree<Key, T> *min = findMin(curr->right);
            //если правый ребенок не имеет левого поддерева(то есть сам является минимумом)
            if (min == curr->right && curr->right != end) {
                if (curr->parent && curr->parent->right == curr)
                    curr->parent->right = min;
                else if (curr->parent && curr->parent->left == curr)
                    curr->parent->left = min;
                min->parent = curr->parent;
                min->left = curr->left;
                if (curr->left)
                    curr->left->parent = min;
            }

            //если min не следующий элемент не является правым ребенком для удаляемой ноды
            else if (min != curr->right && curr->right != end) {
                //если у min есть дети до перецепить их к родителю min(дети у min только справа)
                if (min->right) {
                    min->right->parent = min->parent;
                    min->parent->left = min->right;
                }
                if (curr->parent && curr->parent->right == curr)
                    curr->parent->right = min;
                if (curr->parent && curr->parent->left == curr)
                    curr->parent->left = min;
                if (curr->right)
                    curr->right->parent = min;
                if (curr->left)
                    curr->left->parent = min;
                if (!min->right)
                    min->parent->left = NULL;
                min->parent = curr->parent;
                min->left = curr->left;
                min->right = curr->right;
            }

            //            50
            //случай типо / \  удаляем 50
            //          46  end

            else if (curr->right == end)
            {
                if (curr == root)
                {
                    s_tree<Key, T> *max = findMax(curr->left);
                    max->right = end;
                    end->parent = max;
                    delete curr->pair;
                    delete curr;
                    curr = curr->left;
                    allocator.deallocate(curr->pair, 1);
                    root = curr;
                    size--;
                    return ;
                }
                else {
                    curr->parent->right = curr->left;
                    curr->left->parent = curr;
                    end->parent = curr->left;
                    curr->left->right = end;
                }
            }
            if (curr == root)
                root = min;
        }
        if (curr) {
            allocator.deallocate(curr->pair, 1);
            delete curr;
        }
        size--;
    }

    s_tree<Key, T>    *findMin()
    {
        s_tree<Key, T> *tree = root;
        if (size == 0)
            return end;
        while (tree->left && !tree->left->isEnd)
            tree = tree->left;
        return (tree);
    }

    s_tree<Key, T>    *findMax()
    {
        s_tree<Key, T> *tree = root;
        if (size == 0)
            return end;
        while (tree->right && !tree->right->isEnd)
            tree = tree->right;
        return (tree);
    }

    s_tree<Key, T> *findMin(s_tree<Key, T> *curr)
    {
        while (curr->left)
            curr = curr->left;
        return (curr);
    }

    s_tree<Key, T> *findMax(s_tree<Key, T> *curr)
    {
        while (curr->right)
            curr = curr->right;
        return (curr);
    }

    s_tree<Key, T>    *inc(s_tree<Key, T> *tree)
    {
        if (tree->right)
            tree = findMin(tree->right);
        else if (tree->parent && tree->parent->left == tree)
            tree = tree->parent;
        else if (!tree->right)
        {
            Key key = tree->pair->first;
            tree = tree->parent;
            while (comp(tree->pair->first, key) && tree)
                tree = tree->parent;
        }
        return (tree);
    }

    s_tree<Key, T>    *dec(s_tree<Key, T> *tree)
    {
        if (tree->left)
            tree = findMax(tree->left);
        else if (tree->parent && tree->parent->right == tree)
            tree = tree->parent;
        else if (!tree->left)
        {
            Key key = tree->pair->first;
            tree = tree->parent;
            while (tree && !comp(tree->pair->first, key))
                tree = tree->parent;
        }
        return (tree);
    }

public:
    void print(s_tree<Key, T>* aBranch)
    {
        if (!aBranch || aBranch->isEnd) return;
        tabs += 5;
        print(aBranch->right);
        for (int i = 0; i < tabs; i++) std::cout << " ";
        if (!aBranch->isEnd)
            std::cout << aBranch->pair->first << ":" << aBranch->pair->second << std::endl;
        print(aBranch->left);
        tabs-= 5;
        return;
    }
};



#endif //CONTAINERS_TREE_HPP
