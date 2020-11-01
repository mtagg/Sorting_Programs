#include <stdio.h>
#include <stdlib.h>


void QuickSort(int *arr, int lo, int hi);
void Swap(int *a, int *b);
int Parti(int *arr, int lo, int hi);


int main(){
  int arr[] = {1,2,6,7,9,0,5,4,6};
  QuickSort(arr, 3, 9);
  for (int i = 0; i < 9; i++){
    printf("%d\n", arr[i]);
    }
  return 0;
}

void QuickSort(int *arr, int lo, int hi){
    int temparr[hi - lo + 1];
    int top = -1;
    temparr[++top] = lo;
    temparr[++top] = hi;

    while (top >= 0){
      hi = temparr[top--];
      lo = temparr[top--];

      int p = Parti(arr, lo, hi);

      if (p - 1 > 1){
        temparr[++top] = lo;
        temparr[++top] = (p-1);
      }

      if (p + 1 < hi){
        temparr[++top] = p + 1;
        temparr[++top] = hi;
      }
    }
}




void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Parti(int *arr, int lo, int hi){
    int a = arr[hi];
    int i = (lo-1);
    int j;
    for (j = lo; j <= hi; j++){
      if (arr[j] <= a) {
        i++;
        Swap(&arr[lo], &arr[hi]);
      }
    }
    Swap(&arr[i+1], &arr[j]);
    return (i + 1);
}
