#!/bin/bash


# Les code de retour
# 1: moins d'arguments


# vérifier le nombre d'argument  est n'est pas vide
[[ $# == 0  ]] && echo "Vous devez saisir au moins un argument." && exit 1



# utiliser pour conter le nombre de ligne qui doit afficher
declare -i count

# initialiser  le compteur par 0
$count=0

# parcourir tout les argument (Les noms des fichiers donnés dans les paramètres).
for i in $*
do
    # une nouvelle ligne
    echo 
    # vérifier l'existence et les droits de lisibilité du fichier $i
    if [[ -r $i ]]
    then
        count=0
        echo "Les 5 premier  ligne de $i:"
        # afficher les 5 premier ligne de fichier
        while read -r ligne
        do 
            # arrête la boucle lorsque on affiche 5 ligne de fichier 
            (( count == 5 ))  && break

            # afficher la ligne 
            echo "$ligne"
            # augmenter le nombre de lignes à afficher.
            (( count++ ))
        done < $i

        # demander à l'utilisateur s'il souhaite supprimer le fichier
        read rep
        
        # supprimer le fichier si l'utilisateur veut ça 
        [[ "$rep" == "y" || "$rep" == "Y" ]] && rm $i && echo "$i est supprimer" 
    else
        echo "$i n'est pas un fichier"
    fi

done

