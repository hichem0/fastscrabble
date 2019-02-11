this program was written on c++ 
step of correction :
$mkdir fbuild
$ cd fbuild
$ cp /rendu/$ELEVE/myfastscrabble.cpp ./
$ g++ -Ofast -Wall -Werror -std=c++11 -o myfs-test myfastscrabble.cpp $ ./myfs-test -d /tmp/dic.txt -s “lets” -s “rock” -s “...”