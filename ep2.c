#include <stdio.h>
#include <string.h> 
#include <float.h>
#include <stdlib.h>
//funcao de leitura de arquivo
void read_file(char arquivo[], int * k_max); 
//calculo de TF lenta
int main (){

	//interpreta arquivo
	char arquivo[200];
	printf("Arquivo a ser lido: \n");
	gets(arquivo);
	int k;
	read_file(arquivo, &k);	
	printf("%d\n", k);
	return 0;
}

void read_file(char arquivo[], int * k_max){
	FILE *arq;
	arq = fopen(arquivo,"r"); //abrindo arquivo em modo de leitura;
//	char c;
	int num = 0;
	char * value;	
	char * line;
	size_t len = 0;
	int j = 0;
//	while ((c=fgetc(arq))!= EOF)
	while ((getline(&line, &len, arq)) != -1)
	{
		if (num > 1){
			for (int i = 0; i < len; i++)
			{
				if (i > 15){
					value[j] = line[i];
				}
			}
			printf("%s", value);
			j = 0;
		}
		num++;
	}
	*k_max = num-2;
	fclose(arq);
}

