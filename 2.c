#include<stdio.h>
#include<math.h>

float somar(float n, float numeros[]){
    int i;
    float soma=0;
    for(i=0;i<n;i++){
        soma=soma+numeros[i];
    }
    return soma;
}
float mediar(float soma,int n){
    float media;
    media=soma/n;
    return media;
}

float desviar(int n,float numeros[], float media){
    int i;
    float desvio=0;
    for(i=0;i<n;i++){
        desvio=desvio+pow(numeros[i]-media,2);
    }
    desvio=sqrt(desvio/n);
    return desvio;
}

int main(){
    float a[10000],soma,media=0,desvio=0;
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%f",&a[i]);
    }
    soma= somar(n,a);
    media=mediar(soma,n);
    desvio=desviar(n,a,media);
    printf("Soma = %f\nMedia = %f\nDesvio padrao = %f",soma,media,desvio);
    return 0;
}

