#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int a[1000000];

void quick_sort (int *a, int n){

int i = 0, j = n - 1, temp = 0;
int p = a[n/2];




while (i <= j) {

while (a[i] < p){
    i++;
}
while (a[j] > p){
    j--;
}

if (i <= j){
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    i++;
    j--;
    }
}
//счетчики меняются местами
if (j > 0){
    quick_sort (a, j+1); // подмассив слева содержит более 1 эл
}
if (i < n){
    quick_sort (&a[i], n - i); // подмассив справа содержит более 1 эл
}



}

int main()
{
    int n = 10000;

    while (n <= 1000000){

    int a[n];
    srand( time (0));
    for (int i=0; i<n; i++){
    a[i]=rand();
    }

auto begin = chrono::high_resolution_clock::now();

    quick_sort(a, n);

auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;
    n += 10000;


  /*  for (int i = 0; i < n; i++){
        cout << a[i] << " ";*/
    }

    return 0;
}

