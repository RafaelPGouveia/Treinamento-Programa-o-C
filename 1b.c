#include<stdio.h>
#include<math.h>


int main(){
    float a[10000],media=0,desvio=0;
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%f",&a[i]);
      media = media+a[i];
    }
    media=media/n;
    for(i=0;i<n;i++){
        desvio=desvio+pow(a[i]-media,2);
    }
    desvio=sqrt(desvio/n);
    printf("Soma = %f\nMedia = %f\nDesvio padrao = %f",media*n,media,desvio);
    return 0;
}
