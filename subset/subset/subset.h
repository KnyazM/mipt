
#ifndef __SUBSET_H__
#define __SUBSET_H__


using namespace std;

//binary search tree
struct subset_node {

    int key;
    subset_node* right;
    subset_node* left;

};

//initialization
bool init(subset_node** sn) {
    *sn = NULL;

    return true;
}


//find an element in the tree
subset_node* find(subset_node* sn, int k) {
    if (sn == NULL)
        return NULL;
    if (sn->key == k)
        return sn;
    if (k < sn->key)
        return find(sn->left, k);
    else if (k > sn->key)
        return find(sn->right, k);
}

//add the element to the tree, ignore doubles
bool insert(subset_node** sn, int k) {

    if (!(*sn))
    {
        *sn = new subset_node;
        (*sn)->key = k;
        (*sn)->right = NULL;
        (*sn)->left = NULL;
        return true;
    }

    if (find(*sn, k) != NULL)
        return false;

    if (k < (*sn)->key)
        return insert(&(*sn)->left, k);
    else if (k > (*sn)->key)
        return insert(&(*sn)->right, k);
}

//delete the element from the tree
void del_elem(subset_node** sn, int k) {

    if (*sn == NULL)
        return;
    if ((*sn)->left)
        del_elem(&(*sn)->left, k);
    if ((*sn)->right)
        del_elem(&(*sn)->right, k);

     if ((*sn)->left == NULL)
     {
         subset_node* right = (*sn)->right;
         delete *sn;
         *sn = right;
     }
     else if ((*sn)->right == NULL)
     {
         subset_node* left = (*sn)->left;
         delete *sn;
         (*sn) = left;
     }
     else
     {
         
         subset_node* right = (*sn)->right;
         if (right->left == NULL)
         {
             (*sn)->key = right->key;
             (*sn)->right = right->right;
             delete right;
         }
         else
         {
             subset_node* min_parent = right;
             while (min_parent->left->left != NULL)
             {
                 min_parent = min_parent->left;
             }
             subset_node* min = min_parent->left;
             min_parent->left = min->right;
             delete min;
         }
     }

}

//"del_elem" but for profiler
bool remove(subset_node** sn, int k) {

    if (*sn == NULL)
        return false;
    if ((*sn)->key == k)
    {
        del_elem(&(*sn), k);
        return true;
    }
    if (k < (*sn)->key)
        return remove(&(*sn)->left, k);

    return remove(&(*sn)->right, k);

}


//number of elements in the tree
unsigned int size(subset_node* sn) {
    unsigned int s = 0;

    if (sn == nullptr)
        return 0;

    else
        return size(sn->left) + size(sn->right) + 1;
}

//the height og the tree
unsigned int height(subset_node* sn) {
    if (sn == NULL)
        return 0;
    return (max(height(sn->right), height(sn->left)) + 1);

}

//clear all memory used
void destructor(subset_node* sn)
{
    if (sn == NULL);
    return;
    if (sn->left)
        destructor(sn->left);
    if (sn->right)
        destructor(sn->right);

    sn->right = NULL;
    sn->left = NULL;
    sn = NULL;

    delete sn;
}

//for DFS
void visit(subset_node* sn, int* a, int* i) {
    if (sn == NULL)
        return;

    visit(sn->left, a, i);
    a[*i] = sn->key;
    (*i)++;
    visit(sn->right, a, i);
}

//depth-first search
int* DFS(subset_node* sn) {
    int i = 0;
    unsigned int s = size(sn);
    int* a = new int[s];
    visit(sn, a, &i);
    return a;
}




#endif //__SUBSET_H__
