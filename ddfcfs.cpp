#include<iostream.h>
#include<conio.h>
#include<math.h>
int cr[20],iph,i,sum;
void main()
{
	clrscr();
	cout<<"\nEnter the initial position of head : ";
	cin>>iph;
	for(i=0;i<=7;i++)
	{
		cout<<"Enter the cylinder request : ";
		cin>>cr[i];
	}
	for(i=0;i<=6;i++)
	{
		sum=sum+abs(cr[i]-cr[i+1]);
	}
	sum=sum+abs(iph-cr[0]);
	cout<<"\nTotal no of head movement : "<<sum;
	getch();
}