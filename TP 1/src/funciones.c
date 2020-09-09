#include <stdio.h>
#include <stdlib.h>

int getNum(void){

	int num;
	scanf("%d", &num);
	printf("Se ingresó el numero: %d \n",num);
	return num;
}

int sumar(int num1, int num2){

	int resultado = num1 + num2;
	return resultado;
}

int restar(int num1, int num2){

	int resultado = num1 - num2;
	return resultado;
}

int multiplicar(int num1, int num2){

	int resultado = num1 * num2;
	return resultado;
}

float dividir(int num1, int num2){

	float resultado = 0;

	if(num2 !=0){

	 resultado = (float)num1 / num2;
	}

	return resultado;
}

int factorial(int num){

	int resultado = 0;

	int factorial = 1;

	if (num == 0){

		resultado = 1;

	}

	else {
	        for (int i = 1; i <= num; i++) {
	            factorial = factorial * i;
	        }

	        resultado = factorial;
	    }

	return resultado;

}



