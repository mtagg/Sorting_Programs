//MergeSort

#include <stdio.h>

void sort(int* arr, int lo, int mid, int hi);
void merge(int* arr, int lo, int hi);

void main(void){
     int unsorted [] = {11,16,123,1,6,7,11,10,12};
     int n = sizeof(unsorted)/sizeof(unsorted[0]);

     puts("Unsorted array:");
     for( int i = 0; i < n; i++){
          printf("%d, ",unsorted[i]);
     }puts("");

     merge(unsorted, 0, n);
     puts("Sorted array:");
     for (int i = 0; i < n; i++){
          printf("%d, ",unsorted[i]);
     }puts("");


}


void sort(int* arr, int lo, int mid, int hi){

     //1. create 3 variables, one to increment for low, one for high, 
     //and one for the main array.
     
     int L [mid-lo];
     int H [hi-mid];
     int i = 0;
     int j = 0;
     int k = lo;

     //2. create a Low (L) and high (H) array to sort
     while (i < mid-lo){
          L[i++] = arr[k++];
     }
     while (j < hi-mid){
          H[j++] = arr[k++];
     }


     //3. first sort until one array is completely used
     i = 0;
     j = 0;
     k = lo;
     while (i < (mid-lo) && j < (hi-mid)){  
          if (L[i] <= H[j])
               arr[k++] = L[i++];
          else 
               arr[k++] = H[j++];              
     } 


     //4. disperse of all remaining array members of whichever
     // array has unsorted members left 

          while (i < mid-lo){
               arr[k++] = L[i++];
          }
          while (j < hi-mid){
               arr[k++] = H[j++];
          }
     }



void merge(int* arr, int lo, int hi){

     //1. basic case to turn around the recursion process and unstack

     if (lo >= hi-1) return;
     else{
          //2. send out lo-mid and mid-hi arrays to merge() 
     //     ---- divide and conquor method----
          int mid = (lo+hi)/2;
          merge(arr,lo,mid);
          merge(arr,mid,hi);
          //3.send arrays to sorting algorithm 
          sort(arr,lo,mid,hi);
     }
     

    
     

   


}