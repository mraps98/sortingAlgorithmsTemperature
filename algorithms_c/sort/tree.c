/* Source: https://iq.opengenus.org/tree-sort/  */
#include <stdlib.h>
#include "tree.h"
long my_index = 0;
struct btreenode
{
    struct btreenode *leftchild ;
    long data ;
    struct btreenode *rightchild ;
};
static void insert ( struct btreenode **sr, long num) ;
static void inorder ( struct btreenode *sr, long* arr);
void tree_sort(long* arr, long size)
{
    struct btreenode *bt ;
    long i ;
    bt = NULL ;
    for (i=0; i<=size; i++)
        insert ( &bt, arr[i] ) ;
    inorder (bt, arr) ;
}
static void insert ( struct btreenode **sr, long num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;
        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}
static void inorder ( struct btreenode *sr, long* arr)
{
    if (sr!=NULL)
    {
        inorder(sr->leftchild, arr);
	arr[my_index] = sr->data;
	my_index++;
        inorder(sr->rightchild, arr);
    }
}
