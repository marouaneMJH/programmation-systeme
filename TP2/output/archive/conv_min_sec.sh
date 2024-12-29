#!/bin/bash 


# vérifier l'argument passé où paramétre
[[ $# != 1 ]] && echo "error: nombre d'argument" && exit 1

#min: les minutes 
#sec: les second
declare -i min sec  

min=$(($1 / 60))
sec=$(($1 % 60))

echo "le nombre des minutes et seconds dans $1 est $min et $sec."
