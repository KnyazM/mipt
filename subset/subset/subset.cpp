#include <iostream>

using namespace std;

//бинарное дерево поиска
struct subset_node {

    int key;
    subset_node* right;
    subset_node* left;

};

//инициализация пустого дерева
bool init(subset_node** sn){ 
    *sn = NULL;

        return true;
}

//существование
bool exist(subset_node* sn, int k) {
    if (sn == NULL)
        return false;
    if (sn->key == k)
        return true;
    if (k < sn->key)
        return exist(sn->left, k);
    if (k > sn->key)
        return exist(sn->right, k);


}

//поиск элемента в дереве, возвращает указатель на узел
subset_node* find(subset_node* sn, int k) {
    if (sn == NULL)
        return NULL;
    if (sn->key == k)
        return sn;
    if (k < sn->key)
        return find(sn->left, k);
    if (k > sn->key)
        return find(sn->right, k);
}

//добавление элемента в дерево, дубли игнорировать (false, если элемент дублируется)

bool insert(subset_node** sn, int k){
    //если дерево пустое, то создаем
    if (!(*sn))
    {
        *sn = new subset_node;
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
        insert(&(*sn)->left, k);
    if (k > (*sn)->key)
        insert(&(*sn)->right, k);
 }

//удаление элемента
subset_node* del_elem(subset_node* sn, int k) {

    if (sn == NULL)

        return sn;

    if (k == sn->key) {

        subset_node* tmp;

        if (sn->right == NULL)

            tmp = sn->left;

        else {

            subset_node* tmp2 = sn->right;

            if (tmp2->left == NULL) {

                tmp2->left = sn->left;

                tmp = tmp2;

            }

            else {

                subset_node* min = tmp2->left;

                while (min->left!= NULL) {

                    tmp2 = min;

                    min = tmp2->left;

                }

                tmp2->left = min->right;

                min->left = sn->left;

                min->right = sn->right;

                tmp = min;

            }

        }

        delete sn;
        sn = NULL;
        return tmp;

    }

    else if (k < sn->key)

        sn->left = del_elem(sn->left, k);

    else

        sn->right = del_elem(sn->right, k);

    return sn;

}

//тоже удаление, но то, которое надо
bool remove(subset_node** sn, int k) {
    if (exist(*sn, k))
    {
        del_elem(*sn, k);
        return true;
    }
 return false;
}


//количество элементов в дереве
unsigned int size(subset_node* sn) {
    unsigned int s = 0;
    if (sn == NULL)
        return 0;
    else
        return size(sn->left)+size(sn->right)+1;
}



//высота дерева
unsigned int height(subset_node* sn) {
    if (sn == NULL)
        return 0;
    return (max(height(sn->right), height(sn->left))+1);
    
}

//очистить всю используемую память
void destructor(subset_node* sn) {
    if (!sn)
        return;
      destructor(sn->left);
      destructor(sn->right);
    delete sn;
    sn = nullptr;
}

//
//void preorder(node* root)
//{
//    if (root == NULL)
//        return;
//    if (root->key)
//        printf("%d ", root->key);
//    preorder(root->left);
//    preorder(root->right);
//}

int main()
{
    subset_node *sn;

    cout << "Init test" << endl;
    cout << "bool of init: " << init(&sn) << " ";
    cout << "size: " << size(sn) << endl;

    cout << "Insert test" << endl;
    insert(&sn, 10);
    insert(&sn, 35);
    insert(&sn, 5);
    insert(&sn, 1);
    insert(&sn, 7);
    insert(&sn, 20); insert(&sn, 99);
    cout << "size: " << size(sn) << "  ";
    cout << "height: " << height(sn) << endl;

    //cout << "Remove test" << endl;
    //cout << find(sn, 5) << " ";
    //cout << remove(&sn, 5) << " ";
    //cout << find(sn, 10) << " ";
    ////cout << "size: " << size(sn) << "  ";


    //cout << "Del elem test" << endl;
    //cout << find(sn, 5) << " ";
    //cout << del_elem(sn, 5) << " ";
    ////cout << find(sn, 10) << " ";
    //cout << "size: " << size(sn) << "  ";
    //cout << del_elem(sn, 7) << " ";
    cout << "size: " << size(sn) << "  ";
    
    //cout << "Remove test" << endl;
    cout << exist(sn, 60) << " ";
    cout << remove(&sn, 5) << " ";
    cout << remove(&sn, 35)<< " ";
    cout << exist(sn, 60) << " ";
    cout << remove(&sn, 5);
    cout << "size: " << size(sn) << "  " << endl;

 cout << "Destructor test" << endl;
destructor(sn);
cout << size(sn);
}
