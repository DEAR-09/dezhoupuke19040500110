#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int f1(int *a)//顺子 
{
    int i,j,level;
    int v;
    for(i = 0; i <4; i ++)
        for(j = i+1; j < 5; j ++)
        {
            if(a[2*i]>a[2*j])
            {
                v=a[2*i];
                a[2*i]=a[2*j];
                a[2*j]=v;
            }
        }
    for(i = 0; i <4; i=i+2)
    {if((a[i]-a[i+2])!=-1)
     {level=4;break;
	 }
	 else level=7;
	}
     return level;
}
int f2(int *a)//三条 对子 双对 散牌 
{
    int i,j,level=0,s=1,k,n=0;
    int v;
    for(i = 0; i < 4; i ++)
        for(j = i+1; j < 5; j ++)
        {
            if(a[2*i]>a[2*j])
            {
                v=a[2*i];
                a[2*i]=a[2*j];
                a[2*j]=v;
            }
        }
    for(i = 0; i < 4; i=i+2)
    {if(a[i]==a[i+2])
     {s++;
	  if(k<=s){k=s;
	  }
	 }
	 else {
	 s=1;
	 if(k==2)n=1;
	 }
	}
	if(k>2)level=4;
	else if((k==2)&&(n==1))
	level=3;
	else if((k==2)&&(n==0))
	level=2;
	else level=1;
    return level;
}
int f3(int *a)//同花 
{	int i,flag[4],level;
	for(i=1;i<6;i++)
	{if(a[2*i]==100)flag[0]++;
	else if(a[2*i]==200)flag[1]++;
	else if(a[2*i]==300)flag[2]++;
	else if(a[2*i]==400)flag[3]++;
	}
	for(i=0;i<4;i++)
	{if(flag[i]==5)
	 {level=7;return level;
	 break;
	 }
	 else if(flag[3]!=5)
	 {level=5;return level;
	 break;
	 }
	}
}
int f4(int *a)//牌面 
{
    int i,j;
    int v;
    for(i = 0; i <4; i ++)
        for(j = i+1; j < 5; j ++)
        {
            if(a[2*i]>a[2*j])
            {
                v=a[2*i];
                a[2*i]=a[2*j];
                a[2*j]=v;
            }
        }
     return a[8];
}
int f(char a)
{	int i,q=0;
		{if(a!=' ')
		{
		  if(a=='1')
		  q=1;
		  else if(a=='2')
		  q=2;
		  else if(a=='3')
		  q=3;
		  else if(a=='4')
		  q=4;
		  else if(a=='5')
		  q=5;
		  else if(a=='6')
		  q=6;
		  else if(a=='7')
		  q=7;
		  else if(a=='8')
		  q=8;
		  else if(a=='9')
		  q=9;
		  else if(a=='T')
		  q=10;
		  else if(a=='J')
		  q=11;
		  else if(a=='Q')
		  q=12;
		  else if(a=='K')
		  q=13;
		  else if(a=='A')
		  q=14;
		  else if(a=='D')
		  q=100;
		  else if(a=='S')
		  q=200;
		  else if(a=='H')
		  q=300;
		  else if(a=='C')
		  q=400;
		}
		}
	return q;
}
int main(void)
{
	char a[20],b[20];
	int q[20],w[20],i=0,j=0,z1,z2,x1,x2,c1,c2,v1,v2;
	printf("Black:");
	gets(a);
	printf("White:");
	gets(b);
	while(i<10)
	{if(f(a[j])!=0)
	 {q[i]=f(a[j]);
	  i++;
	 }
	 j++;
	}
	j=0;i=0;
	while(i<10)
	{if(f(b[j])!=0)
	 {w[i]=f(b[j]);
	  i++;
	 }
	 j++;
	}
	z1=f3(q);x1=f1(q);c1=f2(q);
	if(z1==7)
	{if(x1==7)z1=7;
	 if(x1==4)z1=6;
	}
	if(z1==5)
	{if(x1==4){
	if(c1==1)z1=1;
	else if(c1==2)z1=2;
	else if(c1==3)z1=3;
	else if(c1==4)z1=4;
			  }
	else if(x1==7)z1=5;
	}
	
	z2=f3(w);x2=f1(w);c2=f2(w);
	if(z2==7)
	{if(x2==7)z2=7;
	 if(x2==4)z2=6;
	}
	if(z2==5)
	{if(x2==4){
	if(c2==1)z2=1;
	else if(c2==2)z2=2;
	else if(c2==3)z2=3;
	else if(c2==4)z2=4;
			  }
	else if(x2==7)z2=5;
	}
	v2=f4(q);
	v2=f4(w);
	//开始比较 
	
}
