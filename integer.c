#include"integer.h"
#include"functions.h"
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<stdio.h>
char * mult(char *x, char *y) {
	char *result ;
	
	char *tenp = (char *)malloc(2);
	tenp[0] = '-';					
	tenp[1] = '\0';
	if(x[0] != '-' && y[0] != '-')
		result = multiply(x, y);
	if(x[0] == '-' && y[0] == '-')
		result = multiply(&x[1], &y[1]);
	if(x[0] == '-' && y[0] != '-') {
		result = multiply(&x[1], y);
		strcat(tenp, result);
		return tenp;
	}
	if(x[0] != '-' && y[0] == '-') {
		result = multiply(x, &y[1]);
		strcat(tenp, result);
		return tenp;
	}
	return result;

}
char * multiply(char *a,char *b){
    	char *mul;
    	char *c;
    	c = (char *)malloc(400);
    	mul = (char *)malloc(400);
    	char *temp;
    	temp = (char *)malloc(400);
    	int la, lb;
    	int i, j, k = 0, x = 0, y;
    	int r = 0;
    	int sum = 0;
    	la = strlen(a)-1;
    	lb = strlen(b)-1;
        for(i = 0; i <= la; i++){
                a[i] = a[i] - '0';
        }

        for(i = 0; i <= lb; i++){
                b[i] = b[i] - '0';
        }

   	 for(i = lb; i >= 0; i--){
        	 r = 0;
        	 for(j = la; j >= 0; j--){
        	     temp[k++] = (b[i] * a[j] + r) % 10;
        	     r = (b[i] * a[j] + r) / 10;
        	 }
        	 temp[k++] = r;
        	 x++;
        	 for(y = 0; y < x; y++){
        	     temp[k++] = 0;
        	 }
  	 }	
   
    	k = 0;
    	r = 0;
    	for(i = 0; i < la + lb + 2; i++){
		 sum = 0;a
		 y = 0;
		 for(j = 1; j <= lb + 1; j++){
		 	if(i <= la + j){
		         	sum = sum + temp[y + i];
		     	}
		     	y += j + la + 1;
		 }
		 c[k++] = (sum + r) % 10;
		 r = (sum + r) / 10;
    	}
    	c[k] = r;
    	j=0;
    	for(i = k - 1; i >= 0; i--){
         	mul[j++] = c[i] + '0';
    	}
    	mul[j] = '\0';
    	mul = removezero(mul);
    	return mul;
}
char *addition(char *x, char *y) {
	char *result, *tenp, *new;
	//x = removezero(x);
	//y = removezero(y);
	if((strcmp(x, "0") == 0) && (strcmp(y, "0") == 0))
		return "0";
	if((strcmp(x, "0") == 0) && (strcmp(y, "0") != 0))
		return y;
	if((strcmp(x, "0") != 0) && (strcmp(y, "0") == 0))
		return x;
	if((strcmp(x, "0") != 0) && (strcmp(y, "0") != 0)) {
		if(x[0] != '-' && y[0] != '-')		
			result = add(x, y);
		if(x[0] == '-' && y[0] == '-') {
			tenp = (char *)malloc(2);
			tenp[0] = '-';
			tenp[1] = '\0';
			result = add(&x[1], &y[1]);
			strcat(tenp, result);
			return tenp;
		}		
		if(x[0] == '-' && y[0] != '-') {
			result = subtract(y, &x[1]);
			return result;
		}
		if(x[0] != '-' && y[0] == '-') {
			result = sub(x, &y[1]);
			return result;
		}
	}
	return result;
}
char *add(char *x, char*y) {
	int lena = strlen(x);
	int lenb = strlen(y);
	int i = lena - 1;
	int j = lenb - 1;
	int k = 0, m = 0,n;
	int anum, bnum, total, carry = 0;
	char *result, *new;
	if(lena >= lenb)
		result = (char *)malloc(lena + 2);
	else
		result = (char *)malloc(lenb + 2);
	while((i != -1) || (j != -1)) {
			
			if(i != -1)
				anum = x[i] - '0';
			else
				anum = 0;
			if(j != -1)
				bnum = y[j] - '0';
			else
				bnum = 0;
			total = anum + bnum + carry;
			carry = 0;
			result[k] = (total % 10) + '0';
			carry = total / 10;
			k++;
			if(i != -1)
				i--;
			if(j != -1)
				j--;
	}
	if(carry == 1) {
		result[k] = 1 + '0';
		k++;
	}
	result[k] = '\0';
	k--;
	new = (char *)malloc(k + 2);
	for(m = 0, n = k; n >= 0 ; m++, n--) {
		new[m] = result[n];
	}	
	new[m] = '\0';
	//new = (char *)malloc(strlen(result));
	//return result;
	return new;
}
char *sub(char *x, char *y) {
	char *result = NULL;
	if(x[0] == '-' && y[0] == '-')
		result = subtract(&x[1], &y[1]);
	if(x[0] != '-' && y[0] != '-')
		result = subtract(x, y);
	if(x[0] != '-' && y[0] == '-')
		result = addition(x, &y[1]);
		
	
	
	return result;
	
}
char *subtract(char *x, char*y) {
	if((strcmp(x, "0") == 0) && (strcmp(y, "0") == 0))
		return "0";
	if((strcmp(x, "0") == 0) && (strcmp(y, "0") != 0)){
		char *tenp = (char *)malloc(strlen(y) + 2);
		tenp[0] = '-';
		tenp[1] = '\0';
		tenp = strcat(tenp, y);
		return tenp;
	}
	if((strcmp(x, "0") != 0) && (strcmp(y, "0") == 0))
		return x;
	int lena = strlen(x);
	int lenb = strlen(y);
	int i = lena - 1;
	int j = lenb - 1;
	int k = 0, m, n, p, q;
	int anum, bnum, diff, borrow;
	char *result, *new;
	if(lena >= lenb)
		result = (char *)malloc(lena + 2);
	else
		result = (char *)malloc(lenb + 2);
	int cmp = compare(x, y);
	if(cmp == 3)
		return "0";
	if(cmp == 1) {
		
		while((i != -1) || (j != -1)) {
			if(i != -1)
				anum = x[i] - '0';
			else
				anum = 0;
			if(j != -1)
				bnum = y[j] - '0';
			else
				bnum = 0;
			if(anum >= bnum)
				diff = (anum - bnum);
			if(anum < bnum) {
				diff = ((anum + 10) - bnum);
				x[i - 1] = x[i - 1] - 1;
			}
			result[k] = diff + '0';
			k++;
			if(i != -1)
				i--;
			if(j != -1)
				j--;
		}	
		result[k] = '\0';
		k--;
		new = (char *)malloc(k + 2);
		for(m = 0, n = k; n > -1 ; m++, n--) {
			new[m] = result[n];
		}
		new[m] = '\0';	
		return new;	
	}
	if(cmp == 2) {
		char *temp;
		char *res;
		temp = (char *)malloc(2);
		temp[0] = '-';
		temp[1] = '\0';
		res = subtract(y, x);
		temp = strcat(temp, res);
		return temp;

	}

}
int compare(char *x, char *y) {
	int lena = strlen(x);
	int lenb = strlen(y);
	int i, j;
	//x = removezero(x);
	//y = removezero(y);
	if(x[0] == '-' && y[0] != '-')
		return 2;
	if(x[0] != '-' && y[0] == '-')
		return 1;
	if(lena > lenb)
		return 1; /* 1 means x is greater than y*/
	if(lenb > lena)
		return 2; /*2 means y is greater than x*/
	if(lenb == lena) {
		for(i = 0, j = 0; (i < lena) && (j < lenb); i++, j++) {
			if(x[i] > y[j])
				return 1;
			if(y[j] > x[i])
				return 2;
		}
		return 3; /*3 means x and y are equal*/
	}
}	

