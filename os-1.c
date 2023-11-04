#include<stdio.h>
void processMethod(int a[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(a[i%2!=0])
		a[i]=a[i]+1;
	}
}
int main()
{
int a[]={10,13,24,16,18};
int N=sizeof(a)/sizeof(int);
int i;
processMethod(a,N);
for(i=0;i<=N;i++)
{
	printf("%d\n",a[i]);
}
return 0;
}

