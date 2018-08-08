#ifndef BRTS_H
#define BRTS_H
#include <iostream>
#include <memory>

namespace BRTs
{
    struct node {
        int key;
        int val;
        int color = 1; //default black
        std::shared_ptr<node> parent;
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
        node (int k, int v) : key(k), val(v) {};
    };
    using sptr = std::shared_ptr<node>  ;

    class tree {
        private :
            sptr nil;
            sptr root;
            void inorder (sptr n);
            sptr min (sptr n);
            sptr search (int k);
            sptr ssor (sptr n);
        public :
            tree () {
                root = nil;
            }
            void inshow () ;
           // void left_rotate (sptr n);
           // void right_rotate (sptr n);
            void ins (node &n);
           // void del (node &n);

    };

    void tree::inorder (sptr n) {
        if ( n != nil ) {
            inorder (n->left) ;
            std::cout << n->key << " " << n->val << " " << n->color << std::endl;
            inorder (n->right);
        }
    }

    void tree::inshow () {
        tree::inorder (root);
    }

    sptr tree::search (int k)  {
        sptr temp = root;
        while ( temp != nil  && temp->key != k) {
            if ( temp->key < k )  temp = temp->right;
            else temp = temp->right;
        }
        if ( temp = nil ) throw std::out_of_range ("No such key") ;
        else return temp;
    }

    sptr tree::min (sptr n) {
        while ( n->left != nil ) 
            n = n->left;
        return n;
    }

    sptr tree::ssor (sptr n) {
        if ( n->right != nil ) return tree::min(n->right);
        sptr temp = n->parent;
        while ( temp != nil && n != temp->left ) {
            n = temp;
            temp = temp->parent;
        }
        return temp;
    }

    void tree::ins (node &n) {
        sptr temp = std::make_shared<node> (n.key, n.val) ;
        sptr x = nil; //parent of insert node
        sptr y = root;
        while ( y != nil ) {
            x = y;
            if ( y->key < n.key ) y = y->right;
            else y = y->left;
        }
        temp->parent = x;
        if ( x == nil )  root = temp;
        else {
            if ( x->key < n.key ) x->right = temp;
            else x->left = temp;
        }
        temp->left = nil;
        temp->right = nil;
    }

}
#endif