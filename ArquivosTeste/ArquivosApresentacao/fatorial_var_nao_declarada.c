int fatorial(int contador, int n){
	resultado;
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
  int resultado;
  int contador;
  contador = 0;
  n = 5;
  saidamul = fatorial(contador);
}