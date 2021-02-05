#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>


using namespace std;

int arr[1000000];

void bubble_sort (int n, std::istream& dest){

    srand( time (0));
    int arr[n];
    for (int i=0; i<n; i++){
        arr[i]=rand();
    }

    auto begin = chrono::high_resolution_clock::now();

    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    dest << "time in msecs = " << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
    dest << endl;

}

int main()
{
   istream out;

    out.open("output.txt");
   int k = 10;
  // while (k <= 1000000){
    bubble_sort(k, out);
   /* k += 10000;
   }*/

   out.close();

    return 0;
}
