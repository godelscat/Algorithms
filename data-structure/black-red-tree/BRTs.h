#ifndef BRTS_H
#define BRTS_H
#include <iostream>
#include <memory>

namespace BRTs
{
    struct node {
        int key;
        int val;
        bool color = 1; //default black
        std::shared_ptr<node> parent;
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
        node () { } ;
        node (int k, int v) : key(k), val(v) {};
    };
    using sptr = std::shared_ptr<node>  ;

    class tree {
        private :
            sptr nil ;
            sptr root ;
            void inorder (sptr n);
            sptr min (sptr n);
            sptr search (int k);
            sptr ssor (sptr n);
            void ins_fixup (sptr n);
//            void del_fixup (sptr n);
        public :
            tree () {
                nil = std::make_shared<node>();
                root = nil;
            }
            void inshow () ;
            void left_rotate (sptr n);
            void right_rotate (sptr n);
            void ins (node &n);
 //           void del (node &n);

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

    void tree::left_rotate (sptr n) {
        //n is the root node of rotating subtree
        sptr x = n->left; //right child to be rotated
        n->right = x->left;
        if (x->left != nil) x->left->parent = n;
        x->parent = n->parent;
        if ( n->parent == nil ) {
            root = x;
        } else {
            if ( n = n->parent->left ) x = n->parent->left;
            else x = n->parent->right;
        }
        n->parent = x;
        x->left = n;
    }

    void tree::right_rotate(sptr n) {
        //n is the root node of rotating subtree
        sptr x = n->right; //left child to be rotated
        n->left = x->right;
        if (x->right != nil) x->right->parent = n;
        x->parent = n->parent;
        if ( n->parent == nil ) {
            root = x;
        } else {
            if ( n = n->parent->left ) x = n->parent->left;
            else x = n->parent->right;
        }
        n->parent = x;
        x->right= n;
    }

    void tree::ins_fixup (sptr n) {
        while ( ! n->parent->color ) {
            if ( n->parent == n->parent->parent->left ) {
                sptr uncle = n->parent->parent->right;
                // case 1 : uncle is red
                if ( ! uncle->color ) { 
                    n->parent->color = 1;
                    uncle->color = 1;
                    n = n->parent->parent;
                    n->parent->parent->color = 1;
                    continue;
                } //case 2 : uncle is black, and n is right child
                //after rotate, case 2 becomes case 3
                if ( uncle->color && n == n->parent->right ) {
                    n = n->parent;
                    tree::left_rotate (n);
                }
                //case 3 : uncle is black, and n is left child
                if ( uncle->color && n == n->parent->left ) {
                    n->parent->color = 1;
                    n->parent->parent->color = 0;
                    right_rotate(n->parent->parent);
                }
            } else {
                sptr uncle = n->parent->parent->left;
                // case 1 : uncle is red
                if ( ! uncle->color ) { 
                    n->parent->color = 1;
                    uncle->color = 1;
                    n->parent->parent->color = 1;
                    n = n->parent->parent;
                    continue;
                } //case 2 : uncle is black, and n is left child
                //after rotate, case 2 becomes case 3
                if ( uncle->color && n == n->parent->left) {
                    n = n->parent;
                    tree::right_rotate(n);
                }
                //case 3 : uncle is black, and n is right child
                if ( uncle->color && n == n->parent->right) {
                    n->parent->color = 1;
                    n->parent->parent->color = 0;
                    left_rotate(n->parent->parent);
                }
            }
        }
        root->color = 1; //set root color to black
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
        temp->parent = x; //set root->parent = nil
        if ( x == nil )  root = temp;
        else {
            if ( x->key < n.key ) x->right = temp;
            else x->left = temp;
        }
        temp->left = nil;
        temp->right = nil;
        temp->color = 0; //set insert color to red
        tree::ins_fixup (temp);
    }

}
#endif