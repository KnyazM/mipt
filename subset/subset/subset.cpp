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

//удаление элемента из дерева
bool remove(subset_node** sn, int k)
{
    if ((*sn) == NULL)
        return false;

    if ((*sn)->key == k)
    {
        subset_node* temp;

        if (!(*sn)->right)
        {
            temp = (*sn)->left;
        }
        else
        {
            subset_node* temp2 = (*sn)->right;

            if (!temp2->left)
            {
                temp2->left = (*sn)->right;
                temp = temp2;
            }
            else
            {
                subset_node* min_el = temp2->left;
                while (min_el->left != NULL)
                {
                    temp2 = min_el;
                    min_el = temp2->left;
                }
                temp2->left = min_el->right;
                min_el->left = (*sn)->left;
                min_el->right = (*sn)->right;
                temp = min_el;
            }

        }
        /*delete (*sn);*/
        //(*sn) = temp;
        /*delete temp;*/
        //temp = NULL;

           return true;
    }


    if (k < (*sn)->key)
        remove(&(*sn)->left, k);
    if (k > (*sn)->key)
        remove(&(*sn)->right, k);

    return true;
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
    sn = NULL;
}

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

    cout << "Remove test" << endl;
    cout << find(sn, 5) << " ";
    cout << remove(&sn, 5) << " ";
    cout << find(sn, 10) << " ";
    //cout << "size: " << size(sn) << "  ";


    cout << "Destructor test" << endl;
    destructor(sn);
    /*cout << size(sn);*/
}