int createint(char *str) {
	int sum = 0;
	int len = strlen(str);
	int term, i;
	for(i = 0; i < len; i++) {
		term = str[i] - '0';
		sum = sum * 10 + term;
	}

	return sum;
}
char *power(char *x, char *z) {
	char *term, *result, *pow;
	int y = createint(z);
	/*result = (char *)malloc(1024);
	result[0] = '1';
	result[1] = '\0';*/
	result = x;
	int i = 0, temp, m, new, n;
	if(strcmp(x, "0") == 0) 
		if(y == 0) {
			return NULL;
		}
		else 
			return 	"0";
	else /* x!=0 */ {
		if(y == 0)
			return "1";
		else /* x!=0 y!=0 */{
			
			/*while(y > 1) {
				term = x;
				result = mult(result, term);
				y--;
			}*/
			int w = createint(x);
			double po = powr(w, y);
			new = po;
			result = (char *)malloc(200);
			while(new) {
				temp = new % 10;
				result[i] = temp + '0';
				new = new / 10;
				i++;
			}
			result[i] = '\0';
			pow = (char *)malloc(i + 2);
			for(m = 0, n = i - 1; n > -1 ; m++, n--) {
				pow[m] = result[n];
			}
			pow[m] = '\0';
			return pow;
		}	
	}
	return result;
}
char *division(char *x, char *y) {
	char *result ;
	x = removezero(x);
	y = removezero(y);
	if(strcmp(x, "0") == 0)
		return "Undefined";
	if(strcmp(x, "1") == 0)
		return x;
	if(strcmp(y, "0") == 0)
		return "0";
	char *tenp = (char *)malloc(2);
	tenp[0] = '-';
	tenp[1] = '\0';
	if(x[0] != '-' && y[0] != '-')
		result = divides(x, y);
	if(x[0] == '-' && y[0] == '-')
		result = divides(&x[1], &y[1]);
	if(x[0] == '-' && y[0] != '-') {
		result = divides(&x[1], y);
		strcat(tenp, result);
		return tenp;
	}
	if(x[0] != '-' && y[0] == '-') {
		result = divides(x, &y[1]);
		strcat(tenp, result);
		return tenp;
	}
	return result;
}
char *divides(char *y, char *x) {
	double res, a, b;
	int new, temp, m, n, k;
	char *result, *div;
	int len = 0, i = 0;
	a = createdouble(x);
	b = createdouble(y);
	res = a / b;
	new = (int)res;
	if(new == 0)
		return "0";
	temp = new;
	while(temp) {
		temp = temp / 10;
		len++;
	}
	result = (char *)malloc(len + 1);
	while(new) {
		temp = new % 10;
		result[i] = temp + '0';
		new = new / 10;
		i++;
	}
	result[i] = '\0';
	div = (char *)malloc(i + 2);
	for(m = 0, n = i - 1; n > -1 ; m++, n--) {
		div[m] = result[n];
	}
	div[m] = '\0';
	return div;
	
		
}
double createdouble(char *x) {
	double sum = 0;
	int i = 0;
	for(i = 0; x[i] != '\0'; i++) {
		sum = sum * 10 + x[i] - '0';
	}
	return sum;
}
char *comparison(char *x, char *y, char ch) {
	int ans = compare(x, y);
	char *res;
	res = (char *)malloc(6);
	if(ans == 1 && ch == '<')
		strcpy(res, "1");
	else if(ans == 2 && ch == '>')
		strcpy(res, "1");
	else if(ans == 3 && ch == '=')
		strcpy(res, "1");
	else
		strcpy(res, "0");
	return res;
}
char *realadd(char *x, char *y) {
	//return add(x, y);
	char *result;
	int i, j, k, decx = 0, decy = 0, lenx, leny, lenres;
	int countx = 0, county = 0;
	//x = remdec(x);
	//y = remdec(y);
	for(i = 0; x[i] != '\0'; i++) {
		if(x[i] == '.') {
			decx = i;
			for(j = i; x[j + 1] != '\0'; j++) {
				x[j] = x[j + 1];
				countx++;
			}
			
			x[j] = '\0';
			break;
			
		}
		
	}
	for(i = 0; y[i] != '\0'; i++) {
		if(y[i] == '.') {
			decy = i;
			for(j = i; y[j + 1] != '\0'; j++) {
				y[j] = y[j + 1];
				county++;
			}
			y[j] = '\0';
			break;
		}
		
	}
	//printf("%d %d %d %d \n", decx, decy, countx, county);
	if((decx != 0) || (decy != 0)) {	/*Decimal exists*/
		/*if((decx == decy) && (countx == county)){
			result = add(x, y);
			decy = decy + (decx - decy);
			result = insertpt(result, decx);
			return result;
		}
		 else if((decx > decy) && (countx == county)) {
			y = addzerosbefore(y, decx - decy);
			result = add(x, y);
			decx = decx + (decy - decx);
			result = insertpt(result , decx);
			return result;
		}
		else if((decy > decx) && (countx == county)) {
			x = addzerosbefore(x, decy - decx);
			result = add(x, y);
			result = insertpt(result, decy);
			return result;
		}*/
		if((decx == decy) && (countx == county)){	/* ordered numbers ie 12.51 24.18 */
			result = add(x, y);
			
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
		 else if((decx > decy) && (countx == county)) {
			y = addzerosbefore(y, decx - decy );
			
			result = add(x, y);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
		else if((decy > decx) && (countx == county)) {
			x = addzerosbefore(x, decy - decx);
			//decx = decx + (decy - decx);
			result = add(x, y);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decy);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decy + 1);
			return result;
		}
		else if((decx == decy) && (countx > county)) {
			y = addzerosafter(y, countx - county);
			result = add(x, y);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
			
		}
		else if((decx == decy) && (countx < county)) {
			x = addzerosafter(x, county - countx);
			result = add(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decx > decy) && (countx > county)) {
			y = addzerosbefore(y, decx - decy);
			y = addzerosafter(y, countx - county);
			result = add(x, y);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
		else if((decx > decy) && (countx < county)) {
			y = addzerosbefore(y, decx - decy);
			x = addzerosafter(x, county - countx);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
		else if((decx < decy) && (countx > county)) {
			x = addzerosbefore(x, decy - decx);
			y = addzerosafter(y, countx - county);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
		else if((decx < decy) && (countx < county)) {
			x = addzerosbefore(x, decy - decx);
			x = addzerosafter(x, county - countx);
			if(result[0] == '-' && (strlen(x) == strlen(result)))
				result = insertpt(result, decx + 1);
			else if((strlen(x) == strlen(result)))
				result = insertpt(result, decx);
			else if((strlen(x)  + 1 == strlen(result)))
				result = insertpt(result, decx + 1);
			return result;
		}
	}
	else
		result = add(x, y);
	return result;
 
}
char *realsub(char *x, char *y) {
	//return sub(x, y);
	char *result;
	int i, j, k, decx = 0, decy = 0, dig_after_x, dig_after_y;
	int countx = 0, county = 0;
	//x = remdec(x);
	//y = remdec(y);
	for(i = 0; x[i] != '\0'; i++) {
		if(x[i] == '.') {
			decx = i;
			for(j = i; x[j + 1] != '\0'; j++) {
				x[j] = x[j + 1];
				countx++;
			}
			
			x[j] = '\0';
			break;
			
		}
		
	}
	for(i = 0; y[i] != '\0'; i++) {
		if(y[i] == '.') {
			decy = i;
			for(j = i; y[j + 1] != '\0'; j++) {
				y[j] = y[j + 1];
				county++;
			}
			y[j] = '\0';
			break;
		}
		
	}
	//x = addzerosbefore(x, 1);
	//y = addzerosbefore(y, 1);
	//printf("%d %d %d %d \n", decx, decy, countx, county);
	if((decx != 0) || (decy != 0)) {	/*Decimal exists*/
		if((decx == decy) && (countx == county)){	/* ordered numbers ie 12.51 24.18 */
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result, decx + 1);
			else
				result = insertpt(result, decx);
			return result;
		}
		 else if((decx > decy) && (countx == county)) {
			y = addzerosbefore(y, decx - decy );
			
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decy > decx) && (countx == county)) {
			x = addzerosbefore(x, decy - decx);
			//decx = decx + (decy - decx);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result, decy + 1);
			else
				result = insertpt(result , decy);
			return result;
		}
		else if((decx == decy) && (countx > county)) {
			y = addzerosafter(y, countx - county);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
			
		}
		else if((decx == decy) && (countx < county)) {
			x = addzerosafter(x, county - countx);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decx > decy) && (countx > county)) {
			y = addzerosbefore(y, decx - decy);
			y = addzerosafter(y, countx - county);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decx > decy) && (countx < county)) {
			y = addzerosbefore(y, decx - decy);
			x = addzerosafter(x, county - countx);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decx < decy) && (countx > county)) {
			x = addzerosbefore(x, decy - decx);
			y = addzerosafter(y, countx - county);
			result = sub(x, y);
			if(result[0] == '-')
				result = insertpt(result , decx + 1);
			else
				result = insertpt(result , decx);
			return result;
		}
		else if((decx < decy) && (countx < county)) {
			x = addzerosbefore(x, decy - decx);
			x = addzerosafter(x, county - countx);
			result = sub(x, y);
			if(result[0] == '-')			
				result = insertpt(result , decy + 1);
			else
				result = insertpt(result , decy);
			return result;	
		}
	
		
	}
	else
		result = sub(x, y);
	return result;
 
}
char *realmult(char *x, char *y) {
	char *result;
	int i, j, k, decx = 0, decy = 0, dig_after_x, dig_after_y;
	int countx = 0, county = 0;
	//x = remdec(x);
	//y = remdec(y);
	for(i = 0; x[i] != '\0'; i++) {
		if(x[i] == '.') {
			decx = i;
			for(j = i; x[j + 1] != '\0'; j++) {
				x[j] = x[j + 1];
				countx++;
			}
			
			x[j] = '\0';
			break;
			
		}
		
	}
	for(i = 0; y[i] != '\0'; i++) {
		if(y[i] == '.') {
			decy = i;
			for(j = i; y[j + 1] != '\0'; j++) {
				y[j] = y[j + 1];
				county++;
			}
			y[j] = '\0';
			break;
		}
		
	}
	if((decx != 0) || (decy != 0)) {
		
			result = mult(x, y);
			result = insertpt(result, strlen(result) - (countx + county));
			return result;
	}
	else
	return mult(x, y);
}
//char *realpow(char *x, char *y) 

