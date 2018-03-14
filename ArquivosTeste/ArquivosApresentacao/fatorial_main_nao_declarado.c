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

