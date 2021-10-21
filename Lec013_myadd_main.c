#include <stdio.h>
int myadd(int, int);
int main()
{
     int v1, v2;
     printf("Value 1: ");
     scanf("%d",&v1);
     printf("Value 2: ");
     scanf("%d",&v2);

     // Cal function that returns sum as integer
     int ans = myadd(v1, v2);
     printf ("Answer: %d\n", ans);

     return 0;
}
