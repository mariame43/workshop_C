#include <stdio.h>

// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int NumberDeElement,S;
    
    printf("Enter number of Items: \n");
    scanf("%d",&NumberDeElement);
    
    int tab[NumberDeElement];
    for (int i = 0; i < NumberDeElement; i++)
    {
           printf("Enter number %d: ",i+1);
            scanf("%d",&tab[i]);
    }
  S = 0 ;
for (int i = 0; i < NumberDeElement; i++)  {
    S = S + tab[i];
}
           printf("La somme est %d  ",S);
          
    
 
    return 0;
}
