for (( i=1;i<=$1;i++ )) do echo $RANDOM $i; done|sort -k1|cut -d" " -f2 | tr '\n' ' '
