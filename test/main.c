#include <stdio.h>
#include <stdlib.h>

int fact(int N) {
    int i ;
    int factorielle = 1;
    for(int i=1; i<=N ; i++){
        factorielle = factorielle * i ;
    }
    return factorielle ;
}

float power (float x, int p) {

    float res = x ;
    int compteur = 0 ;

    while (compteur<=p) {
        res = res*x;
        compteur =compteur +1 ;

    }

    return res ;
}

int main()
{

    printf("Hello!\n");
    int a = fact(3) ;
    printf("%d\n",a);
    float puis = power(1.2, 4) ;
    printf("%f\n",puis);
    return 0;

}
