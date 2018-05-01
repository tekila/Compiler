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
void main(void){
  int n;
  int saidamul;
  int contador;
  int array[5];
  array[4] = 5;
  contador = 0;
  n = 5;
  saidamul = fatorial(contador);
  n = n+1;
  n = saidamul + contador;
  contador = n+2;
}