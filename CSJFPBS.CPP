#include<iostream.h>
#include<conio.h>
double sjftat,sjfwt,pbstat,pbswt;

void sjf()
{
int p[4],at[4],bt[4],ft[4],tat[4],wt[4],stat=0,swt=0;
int i,j,k,temp1,temp2,temp3,loc,min,sum=0;
for(i=0;i<=3;i++)
{
  cout<<"enter the process number  : ";
  cin>>p[i];
  cout<<"enter arrival time for p"<<p[i]<<" : ";
  cin>>at[i];
  cout<<"enter burst time for p"<<p[i]<<"   : ";
  cin>>bt[i];
}

for(j=1;j<=2;j++)
{
  min=bt[j];
  for(k=j+1;k<=3;k++)
   {
     if(bt[k]<min)
      {
	min=bt[k];
	loc=k;
      }
   }

temp1=bt[loc];
bt[loc]=bt[j];
bt[j]=temp1;

temp2=at[loc];
at[loc]=at[j];
at[j]=temp2;

temp3=p[loc];
p[loc]=p[j];
p[j]=temp3;

}

for(i=0;i<=3;i++)
{
 sum=sum+bt[i];
 ft[i] =sum;
 tat[i]=ft[i]-at[i];
 wt[i]=tat[i] -bt[i];
}

clrscr();
cout<<"\n******************************************";
cout<<"\nprocess\tatime\tbtime\tftime\ttat\twt";
for(i=0;i<=3;i++)
{
cout<<endl<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ft[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
}

for(i=0;i<=3;i++)
{
stat=stat+tat[i] ;
swt=swt+wt[i];
}

cout<<"\n******************************************";
cout<<"\naverage turnaroundtime "<<(double)stat/4;
cout<<"\naverage waiting time "<<(double)swt/4;
sjftat=(double)stat/4;
sjfwt=(double)swt/4;
}

void priority()
{
int p[4],at[4],bt[4],ft[4],pr[4],tat[4],wt[4],stat=0,swt=0;
int i,j,k,temp1,temp2,temp3,temp4,loc,min,sum=0,flag=0;

for(i=0;i<=3;i++)
{
  cout<<"enter the process number  : ";
  cin>>p[i];
  cout<<"enter arrival time for p"<<p[i]<<" : ";
  cin>>at[i];
  cout<<"enter burst time for p"<<p[i]<<"   : ";
  cin>>bt[i];
  cout<<"enter priority for p"<<p[i]<<"     : ";
  cin>>pr[i];
}

for(j=1;j<=2;j++)
{
  flag=0;
  min=pr[j];
  for(k=j+1;k<=3;k++)
   {
     if(pr[k]<min)
      {
	flag=1;
	min=pr[k];
	loc=k;
      }
   }
if(flag==1)
{
temp1=bt[loc];
bt[loc]=bt[j];
bt[j]=temp1;

temp2=at[loc];
at[loc]=at[j];
at[j]=temp2;

temp3=p[loc];
p[loc]=p[j];
p[j]=temp3;

temp4=pr[loc];
pr[loc]=pr[j];
pr[j]=temp4;
}
}

for(i=0;i<=3;i++)
{
 sum=sum+bt[i];
 ft[i] =sum;
 tat[i]=ft[i]-at[i];
 wt[i]=tat[i] -bt[i];
}

clrscr();
cout<<"\n******************************************";
cout<<"\nprocess\tatime\tbtime\tpr\tftime\ttat\twt";
for(i=0;i<=3;i++)
{
cout<<endl<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<pr[i]<<"\t"<<ft[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
}

for(i=0;i<=3;i++)
{
stat=stat+tat[i] ;
swt=swt+wt[i];
}

cout<<"\n******************************************";
cout<<"\naverage turnaroundtime "<<(double)stat/4;
cout<<"\naverage waiting time "<<(double)swt/4;

pbstat=(double)stat/4;
pbswt=(double)swt/4;
}

void main()
{
clrscr();
sjf();
priority();
if(sjftat<pbstat &&sjfwt<pbswt)
{
cout<<endl<<"sjf scheduling is the best";
}
else
{
cout<<endl<<"priority based scheduling is the best";
}

getch();
}
