int fatorial(int contador, int n){
	int resultado;
	contador = contador + 1;
	if (contador < n){
		resultado = fatorial(contador);
		contador = contador*resultado;
		return contador;
	}else{
		return contador;
	}
	
}

void funcaoNaoRetornaNada(void)
{
	int a;
	a = 3;
}

void main(void){
  int n;
  int saidamul;
  int contador;
  saidamul = funcaoNaoRetornaNada();
  contador = 0;
  n = 5;
  saidamul = fatorial(contador, n);
}