char *realcomp(char *x, char *y, char ch) {
	return comparison(x, y, ch);
}
char *realdiv(char *x, char *y) {
	//return division(x, y);
	char *result;
	int i, j, k, decx = 0, decy = 0, dig_after_x, dig_after_y;
	int countx = 0, county = 0;
	//x = remdec(x);
	//y = remdec(y);
	for(i = 0; x[i] != '\0'; i++) {
		if(x[i] == '.') {
			decx = i;
			for(j = i; x[j + 1] != '\0'; j++) {
				x[j] = x[j + 1];
				countx++;
			}
			
			x[j] = '\0';
			break;
			
		}
		
	}
	for(i = 0; y[i] != '\0'; i++) {
		if(y[i] == '.') {
			decy = i;
			for(j = i; y[j + 1] != '\0'; j++) {
				y[j] = y[j + 1];
				county++;
			}
			y[j] = '\0';
			break;
		}
		
	}
	if((decx != 0) || (decy != 0)) {
		
			result = division(x, y);
			if(county == countx || county > countx)
				result = insertpt(result, strlen(result) - (county));
			else
				result = insertpt(result, strlen(result) - (countx));
			
			return result;
	}
	else
	return division(x, y);
}
char *remdec(char *ptr) {
	int i, j;
	for(i = 0; ptr[i] != '\0'; i++) {
		if(ptr[i] == '.') {
			for(j = i; ptr[j + 1] != '\0'; j++) {
				ptr[j] = ptr[j + 1];
			}
			ptr[j] = '\0';
			break;
		}
		
	}
	return ptr;
}
char *insertpt(char *x, int pos) {
	int i, j;
	int len = strlen(x);
	char *res;
	res = (char *)malloc(len + 2);
	for(i = 0, j = 0; x[j] != '\0'; j++, i++) {
		if(i == pos) {
			res[i] = '.';
			i++;
		}
		res[i] = x[j];
	}
	res[i] = '\0';
	return res;
}
char *removezero(char *x) {
	int i = 0, j = 0, k = 0;
	char *res = (char *)malloc(strlen(x));
	for(i = 0, j = 0; x[i] != '\0'; i++) {
		if((k == 0) && (x[i] == '0'))
			continue;
		else {
			res[j] = x[i];
			k++;
			j++;
		}
		
	}
	res[j] = '\0';
	if(res[0] == '\0') {
		res[0] = '0';
		res[1] = '\0';
		
	}
	
	return res;	
}
char *addzerosbefore(char *x, int n) {
	char *res = (char *)malloc(strlen(x) + n);
	int i, j;
	for(i = 0; i  < n; i++) 
		res[i] = '0';
	for(j = 0; x[j] != '\0'; j++, i++)
		res[i] = x[j];
	return res;
}
char *addzerosafter(char *x, int n) {
	//char *res = (char *)malloc(strlen(x) + n);
	int i = strlen(x) - 1, j;
	for(i = strlen(x) , j = 0; j < n; i++, j++) 
		x[i] = '0';
	x[i] = '\0';
	return x;
}		
