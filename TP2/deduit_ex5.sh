#!/bin/bash





# vérifier le nombre d'argument  est n'est pas vide
[[ $# == 0  ]] && echo "error: moins d'argument" && exit 1



# utiliser pour conter le nombre de ligne qui doit afficher
declare -i count

count=0
# parcourir tout les argument (le mom des fichiers données dans les paramétre )
for i in $*
do
    # une nouvelle ligne
    echo 
    # vérifier si l'argument est un fichier 
    if [[ -f $i ]]
    then
        count=0
        echo "les 5 premier  ligne de $i"
        # afficher les 5 premier ligne de fichier
        while read -r ligne
        do 

            # arrête la boucle lorsque on affiche 5 ligne de fichier 
            ((count == 5))  && break

            # afficher la  le ligne 
            echo "$ligne"
            # augmenter le nombre des ligne afficher 
            (( count++ ))
        done < $i

        # demander à l'utilisateur s'il souhaite supprimer le fichier
        read rep
        
        # supprimer le fichier si l'utilisateur veut ca 
        [[ "$rep" == "y" || "$rep" == "Y" ]] && rm $i && echo "$i est supprimer" 
    else
        echo "$i n'est pas une fichier"
    fi

done

