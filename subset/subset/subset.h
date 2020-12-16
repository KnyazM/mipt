
#ifndef __SUBSET_H__
#define __SUBSET_H__

//nclude <iostream>

//const int POISON_VALUE = -666;

using namespace std;



//бинарное дерево поиска
struct subset_node {

    int key;
    subset_node* right;
    subset_node* left;

};

//инициализация пустого дерева
bool init(subset_node** sn) {
    *sn = NULL;

    return true;
}

////существование
//bool exist(subset_node* sn, int k) {
//    if (sn == NULL)
//        return false;
//    if (sn->key == k)
//        return true;
//    if (k < sn->key)
//        return exist(sn->left, k);
//    else if (k > sn->key)
//        return exist(sn->right, k);
//}

//поиск элемента в дереве, возвращает указатель на узел
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

//добавление элемента в дерево, дубли игнорировать (false, если элемент дублируется)

bool insert(subset_node** sn, int k) {
    cout << " a ";

    //если дерево пустое, то создаем
    if (!(*sn))
    {  *sn = new subset_node;
        (*sn)->key = k;
        (*sn)->right = NULL;
        (*sn)->left = NULL;
        return true;
    }
    //уже существует, возвращаем false
    if (find(*sn, k) != NULL)
        return false;
    //не существовал ранее, снова вызываем insert
    if (k < (*sn)->key)
        return insert(&(*sn)->left, k);
    else if (k > (*sn)->key)
        return insert(&(*sn)->right, k);
}

//удаление элемента
void del_elem(subset_node* sn, int k) {
  if (sn->left == NULL)//нет левого потомка
  {
      subset_node* right = sn->right; //подставляем правое
      delete sn;
      sn = right;
  }
  else if (sn->right == NULL)//нет правого потомка
  {
      subset_node* left = sn->left;
      delete sn;
      sn = left;
  }
  else//есть оба потомка
  {
      //ищем минимальный справа
      subset_node* right = sn->right;
      if (right->left == NULL)//у правого нет левого потомка - он сам по себе минимальный
      {
          sn->key = right->key;
          sn->right = right->right;
          delete right;
      }
      else//у правого есть левый потомок - минимальный где-то там будет
      //найдем родителя минимального элемента
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

//тоже удаление, но то, которое надо
bool remove(subset_node** sn, int k) {

    if (sn == NULL)
        return false;
    if ((*sn)->key == k)
    {
        del_elem(*sn, k);
        return true;
    }        
    if (k < (*sn)->key)
        return remove(&(*sn)->left, k);
    else if (k > (*sn)->key)
        return remove(&(*sn)->right, k);

}


//количество элементов в дереве
unsigned int size(subset_node* sn) {
    unsigned int s = 0;

    if (sn == nullptr)
        return 0;

    //if ((sn->right == NULL) & (sn->left == NULL))
    //{
    //    //if (sn->key == POISON_VALUE)
    //      //  return 0;

    //    return 1;
    //}

    else
        return size(sn->left) + size(sn->right) + 1;
}


//высота дерева
unsigned int height(subset_node* sn) {
    if (sn == NULL)
        return 0;
    return (max(height(sn->right), height(sn->left)) + 1);

}

//очистить всю используемую память
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
        //sn->key = POISON_VALUE;
        sn = NULL;

        delete sn;
}

void visit(subset_node* sn, int* a) {
    int i = 0;
    if (sn == NULL)
        return;
    visit(sn->left, a);
    a[i] = sn->key;
    i++;

    visit(sn->right, a);
}

int* DFS(subset_node* sn) {
    int* a = new int[size(sn)];
    visit(sn, a);
    return a;
}




#endif //__SUBSET_H__