#include<stdio.h>
FILE *in,*out;
int n,a[100001]={0},b[100001]={0},len=1;

void work(int i)
{int mid,l=1,r=len;
 while(l<=r)
   {mid=(l+r)/2;
    if(b[mid]==a[i])
      return;
    else if(b[mid]>a[i])
      l=mid+1;
    else r=mid-1;
   }
 if(l>len)
   {len++;
    b[len]=a[i];
   }
 else b[l]=a[i];
// printf("%d************/n",i);getch();
}

main()
{in=fopen("xulie.in","r");
 fscanf(in,"%d",&n);
 int i;
 for(i=1;i<=n;i++)
    fscanf(in,"%d",&a[i]);
 fclose(in);
 b[1]=a[1];
 for(i=2;i<=n;i++)
   if(a[i]!=0)
    work(i);
 out=fopen("xulie.out","w");
 if(n!=0)
 fprintf(out,"%d\n",len);
 else
 fprintf(out,"%d\n",0);
 fclose(out);
}
