#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"functions.h"
/*int main() {
	double res;
	while(1) {
		 functions();
	}
	return 0;
}*/
void functions() {
	int func, a, b;
	double res, x;

		printf("1. Sine\n2.Cosine\n3.Tangent\n4.Sin Inverse\n5. cos Inverse\n6. tan Inverse\n7. Power\n8. Factorial\n9. Log\n10.\
e ^ x\n11. Complex Functions\n12. Converter\n13. nCr\n14. Exit\n");
		scanf("%d", &func);
		switch(func) {
			case 1:
				scanf("%lf", &x);
				res = sine(x);
				printf("->%lf\n", res);
				break;
			case 2:
				scanf("%lf", &x);
				res = cosine(x);
				printf("->%lf\n", res);
				break;
			case 3:
				scanf("%lf", &x);
				res = tan(x);
				printf("->%lf\n", res);
				break;
			case 4:
				scanf("%lf", &x);
				res = sininverse(x);
				printf("->%lf\n", res);
				break;
			case 5:
				scanf("%lf", &x);
				res = cosinverse(x);
				printf("->%lf\n", res);
				break;
			case 6:
				
				break;
			case 7:
				scanf("%d%d", &a, &b);
				res = powr(a, b);
				printf("->%lf\n", res);
				break;
			case 8:
				scanf("%d", &a);
				b = factorial(a);
				break;
			case 9:
				scanf("%lf", &x);
				res = ln(x);
				printf("->%lf\n", res);
				break;
			case 10:
				scanf("%lf", &x);
				res = exp(x);
				printf("->%lf\n", res);
				break;
			case 11:
				complexfunc();
				break;
			case 12:
				converter();
				break;				
			case 13:
				scanf("%d%d", &a, &b);
				res = combination(a, b);
				printf("->%lf\n", res);
				break;
			default:
				exit(0);
		}
	
}
double sine(double x) {
	double term, sum;
	int i;
	x = ((x * 3.142) / 180);
	term = x;
	sum = x;
	for(i = 2; term >= 0.000001; i++) {
		term = (-1 * term * x * x) / ((2 * i - 1) * (2 * i - 2));
		sum = sum + term;
	}
	return sum;
}
double cosine(double x) {
	double term, sum, deno;
	int i;
	x = (x * (3.142 / 180));
	term = 1;
	sum = 1;
	for(i = 1; term >= 0.000001; i++) {
		deno = 2 * i * (2 * i - 1); 
		term = (-1 * term * x * x) / deno;
		sum = sum + term;
	}
	return sum;
}
double tan(double x) {
	
	double tan, sin, cos;
	sin = sine(x);
	cos = cosine(x);
	tan = sin / cos;
	return tan;
}
double reciprocal(double x) {
	double y;
	y = 1.0/x;
	return y;
}
double exp(double x) {
	double term, sum;
	int i;
	term = 1;
	sum = 1;
	for(i = 2; term >= 0.0001; i++) {
		term = (term * x) / (i);
		sum = sum + term;
	}	
	return sum;
}
/*sin inv = x + 1/2*x^3/3 + 1.3.x^5 / 2.4.5
*/
double sininverse(double x) {
	double term, sum;
	int i;
	term = x;
	sum = x;
	for(i = 2; term < 0.001; i++) {
		if(i % 2 == 0)
			term = (term * x * x * 1) / (i * (i + 1));
		else
			term = (term * x * x * i) / ((i + 1) * (i + 2));
		sum = sum + term;
	}
	return sum;
}
double cosinverse(double x) {
	return 1.57 - sininverse(x);
}
double ln(double x) {
	double term, sum;
	term = x - 1;
	sum = x - 1;
	int i;
	for(i = 2; term > 0.0001; i++) {
		term = (-1 * term * (x - 1)) / i;
		sum = sum + term;
	}
	return sum;
}
double powr(int x, int y) {
	long long prod = 1;
	int i, sign;
	long long term = x;
	if(y < 0) {
		sign = -1;
		y = -y;
	}
	for(i = 0; i < y; i++)
		prod = prod * x;
	if(sign == -1)
		prod = 1.0 / prod;
	return prod;
}
int factorial(int n) {
	int i, fact = 1;
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	for(i = 0; i < n; i++) 
		fact = fact * i;
	return fact;
}
void complexfunc() {
	typedef struct complex {
		double real, imaginary;
	}complex;
	int i;
	complex a, b, c;
	printf("Enter first Complex number\n");
	scanf("%lf%lf", &a.real, &a.imaginary);
	printf("Enter second Complex number\n");
	scanf("%lf%lf", &b.real, &b.imaginary);
	while(1) {
		printf("1. Add\n 2.Subtract \n 3. Multiply\n 4. Insert new complex numbers \n 5. Exit\n");
		scanf("%d", &i);
		switch(i) {
			case 1:
				c.real = a.real	+ b.real;
				c.imaginary = a.imaginary + b.imaginary;
				printf("%.2lf + (%.2lf)i\n", c.real, c.imaginary);
				break;  
			case 2:
				c.real = a.real	- b.real;
				c.imaginary = a.imaginary - b.imaginary;
				printf("%.2lf + (%.2lf)i\n", c.real, c.imaginary);
				break;
			case 3:
				c.real = (a.real * b.real) - (a.imaginary * b.imaginary);
				c.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
				printf("%.2lf + (%.2lf)i\n", c.real, c.imaginary);
				break;
			case 4:
				complexfunc();
			case 5:
				return;
		}
	}
}
double combination(int n, int r) {
	double res;
	res = (factorial(n)) / (factorial(r) * factorial(n - r));
	return res;
}
void converter() {
	int quantity;
	while(1) {
		printf("1. Lenght\n2. Mass\n3. Time\n4. Currency\n5. Temprature\n6. Decimal to base n\n7. Exit\n");
		scanf("%d", &quantity);	
		switch(quantity) {
			case 1:
				lenghtconv();
				break;
			case 2:
				massconv();
				break;
			case 3:
				timeconv();
				break;
			case 4:
				currency();
				break;
			case 5:
				temprature();
				break;
			case 6:
				DecimaltoBasen();
				break;
			case 7:
				return;
		}
	}
}
void lenghtconv() {
	double val, conv;
	int i;
	while(1) {
		printf("1. centimetre to meter\t2. kilometer to meter\t3. inch to foot\n4.Mile to kilometer\t5. Yard to foot\t"); 
		printf("6. meter to centimetre\n7. meter to kilometer\t8. foot to inch\t9.Kilometer to mile\n10. Foot to Yard\t"); 
		printf("11.Exit\n");
		scanf("%d", &i);
		if(i != 11) {
			printf("Enter Value : ");
			scanf("%lf", &val);
		}
		switch(i) {
			case 1:
				conv = val / 10;
				break;
			case 2:
				conv = val * 1000;
				break;
			case 3:
				conv = val * 0.0833334;
				break;
			case 4:
				conv = val * 1.609344;
				break;
			case 5:
				conv = val * 3;
				break;
			case 6:
				conv = val * 10;
				break;
			case 7:
				conv = val / 1000;
				break;
			case 8:
				conv = val * 12;
				break;
			case 9:
				conv = val * 0.62137119;
				break;
			case 10:
				conv = val * 0.3333333;
				break;
			case 11:
				return;
		}
		printf("%lf -> %lf\n", val, conv);
	}
}				

