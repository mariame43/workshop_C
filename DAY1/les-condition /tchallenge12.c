
#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2; 
    printf("Entrez  instant num1 : ");
    scanf("%d:%d:%d", &h1, &m1, &s1);

    printf("Entrez instant num2 : ");
    scanf("%d:%d:%d", &h2, &m2, &s2);

    if (h1 == h2 && m1 == m2 && s1 == s2) {
        printf("Il s'agit du même instant.\n");
    } else if (h1 < h2 || (h1 == h2 && m1 < m2) || (h1 == h2 && m1 == m2 && s1 < s2)) {
        printf("Le premier instant vient avant le deuxième.\n");
    } else {
        printf("Le deuxième instant vient avant le premier.\n");
    }

    return 0;
}

