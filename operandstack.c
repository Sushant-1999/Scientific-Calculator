#include"operandstack.h"
#include<stdlib.h>
#include<string.h>

void init(stack *s) {
	s->i = 0;
	s->a[s->i] = NULL;
}
void push(stack *s, char *n) {
	s->a[s->i] = (char *)malloc(400);
	strcpy(s->a[s->i], n);
	(s->i)++;	
}
char *pop(stack *s) {
	char *ret;
	ret = (char *)malloc(400);
	strcpy(ret, s->a[(s->i) - 1]);
	(s->i)--;
	return ret;
}
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i = CAPACITY;
}
