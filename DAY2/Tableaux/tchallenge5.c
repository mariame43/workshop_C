
#include <stdio.h>

int main() {


    int num , mini ;
    printf("entre numero : ");
    scanf("%d",&num);
    
int elle[num];
    for (int i = 0; i < num; i++) {
        printf("Enter numero %d: ", i + 1);
        scanf("%d", &elle[i]);
    }

    mini = elle[0];

    for (int i = 1; i < num; i++) {
        if (elle[i] < mini) {
            mini = elle[i];
        }
    }

    printf("le miniman est %d\n", mini);

    return 0;
}



