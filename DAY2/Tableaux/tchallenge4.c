#include <stdio.h>

int main() {


int NumberDeElement,max;
    
    printf("Enter number of Items: \n");
    scanf("%d",&NumberDeElement);
    
    int tab[NumberDeElement];
    for (int i = 0; i < NumberDeElement; i++)
    {
           printf("Enter number %d: ",i+1);
            scanf("%d",&tab[i]);
    }
    
    // search for max
    max = tab[0]; // WE PUT FIRST NUMBER AS MAX AFTER THAN WE COMPARE IT WITH OTHER NUMBERS
    
    for (int i = 1; i < NumberDeElement; i++)
    {
        if (tab[i]>max)
        {
            max= tab[i];
        }
        
    }
    

    printf("le maximan est %d",max);
 
 
    return 0;
}
