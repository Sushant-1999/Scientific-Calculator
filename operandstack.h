#define CAPACITY 1024
typedef struct stack{
	char *a[CAPACITY];
	int i;
}stack;
void init(stack *s);
void push(stack *s, char *n);
char *pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);
