#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include"operandstack.h"
#include"integer.h"
#include"functions.h"
#define OPERATOR 	100
#define	OPERAND		200
#define	END		300
#define	ERROR		400
typedef struct token{
	int type;	// type takes values OPERAND/OPERATOR/END/
	char *s;
	char op;
}token;
char *postfix(char *str);
token *getnext(char *str, int *reset);
void print(char *str);
int quit(char *str);
int readline(char *arr, int len);
char * multiply(char a[],char b[]);
enum states {START, DIG, OP, STOP, ERR, SPC};
token *getnext(char *str, int *reset) {
	static int i;
	static int currstate;
	int nextstate;
	if(*reset == 1){
		*reset = 0;
		currstate = START;
		i = 0;
	}
	token *t = (token *)malloc(sizeof(token));
	t->s = (char *)malloc(1024);
	char currchar, currop;
	int j = 0;
	while(1) {
		currchar = str[i];
		switch(currstate) {
			case START:
				switch(currchar) {
					case '0': case '1': case '2':
					case '3': case '4': case '5':
					case '6': case '7': case '8':
					case '9': case '.':
						nextstate = DIG;
						t->s[j] = currchar;
						t->s[j + 1] = '\0';
						j++;
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '^':
					case '>': case '<': case '=':
						nextstate = OP;
						currop = currchar;	
						break;
					case ' ': case '\t':
						nextstate = SPC;
						break;
					case '\0':
						nextstate = STOP;
						t->type = END;
						break;
					default:
						break;				}
				break;
			case DIG:
				switch(currchar) {
					case '0': case '1': case '2':
					case '3': case '4': case '5':
					case '6': case '7': case '8':
					case '9': case '.':
						nextstate = DIG;
						t->s[j] = currchar;
						t->s[j + 1] = '\0';
						j++;
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '^':
					case '>': case '<': case '=':
						nextstate = OP;
						t->type = OPERAND;
						i++;
						currstate = nextstate;
						return t;	
						break;
					case ' ': case '\t':
						nextstate = SPC;
						t->type = OPERAND;
						i++;
						currstate = nextstate;
						return t;	
						break;
					case '\0':
						nextstate = STOP;
						t->type = OPERAND;
						i++;
						currstate = nextstate;
						return t;	
						break;
					default:
						nextstate = ERR;
						t->type = OPERAND;
						i++;
						currstate = nextstate;
						return t;	
						break;
				}

				break;
			case OP:
				switch(currchar) {
					case '0': case '1': case '2':
					case '3': case '4': case '5':
					case '6': case '7': case '8':
					case '9': case '.':
						nextstate = DIG;
						currop = currchar;
						t->s[j] = currchar;
						t->s[j + 1] = '\0';
						j++;
						t->type = OPERATOR;
						t->op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '^':
					case '>': case '<': case '=':
						nextstate = OP;
						t->type = OPERATOR;
						t->op = currop;
						currop = currchar;
						i++;
						currstate = nextstate;
						return t;
						break;
					case ' ': case '\t':
						nextstate = SPC;
						t->type = OPERATOR;
						t->op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					case '\0':
						nextstate = STOP;
						t->type = OPERATOR;
						t->op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
					default:
						nextstate = ERR;
						t->type = OPERATOR;
						t->op = currop;
						i++;
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case SPC:
				switch(currchar) {
					case '0': case '1': case '2':
					case '3': case '4': case '5':
					case '6': case '7': case '8':
					case '9': case '.':
						nextstate = DIG;
						t->s[j] = currchar;
						t->s[j + 1] = '\0';
						j++;
						break;
					case '+': case '-': case '*':
					case '/': case '%': case '^':
					case '>': case '<': case '=':
						nextstate = OP;
						currop = currchar;
						break;
					case ' ': case '\t':
						nextstate = SPC;
						break;
					case '\0':
						nextstate = STOP;
						break;
					default:
						nextstate = ERR;
						break;
				}

				break;
			case STOP:
				t->type = END;
				return t;
				break;
			case ERR:
				t->type = ERROR;
				return t;
				break;
		}
		currstate = nextstate;
		i++;
	}
}	 
//int main(int argc, char *argv[]) {
void bc() {
	char *str, *ans;
	str = (char *)malloc(1024);
	int x, i, qut, clr;
	while((x = readline(str, 1024))) {
		qut = quit(str);
		if(qut == 0) {
			free(str);
			return ;
		}
		ans = postfix(str);
		if(ans == NULL) 
			fprintf(stderr, "Error in Expression\n");
		else
			print(ans);
	}
	free(str);
	return ;
}
int readline(char *arr, int len) {
	int i = 0;
	//static int j = 0;
	char ch;
	/*if(j == 0) {
		ch = getchar();
	}*/
	while((ch = getchar()) != '\n') {
		
		arr[i] = ch;
		i++;
	}
	/*Need to add the null character at the end to make it a string
	 */
	arr[i] = '\0';
	//j++;
	return i;
}
void print(char *s){
		printf(">>%s\n",s);
}
int quit(char *s){
	if(strcmp(s, "quit") == 0)
		return 0;
	else
		return 1;
}

char *postfix(char *str) {
	token *t;
	char *x, *y;
	char *result;
	int k;
	stack a;
	init(&a);
	int reset = 1;
	while(1) {
		t = getnext(str, &reset);
		/*if(t->type == END)
			break;
		if(t->type == ERROR)
			return NULL;	
		if(t->type == OPERAND) {
			print(t->s);
			result = t->s;
		}
		if(t->type == OPERATOR)
			printf("%c\n", t->op);
		*/
		if(t->type == OPERAND) { 
			push(&a, t->s);
			//print(t.s);
		}
		else if (t->type == OPERATOR) { 
			if(!isempty(&a))
				x = pop(&a);
			else
				return NULL; 
			if(!isempty(&a))
				y = pop(&a);
			else
				return NULL; 
			//result = calc(y, x, t->op);
			switch(t->op) {
				case '+':
					result = realadd(x, y);
					break;
				case '-':
					result = realsub(y, x);
					break;
				case '*':
					result = realmult(x, y);	
					break;
				case '/':
					result = realdiv(x, y);		
					break;
				
				case '^' :
					result = power(y, x);
					break;
				case '>' : case '<' : case '=' :
					result = realcomp(x, y, t->op);
			}
			if(strcmp(result, "undefined") == 0)
				return "undefined";
			if(result != NULL)
				push(&a, result);
			else
				return NULL;
		}
		else if (t->type == ERROR) 
			return NULL; 
		else {
			if(!isempty(&a))
				result = pop(&a);
			else
				return NULL;
			if(isempty(&a))
				return result;
			else
				return NULL; 
		}
	}
	return result;
}
/*For Postfix evaluator run using ./project -postfix
*For Scientific Functions run using ./project -functions
*/
int main(int argc, char *argv[]) {
	//char opt[30];
	/*while(1) {
		printf("For postfix evaluator type postfix\nFor scientific functions type functions\nTo Exit type exit\n");
		scanf("%s", opt);
		if(strcmp(opt, "postfix") == 0)
			bc();
		if(strcmp(opt, "functions") == 0) {
			while(1)
				functions();
		}
		if(strcmp(opt, "exit") == 0)
			exit(0);
		
	}
	printf("Wrong Option\n");*/
	if(argc != 2) {
		fprintf(stderr, "Error\n use -p or -f \n");
		exit(0);
	}
	if(strcmp(argv[1], "-p") == 0)
		bc();
	else if(strcmp(argv[1], "-f") == 0)
		while(1)
			functions();
	else {
		printf("Use ./project -p for postfix evaluator\nUse ./project -f for scientific functions\n");
	}
	
	return 0;
}
	
