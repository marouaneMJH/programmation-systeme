#!/bin/bash

# Retour de la commande
# 3: Le fichier n'existe pas
# 2: L'en-tête n'est pas ajouté
# 1: Nombre d'arguments incorrect
# 0: Succès

# Vérifier le nombre d'arguments
[[ $# != 1 ]] && echo "Cette commande prend seulement un fichier en argument." && exit 1

# Vérifier l'existence et droit de lisibilité du fichier 
[[ ! -r $1  ]] && echo "Le fichier '$1' n'existe pas ." && exit 3

# Étapes :
# 1. Copie la date et le contenu du fichier original dans un fichier temporaire (_tmp)
# 2. Copie le contenu de _tmp dans le fichier original
# 3. Supprime _tmp

{
    echo "$(date)"
    cat "$1"
} > _tmp 

cat _tmp > "$1" || { 
    echo "Impossible de mettre à jour le fichier '$1'."; 
    rm _tmp; 
    exit 2; }

rm _tmp 2> /dev/null

[[ $? != 0 ]] && echo "Impossible de mettre à jour le fichier '$1'." && exit 2
echo "La date a été ajoutée en tête du fichier '$1'."

