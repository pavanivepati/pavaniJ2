#include<stdio.h>
#include<conio.h>
#define size 10
int largest(int arr[],int n);
void radix_sort(int arr[],int n);
void main()
{
	int arr[size],i,n;
	pritnf("enter no of elements");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,n);
	printf("\n after sorting array is");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int largest(int arr[],int n)
{
	int large=arr[0],i;
	for(i=0;i<n;i++)
	{
	if(arr[i]>large)
	  large=arr[i];
    }
    return large;
}
void radix_sort(int arr[],int n)
{
	int bucket[size][size],bucket_count[size];
	int i,j,k,remainder,NOP=0,divisor=1,large,pass;
	large=largest(arr,n);
	while(large>0)
	{
		NOP++;
		large/=size;
	}
	for(pass=0;pass<NOP;pass++)
	{
		for(i=0;i<size;i++)
		{
		  bucket_count[i]=0;
	      for(i=0;i<n;i++)
		  {
			remainder=(arr[i]/divisor)%size;
			bucket[remainder][bucket_count[remainder]]=arr[i];
			bucket_count[remainder]+=1;
		  }
		  i=0;
		  for(k=0;k<size;k++)
		  {
			for(j=0;j<bucket_count[k];j++)
			{
				arr[i]=bucket[k][j];
				i++;
			}
		  }
		  divisor*=size;
	    }
	}
}
