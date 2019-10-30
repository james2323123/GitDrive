yacc -d 'mini-pascal-yacc.y'
lex 'mini-pascal-lex.l'
cc 'y.tab.c' -ly -ll
