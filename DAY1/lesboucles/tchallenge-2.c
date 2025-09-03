
#include <stdio.h>

int main() {
    int S = 0, x, i;

    printf("Entrer un numéro : ");
    scanf("%d", &x);

    for (i = 1; i <= x; i++) {
        S = S + i;
    }

    printf("La somme des nombres  %d est : %d\n", x, S);

    return 0;
}


    

