#include <stdio.h>



int main() {
  int m, x, i;
  printf ("entrer une numero :");
  scanf ("%d",&x);
  
    for ( i = 0; i <= 10; i++){
      m = x * i ;
    
printf ("%d = %d * %d\n",m,x,i);
 }


    return 0;
}