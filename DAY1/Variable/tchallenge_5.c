#include <stdio.h>


int main() {

      float C;

    printf("la température en Celsius");
    scanf ("%f",&C);
if (C < 0 )
{
     printf("solide");
} else if (0 <= C && C < 100){
    printf("liquide");

}else{

 printf("gaz");

}

    return 0;

}