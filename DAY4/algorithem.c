// challenge 1 : Tri a bulles
#include <stdio.h>

void affichage (int nombre[],int taille ){
    for (int i = 0; i < taille; i++)
    {
        printf("%d",nombre[i]);
    }
      printf("\n");
      }

void change (int *a, int *b) {
 int   num = *a;
        *a =  *b;
       *b = num;
}



void tripe(int nombre[],int taille){
int i , j ;
for ( i = 0; i < taille - 1 ; i++)
{
    for ( j = 0; i < taille - i - 1 ; j++)
    {
        if (nombre[j]>nombre[j+1])
        {
           change(&nombre[j], &nombre[j + 1]);
        }
        
    }
    
}


}

int main() {
    int taille ;
 printf("entrer les numbre element :");
    scanf("%d",&taille);
  int  nombre[taille];
    for (int i = 0; i < taille; i++)
    {
        
         scanf("%d", &nombre[i]);
    }
    
   

printf("afficher les numbre ecrite :\n");
affichage (nombre,taille );
tripe(nombre,taille);
printf("afficher croissan de numbre :\n");
affichage (nombre,taille );



    return 0;
}