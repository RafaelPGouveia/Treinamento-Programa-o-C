#include<stdio.h>
#include<math.h>
#define N 3

int main(){
    float a[N],media=0,desvio=0;
    int i;

    for(i=0;i<N;i++){
      scanf("%f",&a[i]);
      media = media+a[i];
    }
    media=media/N;
    for(i=0;i<N;i++){
        desvio=desvio+pow(a[i]-media,2);
    }
    desvio=sqrt(desvio/N);
    printf("Soma = %f\nMedia = %f\nDesvio padrao = %f",media*N,media,desvio);
    return 0;
}
