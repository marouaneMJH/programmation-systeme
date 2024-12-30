#!/bin/bash



[[ $# != 0 ]] &&  echo la commande ne prend pas des arguments && exit 1

# déclarer reps comme un tableaux
declare -a reps

# lire les répertoires
read -p "Entrez les noms des répertoires: " reps 


# afficher le contenue de chaque répertoire
for i in $reps
do 
    # vérifier si la répertoire lisible
    if [[ -r $i ]]
    then 
        echo -e "\n le contenu de $i est:" 
        ls $i
    # sinon=
    else
        echo -e "\n$i \t n\'existe pas ou n'est pas lisible."
    fi
done