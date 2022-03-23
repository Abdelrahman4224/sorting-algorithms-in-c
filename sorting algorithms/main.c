#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000000






void printArray(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
         printf("%d,", a[i]);
    }
    printf("\n");
}
int * fillArray(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        a[i]= 1 + rand() % 1000000;
    }
    return a;
}







int* buildmaxheap(int a[], int n)

{

    int heapsize = n;

    int j;

    for (j = n/2; j >= 0; j--) {

        maxheapify(a, j, heapsize);

    }

    return a;

}

void maxheapify(int a[], int i, int heapsize)

{

    int temp, largest, left, right, k;

    left = (2*i);

    right = ((2*i)+1);

    if (left >= heapsize)

        return;

    else {

        if (left < (heapsize) && a[left] > a[i])

            largest = left;

        else

            largest = i;

        if (right < (heapsize) && a[right] > a[largest])

            largest = right;

        if (largest != i) {

            temp = a[i];

            a[i] = a[largest];

            a[largest] = temp;

            maxheapify(a, largest, heapsize);

        }

    }

}


int * Heapsort(int a[],int n){
int *m = calloc(MAX, sizeof(int));

m = buildmaxheap(a,n);
int temp ,j,i=0;

for (j = n-1; j >= 0; j--) {
     temp = m[i];
     m[i]=m[j];
     m[j]=temp;
     buildmaxheap(m,j);

        }

return m;

}



int random(int first , int last){
int i;
return rand() % (last + 1 - first) + first;
}

int randompartition(int a[],int first,int last){
int i,temp;
i = random(first,last);
temp = a[last];
a[last] = a[i];
a[i]=temp;
return partition(a,first,last);
}

void quicksort(int a[],int first,int last){
int pivot ;
if (first < last){

    pivot = randompartition(a,first,last);
    quicksort(a,first,pivot-1);
    quicksort(a,pivot+1,last);

}



}



int partition(int a[],int first,int last){

int i , j ,temp,pivot;
pivot = a[last];
j = first - 1;
for(i = first ; i <= last - 1; i++){

   if (a[i]<= pivot){

  j++;
   temp = a[j];
  a[j] = a[i];
  a[i] = temp;
  }
  }

  temp = a[j+1];
  a[j+1] = a[last];
  a[last] = temp;
  return j+1;

}







int * bubblesort(int a[],int size){
int i,j,temp;
for(i=0;i<size-1;i++){
    for(j=0;j<size-i-1;j++){
        if (a[j]>a[j+1]){
          temp = a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
         }

    }



}
return a;
}

int * selectionsort(int a[],int size){
int i=0,j,temp,min;
for (i = 0; i < size; i++)
    {
        min = i;
       for (j = i+1; j <size; j++) {
          if (a[j] < a[i]){
                min = j;
         temp = a[min];
        a[min] = a[i];
        a[i]=temp;
          }
    }
    }

return a;
}

int * insertionsort(int a[],int n){
     int i, k, j;
    for (i = 1; i < n; i++) {
        k = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
    }


return a ;

}

void merge(int a[], int first, int last, int pivot)
{
    int i, j, k;
    int n1 = pivot - first + 1;
    int n2 =  last - pivot;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = a[first + i];
    for (j = 0; j < n2; j++)
        R[j] = a[pivot + 1+ j];

    i = 0;
    j = 0;
    k = first;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

   while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int first, int last)
{
    if (first < last)
    {
        int pivot = first+(last - first)/ 2;

        mergeSort(a, first, pivot);
        mergeSort(a, pivot+1 , last);

        merge(a, first, last, pivot);
    }
}


void main()

{
while(1){
    int i, t, n,s,first,last,back;

	int *a = calloc(MAX, sizeof(int));

    int *m = calloc(MAX, sizeof(int));

    system("cls");
    printf("Choose desired operation \n");
    printf("(1)  BULID MAX HEAP\n");
    printf("(2)  HEAP SORT\n");
    printf("(3)  Quick SORT\n");
    printf("(4)  Bubble Sort\n");
    printf("(5)  Selection Sort\n");
    printf("(6)  Insertion Sort\n");
    printf("(7)  Merge Sort\n");
    printf("(8)  running time\n");
    printf("(9)  Start Over\n");
    printf("(10) Exit\n");
    scanf("%d", &s);
    switch(s){
        case(1):{
            system("cls");

             printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
    m = buildmaxheap(a, n);

    printf("The heap is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", m[t]);

    }
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}

case(2):{
    system("cls");
     printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
 m = Heapsort(a, n);

    printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", m[t]);


}
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}
case(3):{
    system("cls");
     printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

}
 first = 0;
 last  = n-1;
 quicksort(a,first,last);
 printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", a[t]);

}

printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}
case(4):{
    system("cls");

 printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
m = bubblesort(a,n);

 printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", m[t]);


}
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}
case(5):{
    system("cls");
 printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
m = selectionsort(a,n);

 printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", m[t]);


}
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}
case(6):{
    system("cls");
 printf("\nEnter no of elements in the array\n");

    scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
m = insertionsort(a,n);

 printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", m[t]);


}
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;}
}
case(7):{

     system("cls");
     printf("\nEnter no of elements in the array\n");

     scanf("%d", &n);

    printf("Enter the array\n");

    for (i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }
 first =0;
 last = n-1;
 mergeSort( a , first , last);
 printf("Array after sorting is\n");

    for (t = 0; t < n; t++) {

        printf("%d,", a[t]);


}
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
break ;
}
}

case (8):{
system("cls");
    clock_t t;
    double cpu_time_used;
    int f;

    for(f=100 ; f<=10000; f=f+100)
    {

        int low=0;
        int high=f-1;
        srand((unsigned)time(NULL));
        m = fillArray(a,f);
        t=clock();
        Heapsort(m,f);
        t=(clock())-t;
        cpu_time_used=((double)t)/CLOCKS_PER_SEC  ;
        printf("Heap sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        m = fillArray(a,f);
        t=clock();
        bubblesort(m,f);
        t=((clock())-t);
        cpu_time_used=((double)t)/CLOCKS_PER_SEC  ;
        printf("Bubble sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        m = fillArray(a,f);
        t=clock();
        selectionsort(m,f);
        t=((clock())-t);
        cpu_time_used=(((double)t)/CLOCKS_PER_SEC)  ;
        printf("Selection sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        m = fillArray(a,f);
        t=clock();
        insertionsort(m,f);
        t=((clock())-t);
        cpu_time_used=(((double)t)/CLOCKS_PER_SEC)  ;
        printf("Insertion sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        m = fillArray(a,f);
        t=clock();
        quicksort(m,low,high);
        t=((clock())-t);
        cpu_time_used=(((double)t)/CLOCKS_PER_SEC)  ;
        printf("Quick sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        m = fillArray(a,f);
        t=clock();
        mergeSort(m,low,high);
        t=((clock())-t);
        cpu_time_used=(((double)t)/CLOCKS_PER_SEC)  ;
        printf("Merge sort runtime: %f , size of array is: %d",cpu_time_used,f);
        printf("\n");
        printf("\n");
         }
printf("\n");
printf("press 0 to repeat ");
scanf("%d",&back);
if(back == 0){
        system("cls");
break ;
}
}

case(9):{

break ;
}
case(10):{
exit(0);
break;
}


}}}
