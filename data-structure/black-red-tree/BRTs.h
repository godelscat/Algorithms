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
            void del_fixup (sptr n);
        public :
            tree () {
                nil = std::make_shared<node>();
                root = nil;
            }
            void inshow () ;
            void left_rotate (sptr n);
            void right_rotate (sptr n);
            void ins (node &n);
            void del (node &n);

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
            else temp = temp->left;
        }
        if ( temp == nil ) throw std::out_of_range ("No such key") ;
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
        sptr x = n->right; //right child to be rotated
        n->right = x->left;
        if (x->left != nil) x->left->parent = n;
        x->parent = n->parent;
        if ( n->parent == nil ) {
            root = x;
        } else if ( n == n->parent->left ) {
            n->parent->left = x ;
        } else
            n->parent->right = x;
        n->parent = x;
        x->left = n;
    }

    void tree::right_rotate(sptr n) {
        //n is the root node of rotating subtree
        sptr x = n->left; //left child to be rotated
        n->left = x->right;
        if (x->right != nil) x->right->parent = n;
        x->parent = n->parent;
        if ( n->parent == nil ) {
            root = x;
        } else if ( n == n->parent->left ) {
            n->parent->left = x;
        } else 
            n->parent->right = x;
        n->parent = x;
        x->right= n;
    }

    void tree::ins_fixup (sptr n) {
        while ( ! n->parent->color ) {
            if ( n->parent == n->parent->parent->left ) {
                sptr uncle = n->parent->parent->right;
                // case 1 : uncle is red
                if ( (uncle != nil) && (! uncle->color) ) { 
                    n->parent->color = 1;
                    uncle->color = 1;
                    n->parent->parent->color = 0;
                    n = n->parent->parent;
                } 
                //case 2 : uncle is black, and n is right child
                //after rotate, case 2 becomes case 3
                else { 
                    if (  n == n->parent->right ) {
                        n = n->parent;
                        tree::left_rotate (n);
                    }
                //case 3 : uncle is black, and n is left child
                    n->parent->color = 1;
                    n->parent->parent->color = 0;
                    right_rotate(n->parent->parent);
                }
            } else {
                sptr uncle = n->parent->parent->left;
                // case 1 : uncle is red
                if ( (uncle != nil) && (! uncle->color)  ) { 
                    n->parent->color = 1;
                    uncle->color = 1;
                    n->parent->parent->color = 0;
                    n = n->parent->parent;
                } 
                //case 2 : uncle is black, and n is left child
                //after rotate, case 2 becomes case 3
                else {
                    if (  n == n->parent->left) {
                        n = n->parent;
                        tree::right_rotate(n);
                    }
                //case 3 : uncle is black, and n is right child
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

    void tree::del_fixup (sptr n) {
        //n is the labeled node, which has kind "double color"
        while ( n != root && n->color ) {
            if ( n == n->parent->left ) {
                //bro is n's brother
                sptr bro = n->parent->right;
                //case 1: bro is red
                if ( ! bro->color ) {
                    n->parent->color = 0;
                    bro->color = 1;
                    tree::left_rotate(n->parent);
                    bro = n->parent->right;
                }
                //after rotate, case 1 become case 2/3/4
                //case 2 : bro is black, and both children of bro are black
                if (  bro->left->color && bro->right->color ) {
                    bro->color = 0;
                    n = n->parent;
                } else {
                    //case 3 : bro is black and bro->right = red
                    if ( bro->right->color ) {
                        bro->left->color = 1;
                        bro->color =  0;
                        tree::right_rotate (bro) ;
                        bro = n->parent->right;
                    }
                    //after rotate, case 3 becomes case 4
                    bro->color = bro->parent->color;
                    n->parent->color = 1;
                    tree::left_rotate (n->parent);
                    n = root;
                }
            } else {
                sptr bro = n->parent->left;
                if ( ! bro->color ) {
                    n->parent->color = 0;
                    bro->color = 1;
                    tree::right_rotate(n->parent);
                    bro = n->parent->left;
                }

                if ( bro->left->color && bro->right->color ) {
                    bro->color = 0;
                    n = n->parent;
                } else {
                    if ( bro->left->color ) {
                        bro->right->color = 1;
                        bro->color = 0;
                        tree::left_rotate (bro);
                        bro = n->parent->left;
                    }

                    bro->color = bro->parent->color;
                    n->parent->color = 1;
                    tree::right_rotate (n->parent);
                    n = root;
                }
            }
        }
        n->color = 1;
    }

    void tree::del (node &nd) {
        sptr n = tree::search (nd.key) ;
        sptr temp; //node to be deleted
        if ( n->left == nil || n->right == nil )  
            temp = n;
        else 
            temp = tree::ssor (n) ;
        sptr x;
        if ( n->left != nil )  x = n->left;
        else x = n->right;  
        x->parent = temp->parent;
        if ( temp->parent == nil ) {
            root = x;
        } else {
            if ( temp = temp->parent->left ) 
                temp->parent->left = x;
            else 
                temp->parent->right = x;
        }
        if ( temp != n ) {
            n->key = temp->key;
            n->val = temp->val;
        }
        if ( temp->color ) 
            tree::del_fixup (x);
    }
}

#endif