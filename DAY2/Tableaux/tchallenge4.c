#include <stdio.h>

int main() {
    int NumberDeElement, max;

    printf("Enter number of Items: \n");
    scanf("%d", &NumberDeElement);

    int tab[NumberDeElement];

    for (int i = 0; i < NumberDeElement; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &tab[i]);
    }

    // search for max
    max = tab[0]; // First number as max initially

    for (int i = 1; i < NumberDeElement; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    printf("le maximan est %d\n", max);

    return 0;
}
