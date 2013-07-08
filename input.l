%{
#include "Polynom.h"
#define YY_DECL int yylex(Polynom &P)
%}
INTEGER {[0-9]+}
FLOAT {INTEGER"."[0-9]*}
COEFFITIENT {FLOAT}|{INTEGER}
%option noyywrap
%x X
%x Y
%x Z
%x C
%%
%{
	monom m;m.x=0;m.y=0;m.z=0;m.constant=0;
%}
<C>	"X"|"x""^"	{
		m.constant=1;
		BEGIN(X);
}

"X"|"x""^"	{
	BEGIN(X);
}

<C>	"Y"|"y""^"	{
		m.constant=1;
		BEGIN(Y);
}

"Y"|"y""^"	{
	BEGIN(Y);
}

<C>	"Z"|"z""^"	{
		m.constant=1;
		BEGIN(Z);
}

"Z"|"z""^"	{
	BEGIN(Z);
}

<C>	 {FLOAT}		{
			m.constant=atof(yytext);
}
b

<C>	 {INTEGER}	{
			m.constant=atoi(yytext);
}
bb

<X>	 {INTEGER}	{
			m.x=atoi(yytext);
}
bbb

<Y>	 {INTEGER}	{
			m.y=atoi(yytext);
}
bbbb

<Z> 	{INTEGER}	{
			m.z=atoi(yytext);
}


"+"	{
	P.add(m);
	BEGIN(INITIAL);
	BEGIN(C);
}

\n	return 0;

%%