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

void foo(void)
{

}

void main(void){
  int n;
  int a;
  int foo;
  int resultado;
  int saidamul;
  int contador;
  contador = 0;
  n = 5;
  saidamul = fatorial(contador);
}