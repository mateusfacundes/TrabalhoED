#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int valor;
	int qtd;
	struct no *prox;
	struct no *prev;
} nos;

int ehfila();
int ehfilaprio();
int ehpilha();
void criarestrutura();

int main()
{
	int valor ;
	int operacao;
	int qtd;
	int i;
	int controle = 0;

	nos *headadc;
	headadc = (nos *)malloc(sizeof(nos));
	headadc->qtd = 0;

	nos *headrem;
	headrem = (nos *)malloc(sizeof(nos));
	headrem->qtd = 0;

	printf("quantas operaçoes?");
	scanf("%d", &qtd);

	for(i = 0; i < qtd; i++)
	{
		printf("digite o valor:\n");
		scanf("%d", &valor);
		printf("digite a operacao:\n");
		scanf("%d", &operacao);
		if(operacao == 1)
		{
			criarestrutura(valor, headadc);
		}
		if(operacao == 2)
		{
			criarestrutura(valor, headrem);
		}
	}

	nos *teste;
	teste = headadc;

	while(teste->prox != NULL)
	{
		printf("valores adc: %d\n", teste->valor);
		teste = teste->prox;
	}
	printf("valores adc: %d\n", teste->valor);

	while(teste->prev != NULL)
	{
		printf("valores adc ao contrario: %d\n", teste->valor);
		teste = teste->prev;
	}
	printf("valores adc ao contrario: %d\n", teste->valor);

	teste = headrem;
	while(teste->prox != NULL)
	{
		printf("valores rem: %d\n", teste->valor);
		teste = teste->prox;
	}
	printf("valores rem: %d\n", teste->valor);

	printf("head: %d\n", headadc->valor);
	printf("head: %d\n", headrem->valor);

	controle = ehfila(headadc, headrem);
	controle = controle + ehpilha(headadc);
	controle = controle + ehfilaprio(headadc, headrem);


	printf("%d", controle);

	free(headrem);
	free(headadc);
	return 0;
}

void criarestrutura(int valor, nos * head, nos *tail)
{
	nos *novo;
	novo = NULL;
	novo = (nos *)malloc(sizeof(nos));

	novo->valor = valor;
	novo->prox = NULL;

	if(head->qtd == 0)
	{
		head->valor = valor;
		head->prox = NULL;
		head->prev = NULL;
		head->qtd++;
		tail = head;
	}
	else
	{
		nos * teste;
		teste = NULL;
		teste = head;

		while(teste->prox != NULL)
		{
			teste = teste->prox;
		}
		tail = novo;
		teste->prox = novo;
		novo->prev = teste;
	}
}

int ehfila(nos *adc, nos *rem)
{
	int ret;
	nos *testeadc;
	nos *testerem;

	testeadc = adc;
	testerem = rem;

	if(testeadc->prox == NULL || testerem->prox == NULL )
	{
		if(testeadc->valor != testerem->valor)
		{
			return 0;
		}
		else
		{
			ret = 1;
		}
	}
	else
	{
		while(testeadc->prox != NULL || testerem->prox != NULL)
		{
			if(testeadc->valor != testerem->valor)
			{
				return 0;
			}
			else
			{
				ret = 1;
			}
			testeadc = testeadc->prox;
			testerem = testerem->prox;
		}
		if(testeadc->valor != testerem->valor)
		{
			return 0;
		}else
		{
 			ret = 1;
		}
	}
	return ret;
}

int ehpilha(nos *headadc, nos *headrem)
{
	int ret;
	nos *tail;
	nos *teste;
	teste = headadc;
	tail = headrem;

	while(tail->prox != NULL)
	{
		tail = tail->prox;
	}

	if(teste->prox == NULL)
	{
		if(teste->valor != tail->valor)
		{
			return 0;
		}
		else
		{
			ret = 3;
		}
	}
	else
	{
		while(teste->prox != NULL)
		{
			if(teste->valor != tail->valor)
			{
				return 0;
			}
			else
			{
				ret = 3;
			}
			teste = teste->prox;
			tail = tail->prev;
		}
	}
	return ret;
}

int ehfilaprio(nos *headadc, nos *headrem)
{
	int ret;
	nos *teste;
	teste = headrem;

	if(teste->prox == NULL)
	{
		if(teste->valor == headadc->valor)
		{
			ret = 5;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		while(teste->prox != NULL)
		{
			if(teste->valor > teste->prox->valor)
			{
				ret = 5;
			}
			else
			{
				return 0;
			}
			teste = teste->prox;
		}
	}
	return ret;
}














