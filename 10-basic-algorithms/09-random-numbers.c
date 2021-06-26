#include<time.h>
#include<stdlib.h>
main()
{goto l1;
 printf("%d",5);
 l1:
 srand((int)time(NULL));
 printf("%d",rand()%100);
}
