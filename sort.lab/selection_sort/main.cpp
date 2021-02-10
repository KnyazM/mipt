#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int arr[1000000];

void selection_sort(int n) {

    srand( time (0));
    int a_min = 0, tmp = 0, num_min=0;
    int arr[n];
    for (int i=0; i<n; i++){
    arr[i]=rand();
    }
auto begin = chrono::high_resolution_clock::now();
   for (int i = 0; i < n; i++)
    {
        a_min = arr[i];
        num_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < a_min)
            {
                a_min = arr[j];
                num_min = j;
                tmp = arr[i];
            arr[i] = a_min;
            arr[num_min] = tmp;
            }
        }
    }


auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;


}

int main()
{
 int k=10000;
 while (k <= 1000000){
    selection_sort(k);
    k+=10000;
 }


    return 0;
}
