#!/bin/bash


[[ $# == 0 ]] && echo "error: nombre d'argument." && exit 1

# parcourir les argument 
for i in $*
do
    # vérifier si l'utilisateur existe 
    if [[ -d "/home/$i" ]]
    then
        # trouver le shell
        while read -r ligne
        do
            echo nom: $i, repertoire du  connection: /home/$i, shell: "${ligne##*:}"
        done < <(cat /etc/passwd | grep $i)  
    fi
done 



