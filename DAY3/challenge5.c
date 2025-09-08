#include <stdio.h>
void fact(){
    int x , factorial = 1 ;
    
    printf("entre x :");
     scanf ("%d",&x);
     
        for ( int i=1 ; i<= x ; i++){
            factorial = factorial * i ;
        }
printf("la factoriel de cette nombre x est : %d\n",factorial);
}
int main() {
   fact();

    return 0;
}
