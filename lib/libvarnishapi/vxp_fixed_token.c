/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run generate.py instead
 */


#include "config.h"

#include <ctype.h>
#include <stdio.h>

#include "vxp.h"

unsigned
vxp_fixed_token(const char *p, const char **q)
{

	switch (p[0]) {
	case '!':
		if (p[1] == '=' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_NEQ);
		}
		if (p[1] == '~' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_NOMATCH);
		}
		return (0);
	case '(':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('(');
		}
		return (0);
	case ')':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return (')');
		}
		return (0);
	case ',':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return (',');
		}
		return (0);
	case ':':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return (':');
		}
		return (0);
	case '<':
		if (p[1] == '=' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_LEQ);
		}
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('<');
		}
		return (0);
	case '=':
		if (p[1] == '=' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_EQ);
		}
		return (0);
	case '>':
		if (p[1] == '=' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_GEQ);
		}
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('>');
		}
		return (0);
	case '[':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('[');
		}
		return (0);
	case ']':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return (']');
		}
		return (0);
	case 'a':
		if (p[1] == 'n' &&
		    p[2] == 'd' &&
		    (isword(p[2]) ? !isword(p[3]) : 1)) {
			*q = p + 3;
			return (T_AND);
		}
		return (0);
	case 'e':
		if (p[1] == 'q' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_SEQ);
		}
		return (0);
	case 'n':
		if (p[1] == 'o' &&
		    p[2] == 't' &&
		    (isword(p[2]) ? !isword(p[3]) : 1)) {
			*q = p + 3;
			return (T_NOT);
		}
		if (p[1] == 'e' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_SNEQ);
		}
		return (0);
	case 'o':
		if (p[1] == 'r' &&
		    (isword(p[1]) ? !isword(p[2]) : 1)) {
			*q = p + 2;
			return (T_OR);
		}
		return (0);
	case '{':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('{');
		}
		return (0);
	case '}':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('}');
		}
		return (0);
	case '~':
		if ((isword(p[0]) ? !isword(p[1]) : 1)) {
			*q = p + 1;
			return ('~');
		}
		return (0);
	default:
		return (0);
	}
}

const char * const vxp_tnames[256] = {
	['('] = "'('",
	[')'] = "')'",
	[','] = "','",
	[':'] = "':'",
	['<'] = "'<'",
	['>'] = "'>'",
	['['] = "'['",
	[']'] = "']'",
	['{'] = "'{'",
	['}'] = "'}'",
	['~'] = "'~'",
	[EOI] = "EOI",
	[T_AND] = "and",
	[T_EQ] = "==",
	[T_GEQ] = ">=",
	[T_LEQ] = "<=",
	[T_NEQ] = "!=",
	[T_NOMATCH] = "!~",
	[T_NOT] = "not",
	[T_OR] = "or",
	[T_SEQ] = "eq",
	[T_SNEQ] = "ne",
	[T_TRUE] = "T_TRUE",
	[VAL] = "VAL",
};
