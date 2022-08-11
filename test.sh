#!/bin/bash

echo calc : '3+2*(5-2)'
echo '3+2*(5-2)' | ./calc 0123456789 '()+-*/%' 9 ; echo
echo
echo calc : '3+2*(5-2)+(5*(6+2))'
echo '3+2*(5-2)+(5*(6+2))' | ./calc 0123456789 '()+-*/%' 19 ; echo
echo
echo calc : '3+2'
echo '3+2' | ./calc 0123456789 '()+-*/%' 3 ; echo
echo
echo calc : '3+2+'
echo '3+2+' | ./calc 0123456789 '()+-*/%' 4 ; echo
echo
echo calc : '-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))'
echo '-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))' | ./calc 0123456789 '()+-*/%' 84 | cat -e ; echo
echo
echo calc : 'a+b'
echo 'a+b' | ./calc '0abcdefghi' '()+-*/%' 3 ; echo
echo
echo calc : '(a+b('
echo '(1+2(' | ./calc 0123456789 '()+-*/%' 5 ;