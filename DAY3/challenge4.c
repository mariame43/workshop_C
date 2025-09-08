#include <stdio.h>
 void mini(){
     int x ,y,max;
     printf ("entrer la valeur de x :");
     scanf ("%d",&x);
      printf ("entrer la valeur de y :");
     scanf ("%d",&y);
  max= x ;
  if(max >y)
     printf ("le miniman est   :%d",y);
      else 
       printf ("le miniman est   :%d",x);
 }

int main() {
 mini();

    return 0;
}