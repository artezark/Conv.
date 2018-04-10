#include <stdio.h> 
#include <stdlib.h> 

float C_F (float x){
	return x*1.8+32;
}
float F_C (float x){
	return (x-32)*5.0/9.0;
}
float C_K (float x){
	return x+273.15;
}
float K_C (float x){
	return x-273.15;
}

int main(int argc, char *argv[]){
	float c;
	if (argc!=1)
		c = atof(argv[1]);
	else {
		printf("Error!");
		return 1;
	}
	if (argc==3)
		switch (*argv[2]){
			case 'C':
			case 'c':
				if (C_K(c) < 0)
					printf("Temperature < absolute zero for Celsius!\n");
				else
					printf("%.2lf F\n%.2f K", C_F(c), C_K(c));
				break;
			case 'F':
			case 'f':
				if (C_K(F_C(c)) < 0)	
					printf("Temperature < absolute zero for Fahrenheit!\n");
				else	
					printf("%.2f C\n%.2f K", F_C(c), C_K(F_C(c)));
				break;
			case 'K':
			case 'k':
				if (c < 0)
					printf("Temperature < absolute zero for Kelvin!\n");
				else
					printf("%.2f C\n%.2f F", K_C(c), C_F(K_C(c)));
				break;
		}
	else {
		printf ("%.2f C:\n", c);
		if (C_K(c) < 0)
			printf("Temperature < absolute zero for Celsius!\n");
		else
			printf("%.2f F\n%.2f K\n", C_F(c), C_K(c));
		printf ("%.2f F:\n", c);
		if (C_K(F_C(c)) < 0)	
			printf("Temperature < absolute zero for Fahrenheit!\n");
		else
			printf("%.2f C\n%.2f K\n", F_C(c), C_K(F_C(c)));
		printf ("%.2f K:\n", c);
		if (c < 0)
			printf("Temperature < absolute zero for Kelvin!\n");
		else
			printf("%.2f C\n%.2f F\n", K_C(c), C_F(K_C(c)));
		}

return 0;
}
