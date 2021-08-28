#include<stdio.h>
void mergesort(int [],int ,int );
void combine(int [],int ,int ,int );
int main()
{
    int a[20],i,low,high,n;
    printf("enter no of elements");
    scanf("%d",&n);
    low=0;
    high=n-1;
    printf("enter array elements");
    for(i=0;i<n;i++)
    {
	   scanf("%d",&a[i]);
    }
    printf("\n after sorting ");
    mergesort(a,low,high);
    printf("\n after sorting ");
    for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	return 0;
}
void mergesort(int a[20],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
		mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        combine(a,mid,low,high);
    }
}
void combine(int a[20],int mid,int low,int high)
{
    int temp[20],k,i,j,n;
    k=low;
    i=low;
    j=mid+1;
    while(i<mid&&j<=high)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    for(k=0;k<n;k++)
    {
        a[k]=temp[k];
    }
}
2
  #include <stdio.h>

#define max 10

int a[11]={10,24,2,45,01,34,56};
int b[10];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}
