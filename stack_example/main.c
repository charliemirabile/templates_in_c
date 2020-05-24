#include "templates/stack.char@TYPE.t.h"
#include <stdio.h>

int main(void)
{
	int c;
	Stack_char *braces __attribute__ ((__cleanup__(stack_char_destroy)));
	braces = stack_char_init_default();

	while((c = fgetc(stdin))!=EOF)switch(c)
	{
	case '<':
		if(!stack_char_push(braces,'>'))goto bad;
		break;
	case '(':
		if(!stack_char_push(braces,')'))goto bad;
		break;
	case '[':
		if(!stack_char_push(braces,']'))goto bad;
		break;
	case '{':
		if(!stack_char_push(braces,'}'))goto bad;
		break;
	case '}':
	case ']':
	case ')':
	case '>':
		if(stack_char_empty(braces))
			return 1;
		if(*stack_char_top(braces)!=c)
			return 1;
		if(!stack_char_pop(braces,NULL))goto bad;
	default:
		break;
	}
	return !stack_char_empty(braces);
bad:
	fputs("Critical error exiting\n",stdout);
	return -1;
}
