#define maxb 1000000
long int prime[maxb+1],maxfact[maxb+1];

for(i=0;i<=maxb;i++)
     maxfact[i]=i;
 i=2;
 while(i*i<=maxb)
     {if (maxfact[i]==i)
         {j=i*2;
          while(j<=maxb)
              { while(maxfact[j]%i==0)
                     maxfact[j]=maxfact[j]/i;
                if(maxfact[j]<i)
                   maxfact[j]=i;
                j=j+i;
               }
          }
      i=i+1;
     }
 total=-1;
 for (i=1;i<=b;i++)
         if(maxfact[i]==i)
            {total=total+1;
             prime[total]=i;
            }
