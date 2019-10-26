#!/bin/bash

argc=$#
binary=$1

if [ $argc -lt 1 ]
then
    echo "$0 binary"
fi

isELF=$(file $1)

if [[ " ${isELF[*]} " == *" ELF "* ]]
then
    for i in $(objdump -d $1 | tr '\t' ' ' | tr ' ' '\n' | egrep '^[0-9a-f]{2}$')
    do
        echo -n "\x$i"
    done
    echo -e "\n"
fi
