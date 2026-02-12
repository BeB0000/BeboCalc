include <stdio.h>
include <stdlib.h>
include <string.h>

define BUFFER 1024
define INT 1
define OP 0

int cpos = 0;

typedef struct {
	int type;
	char opv; // operator value
    	int nv;   // numeric value
} token;

token tktype;


int parse_number(char *t, int *pos) {
    int number = 0;

    while (t[*pos] >= '0' && t[*pos] <= '9') {
        number = (number * 10) + (t[*pos] - '0');
        (*pos)++;
    }
    
    return number;
}


void get_next_token (char *t) {
    	char c = t[cpos];

    	while (c == ' ') {
        	cpos++;
        	c = t[cpos];
    	}

    	if (c == '\0') {
        	tktype.type = -1;
    	    	return;
    	}

    	if (c >= '0' && c <= '9') {
        	tktype.type = INT;
        	tktype.nv = parse_number(t, &cpos);
    	}
    	else if (c == '+' || c == '-' || c == '*' || c == '/')
	{
       	 	tktype.type = OP;
        	tktype.opv = c;
        	cpos++;
    	}
	else
	{
		printf("err: unknown char: %c\n\n", c);
		exit(69); // :)
	}
}


int parse_term(char *t) {
    int result;

    get_next_token(t);
    if (tktype.type != INT) {
        printf("err: expected number\n");
        exit(1);
    }

    result = tktype.nv;

    while (1) {
        int saved_pos = cpos;
        get_next_token(t);

        if (tktype.type == OP && (tktype.opv == '*' || tktype.opv == '/')) {
            char op = tktype.opv;

            get_next_token(t);
            if (tktype.type != INT) {
                printf("err: expected number after %c\n", op);
                exit(1);
            }

            if (op == '*')
                result *= tktype.nv;
            else {
                if (tktype.nv == 0) {
                    printf("err: division by zero\n");
                    exit(1);
                }
                result /= tktype.nv;
            }
        }
        else {
            cpos = saved_pos;  // put token back
            break;
        }
    }

    return result;
}

int parse(char *t) {
    cpos = 0;

    int result = parse_term(t);

    while (1) {
        int saved_pos = cpos;
        get_next_token(t);

        if (tktype.type == OP && (tktype.opv == '+' || tktype.opv == '-')) {
            char op = tktype.opv;

            int term = parse_term(t);

            if (op == '+')
                result += term;
            else
                result -= term;
        }
        else {
            cpos = saved_pos;
            break;
        }
    }

    return result;
}



void interpret(char *t) {
    	int result = parse(t);
    	printf("result: %d\n", result);
	result = 0;
}

int main(void) {
	char t[BUFFER];

    	while (67) //:)
    	{
        	fputs("> ", stdout);
        	fgets(t, BUFFER, stdin);
        	t[strcspn(t, "\n")] = '\0';
        
        	interpret(t);
    	}
	return 0;
}


