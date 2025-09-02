#include <stdio.h>

int main() {
    int x, y, somme;

    printf("Entrer deux numéros: ");
    scanf("%d %d", &x, &y);

    somme = x + y;

    if (x == y) {
        somme *= 3;
    }

    printf("Le résultat est: %d \n", somme);

    return 0;
}
