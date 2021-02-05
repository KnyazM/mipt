#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>



using namespace std;

  void Merge(int* arr, int l, int m, int r)
  {
      int i = 0, j = 0, k = 0;
      int size_l = m - l + 1;
      int size_r = r - m;

      /* create temp buffers */

      int* temp_L = new int[size_l];
      int* temp_R = new int[size_r];



      /* Copy data to temp buffers temp_L[size_l] and temp_R[size_r] */
      for (i = 0; i < size_l; i++)
          temp_L[i] = arr[l + i];

      for (j = 0; j < size_r; j++)
          temp_R[j] = arr[m + 1 + j];

      /* Merge the temp arrays back into arr[l..r]*/

      i = 0; // Initial index of first temp_buf
      j = 0; // Initial index of second temp_buf
      k = l; // Initial index of merged buffer
      while (i < size_l && j < size_r)
      {
          if (temp_L[i] <= temp_R[j])
          {
              arr[k] = temp_L[i];
              i++;
          }
          else
          {
              arr[k] = temp_R[j];
              j++;
          }

          k++;
      }

      /* Copy the remaining elements of temp_L[], if there are any */
      while (i < size_l)
      {
          arr[k] = temp_L[i];
          i++;
          k++;
      }

      /* Copy the remaining elements of temp_R[], if there are any */
      while (j < size_r)
      {
          arr[k] = temp_R[j];
          j++;
          k++;
      }

      delete[] temp_L;
      delete[] temp_R;
  }


  void Merge_sort(int* arr, int l, int r)
  {
    int m = (l + r)/2;

    if (l >= r)
      return;

    Merge_sort(arr, l, m);
    Merge_sort(arr, m + 1, r);

    Merge(arr, l, m, r);
  }

int main()
{
    int p = 10000;
while (p <= 1000000){
    int arr[p];
    srand( time (0));
    for (int i=0; i < p; i++){
    arr[i]=rand();
    }

auto begin = chrono::high_resolution_clock::now();

Merge_sort(arr, 0, p - 1);

auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;

    p += 10000;
}


    return 0;
}

