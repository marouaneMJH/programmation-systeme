#!/bin/bash 


# vérifier l'entrer
(($# != 1)) || [[ $1 != +([0-9]) ]]  && echo "argument n'est pas valide." && exit 1

# la fonction récursive
function func_c {
    declare -i n
    if (( $1 == 0 ))
    then
        echo 1
    else
        (( n = $1 - 1 ))
        n=$(func_c $n)  
        echo $(( $1 * n ))
    fi
}

# appeler la fonction récursive 
func_c $1
