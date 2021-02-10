#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int a[1000000];

void insertion_sort(int n){

    srand( time (0));
    int temp = 0, prev = 0;
    int arr[n];
    for (int i=0; i<n; i++){
    arr[i]=rand();
    }

auto begin = chrono::high_resolution_clock::now();

    for(int i=1; i < n; i++){
            temp = arr[i];
            prev = i-1;
            while (prev>=0 && arr[prev]>temp){
                arr[prev+1]=arr[prev];
                arr[prev]=temp;
                prev--;
            }
        }


auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;

}

int main()
{

int k = 10000;

while (k <= 510000){
    insertion_sort(k);
    k += 10000;
}
    return 0;
}
