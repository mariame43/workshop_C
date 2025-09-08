#include <stdio.h>
 void maxim(){
     int x ,y,max;
     printf ("entrer la valeur de x :");
     scanf ("%d",&x);
      printf ("entrer la valeur de y :");
     scanf ("%d",&y);
  max= x ;
  if(max <y)
     printf ("le maximan est   :%d",y);
      else 
       printf ("le maximan est   :%d",x);
 }

int main() {
 maxim();

    return 0;
}