#!/bin/bash

# Fonction pour calculer la factorielle  alternative
factorial() {
    local n=$1
    local result=1
    for ((i = 2; i <= n; i++))
    do
        result=$((result * i))
    done
    echo $result
}

num=$1

if (($# != 1)) || [[ $1 != +([0-9]) ]]  
then 
    echo "argument n'est pas valide." && exit 1
fi

echo "la result de la factorielle  de  $num est  $(factorial $num)"

