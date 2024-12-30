#!/bin/bash

# écrire la répertoire s'il n'existe pas 
mkdir -p output/archive

# parcourir tout les fichier du directory courant 
for i in $( echo *)
do
    # vérifier que le fichier est ordinaire
    if [[ -f $i ]]
    then
        # copier le contenu du fichier $i dans le répertoire archive.
        cat  $i >  output/archive/$i
    fi
done 

echo "Tous les fichiers ordinaires du directory courant sont copient dans output/archive."