void massconv() {
	double val, conv;
	int i;
	while(1) {
		printf("1. gram to Kg\t2. kg to tonnes\t3. lbs to kg\n");
		printf("4. Kg to Gram\t5. tonnes to kg\t6. kg to lbs\n");
		printf("7. milligram to Kg\t8. kg to milligram\t9. Exit\n");
		scanf("%d", &i);
		if(i != 9) { 
			printf("Enter Value :");
			scanf("%lf", &val);
		}
		switch(i) {
			case 1:
				conv = val / 1000;
				break;
			case 2:
				conv = val / 1000;
				break;
			case 3:
				conv = val * 0.4536;
				break;
			case 4:
				conv = val * 1000;
				break;
			case 5:
				conv = val * 1000;
				break;
			case 6:
				conv = val * 2.204586;
				break;
			case 7:
				conv = val / 1000000;
				break;
			case 8:
				conv = val * 1000000;
				break;
			case 9:
				return;
		}
		printf("%lf -> %lf\n", val, conv);
		
	}
}
void timeconv() {
	int i;
	double conv, val;
	while(1) {
		printf("1.Second to Minutes\t2. Minutes to seconds\n");
		printf("3.Second to hours\t4. hours to seconds\n");
		printf("5.Minutes to hours\t6. hours to minutes\n");
		printf("7.Days to years\t8. Years to Days\n");
		printf("9. Exit\n");
		scanf("%d", &i);
		if(i != 9) {
			printf("Enter Value : ");
			scanf("%lf", &val);
		}
		switch(i) {
			case 1:
				conv = val / 60;
				break;
			case 2:
				conv = val * 60;
				break;
			case 3:
				conv = val / 3600;
				break;
			case 4:
				conv = val * 3600;
				break;
			case 5:
				conv = val / 60;
				break;
			case 6:
				conv = val * 60;
				break;
			case 7:
				conv = val / 365;
				break;
			case 8:
				conv = val * 365;
				break;
			case 9:
				return;
		}
		printf("%lf -> %lf\n", val, conv);	
	}
}
void currency() {
	double conv, val;
	int i;
	while(1) {
		printf("1. Rupee to US Dollar\t2. US Dollar to Rupee\n");
		printf("3. Rupee to Euro\t4. Euro to Rupee\n");
		printf("5. Pound to Rupee\t6. Rupee to Pound\n");
		printf("7. US Dollar to Euro\t8. US Dollar to pound\n");
		printf("9. Exit\n"); 
		scanf("%d", &i);
		if(i != 9) {
			printf("Enter Value : ");
			scanf("%lf", &val);
		}
		switch(i) {
			case 1:
				conv = val * 0.015;
				break;
			case 2:
				conv = val / 64.97;
				break;
			case 3:
				conv = val * 0.013;
				break;
			case 4:
				conv = val / 76.34;
				break;
			case 5:
				conv = val * 0.012;
				break;
			case 6:
				conv = val / 85.60;
				break;
			case 7:
				conv = val * 0.85;
				break;
			case 8:
				conv = val * 0.76;
				break;
			case 9:
				return;
		}
		printf("%lf -> %lf\n", val, conv);
	}

}
void temprature() {
	double conv, val;
	int i;
	while(1) {
		printf("1.Degree celsius to Degree fahrenheit\t2. Degree Fahrenheit to degree celsius\n");
		printf("3. Degree celsius to Kelvin\t4.Kelvin to Degree celsius\n");
		printf("5. Exit\n");
		scanf("%d", &i);
		if(i != 5) {
			printf("Enter Value : ");
			scanf("%lf", &val);
		}
		switch(i) {
			case 1:
				conv = (val * 9 / 5) + 32;
				break;
			case 2:
				conv = (val - 32) * 5 / 9;
				break;
			case 3:
				conv = val + 273.15;
				break;
			case 4:
				conv = val - 273.15;
				break;
			case 5:
				return;
		}
		printf("%lf -> %lf\n", val, conv);
	}
}

void DecimaltoBasen() {
	char rem[30];
	int num, base, k, j = 0, i = 0;
	printf("Enter Number : ");
	scanf("%d", &num);
	printf("Enter Base : ");
	scanf("%d", &base);
	while(num > 0) {
		k = num % base;
		if(k < 10) 
			rem[i] = (num % base) + '0';
		else {
			
			rem[i] = 'A' + (k - 10);
		}	
		num = num / base;
		i++;	
	}
	printf("->");
	for(j = i - 1; j >= 0; j--) 
		printf("%c", rem[j]);
	printf("\n");
}
