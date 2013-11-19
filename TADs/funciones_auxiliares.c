
int numero_registros(char *archivo, int tam)
{
	FILE *ptr;
	int nbytes, nreg;

	ptr = fopen(archivo, "r");
	if(ptr == NULL) return 0; 
	fseek(ptr, 0, SEEK_END);
	nbytes = ftell(ptr);
	fclose(ptr);
	nreg = nbytes/tamReg;
	return nreg;
}