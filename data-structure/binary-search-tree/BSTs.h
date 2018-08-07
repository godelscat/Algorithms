#ifndef BSTS_H
#define BSTS_H
#include <iostream>
#include <memory>

namespace BSTs 
{
    struct node {
        int key;
        int val;
        std::shared_ptr<node> parent;
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
        node (int k, int v) : key(k), val(v) {} ;
    };

    using sptr = std::shared_ptr<node>;

    class tree {
        private :
            sptr root; 
        public :
            void inorder ( sptr n ) ;
            void inshow ( ) ;
            sptr search ( int k ) ;
            sptr max ( sptr n ) ;
            sptr min ( sptr n ) ;
            sptr ssor ( sptr n ) ;
            sptr psor ( sptr n ) ;
            void ins ( node &n ) ;
            void del ( node &n ) ;
    };

    void tree::inorder( sptr n ) {
        if ( n != nullptr ) {
            inorder ( n->left );
            std::cout << n->key << " " << n->val << std::endl;
            inorder ( n->right ) ;
        }
    }

    void tree::inshow () {
        tree::inorder(root);
    }

    sptr tree::search ( int k ) {
        sptr temp = root;
        while ( temp != nullptr && temp->key != k ) {
            if ( temp->key < k )  temp = temp->right;
            else temp = temp->left;
        }
        if ( temp == nullptr ) throw std::out_of_range ("No such key") ;
        else return temp;
    }

    sptr tree::min ( sptr n ) {
        while ( n->left != nullptr ) 
            n = n->left;
        return n ;
    }

    sptr tree::max ( sptr n ) {
        while ( n->right != nullptr ) 
            n = n->right;
        return n;
    }

    sptr tree::ssor ( sptr n ) {
        if ( n->right != nullptr ) return tree::min ( n->right ) ;
        sptr temp = n->parent;
        while ( n != temp->left  && temp != nullptr ) {
            n = temp;
            temp = temp->parent;
        }
        return temp;
    }

    sptr tree::psor ( sptr n ) {
        if ( n->left != nullptr ) return tree::max ( n->left ) ;
        sptr temp = n->parent;
        while ( n!= temp->right && temp != nullptr ) {
            n = temp;
            temp = temp->parent;
        }
        return temp;
    }

    void tree::ins ( node &n ) {
       sptr tempn = std::make_shared<node>(n.key, n.val);
       if  ( root == nullptr )  {
           root = tempn;
           return ;
       }
       sptr temp = root;
       sptr temp1;
       while ( temp != nullptr  ) {
           temp1 = temp;
           if ( temp->key < n.key ) temp = temp->right;
           else temp = temp->left; 
       }
       tempn->parent = temp1;
       if ( temp1->key < n.key ) temp1->right = tempn;
       else  temp1->left = tempn;
    }

    void tree::del ( node &nd ) {
        sptr n = tree::search (nd.key);
        if ( n->left == nullptr &&  n->right == nullptr ) {
            n.reset();
            return ;
        } 
        if ( n->left == nullptr || n->right == nullptr ) {
            sptr temp ;
            if ( n->left == nullptr ) temp = n->right;
            else temp = n->left;
            if ( n->parent == nullptr ) {
                root = temp ;
                n.reset();
                return ;
            }
            if ( n == n->parent->left ) n->parent->left = temp;
            else n->parent->right = temp;
            temp->parent = n->parent;
            n.reset();
            return ;
        }
        sptr tempss = tree::ssor (n) ;
        n->key = tempss->key;
        n->val = tempss->val;
        tempss.reset();
        return ;
    }
}

#endif