/*Esse programa calcula a soma, média e desvio padrão(nessa ordem) dos numeros inteiros positivos presentes em cada linha de um arquivo chamado dados1.csv, sendo que cada numero está separado
vírgula, a quantidade de numeros por linha não é fixa e sabe-se que o arquivo possui 10 linhas. Após isso, esse programa cria um arquivo chamado resultados.csv e coloca todos os resultados nele
separados por vírgulas e em ordem de cálculo.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int somar(int n, int numeros[]){
/*função para calcular a soma*/
    int i;
    float soma=0;
    for(i=0;i<n;i++){
        soma=soma+numeros[i];
    }
    return soma;
}
float mediar(int soma,int n){
/*função para calcular a média*/
    float media;
    media=(float)soma/(float)n;
    return media;
}
float power(float y,int n){
/*função para realizar potencias*/
    int i;
	float x=1;
    for(i=0;i<n;i++){
        x=x*y;
    }
    return x;
}
float desviar(int n,int numeros[], float media){
/*função para calcular o desvio padrão */
    int i;
    float desvio=0;
    float p;
    for(i=0;i<n;i++){
    	p=numeros[i]-media;
        desvio=desvio+power(p,2);
    }
    p=desvio/n;
    desvio=sqrt(p);
    return desvio;
}

void salvar(int soma,float media, float desvio){
/*função para criar o arquivo com os resultados de cada linha*/
    FILE* arquivo;

    arquivo=fopen("resultados.csv","a");
    fprintf(arquivo,"%d,%f,%f\n",soma,media,desvio);
    fclose(arquivo);
}
int main(){
    float media=0,desvio=0;
    int soma,numero[100][20],i=-1,j,linha=0,nElementos[100],tamanho=0,nProvisorio[100],step;
    FILE* arquivo;
    char entrada[300];

    for(i=0;i<10;i++){
    	for(j=0;j<10;j++){
    		numero[i][j]=0;
		}
	}
	for(i=0;i<10;i++){
		nElementos[i]=0;
	}
	i=0;
    arquivo=fopen("dados1.csv","r");
    if(arquivo==NULL){
    	perror("Houve um erro na leitura do arquivo\"dados1.csv\"!");
    	system("pause");
    	return 0;
	}
    do{
    	i++;
		entrada[i]=fgetc(arquivo); /**/
		if(entrada[i]==','||entrada[i]=='\n'||entrada[i]==EOF){
			for(j=1;j<=tamanho;j++){
				/*para cada caracter lido de um numero, transforma-se ele em um número significativo, isto é, com o valor devido da sua casa decimal
				(se era a dezena, é multiplicado por 10, centena, por 100, etc), soma-se com os restantes do mesmo numero e armazena o resultado final em uma matriz*/
				step=nElementos[linha];/*step representa qual a posição do numero na linha*/
				numero[linha][step]=numero[linha][step] + nProvisorio[j-1]*power(10,tamanho-j);
			}
			tamanho = 0; /*após a leitura de um numero todo, reinicia a contagem de digitos*/
			nElementos[linha]++;
			if(entrada[i]=='\n'){
                linha++;
			}
		}
		else{
			/*converte o caracter lido um digito int*/
            nProvisorio[tamanho]=atoi(&entrada[i]);
            tamanho++;
            }
    }while(entrada[i]!=EOF);
    fclose(arquivo);
    for(i=0;i<10;i++){
    	/*chama cada uma das funções e realiza o calculo com os valores*/
   		soma = somar(nElementos[i],numero[i]);
    	media=mediar(soma,nElementos[i]);
    	desvio=desviar(nElementos[i],numero[i],media);
    	printf("linha[%d]: Soma = %d Media = %f Desvio padrao = %f\n",i,soma,media,desvio);
    	salvar(soma,media,desvio);
    	printf("Um arquivo com os resultados foi criado na pasta desse programa!\n");
	}
	system("pause");
    return 0;
}
