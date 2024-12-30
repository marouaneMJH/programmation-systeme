#!/bin/bash


# vérifier le nombre d'argument 
[[ $# != 1 ]] && echo "Le nombre d'arguments doit être 1" && exit 1

ls "/bin/$1" &> /dev/null
# Afficher le code de retour de l'execution de ls
echo "$?"