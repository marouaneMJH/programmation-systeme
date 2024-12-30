#!/bin/bash

declare -a tabnoms

while read  line
do
        user=${line%%:*}
        tabnoms[${#tabnoms[@]}]="$user"

done < <(cat /etc/passwd | grep home)

# Afficher tous les éléments du tableau
echo "Liste des utilisateurs : ${tabnoms[@]}"


echo le nombre total des element est ${#tabnoms[@]}

echo nom par hazard ${tabnoms[$(($RANDOM % ${#tabnoms[@]}))]}