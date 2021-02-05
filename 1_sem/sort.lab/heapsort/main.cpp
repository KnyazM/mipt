#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

int arr[1000000];

//построение дерева
//преобразование применяется к узлу; n - размер массива (кучи);
//происеивание снизу вверх

void heapify (int *arr, int n, int i){

int largest = i; //наибольший элемент - корень
int left = 2*i + 1;
int right = 2*i + 2;

if (left < n && arr[left] > arr[largest]){

    largest = left;
}

if (right < n && arr[right] > arr[largest]){

    largest = right;
}
//если наибольший не корень
if (largest != i){

    swap(arr[i], arr[largest]);
heapify (arr, n, largest);
    }

}

void heap_sort (int *arr, int n){

for (int i =  n/2 - 1; i >= 0; i--){ //i = n/2 - 1 - первый индекс неконечного узла;
heapify(arr, n, i); //собираем убывающую кучу: каждое поддерево выстраиваем снизу вверх
}
for (int i = n - 1; i >= 0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0); //получаем в корне новый наибольший элемент
        }

}

int main()
{
    int n = 10000;

    while (n <= 1000000){

    int arr[n];
    srand( time (0));
    for (int i=0; i<n; i++){
    arr[i]=rand();
    }

auto begin = chrono::high_resolution_clock::now();

    heap_sort(arr, n);

auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;
    n += 10000;


   /*for (int i = 0; i < n; i++){
        cout << arr[i] << " ";*/
   }

    return 0;
}
