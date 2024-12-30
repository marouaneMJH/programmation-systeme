#!/bin/bash 

# Le code de retour 
# 1: nombre argument n'est pas valable  
# 0: le script est bien exécuter 

# vérifier l'argument passé où paramètre
[[ $# != 1 ]] && echo "vous devez entrez seulement un temps exprimé en secondes." && exit 1

#min: les minutes 
#sec: les second
declare -i min sec  

# calculons les minute et les seconds
min=$(($1 / 60)) 
sec=$(($1 % 60))

echo "le nombre des minutes et seconds dans $1 est $min et $sec."
