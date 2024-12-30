#!/bin/bash


# Les code de retour 
# 1: Aucune argument saisi
# 2: Le script est bien exécuté


[[ $# == 0 ]] && echo "Aucun argument saisi, vous devez entrer au moins un argument." && exit 1

# parcourir les arguments
for i in $*
do
    # vérifier si l'utilisateur existe 
    if [[ -d "/home/$i" ]]
    then
        # trouver le shell
        while read -r ligne
        do
            echo nom: $i, répertoire du  connection: /home/$i, shell: "${ligne##*:}"
        done < <(cat /etc/passwd | grep $i)   # le 
    else
        echo "L'utilisateur << $i >> n'existe pas."
    fi
done 



