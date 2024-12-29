#!/bin/bash

# Retour de la commande
# 3: Le fichier n'existe pas
# 2: L'en-tête n'est pas ajouté
# 1: Nombre d'arguments incorrect
# 0: Succès

# Vérifier le nombre d'arguments
[[ $# -ne 1 ]] && echo "Cette commande prend seulement un fichier en argument." && exit 1

# Vérifier l'existence du fichier
[[ ! -f $1 ]] && echo "Erreur : Le fichier '$1' n'existe pas." && exit 3

# Étapes :
# 1. Copie la date et le contenu du fichier original dans un fichier temporaire (_tmp)
# 2. Copie le contenu de _tmp dans le fichier original
# 3. Supprime _tmp

{
    echo "$(date)"
    cat "$1"
} > _tmp || { echo "Erreur : Impossible d'écrire dans _tmp."; exit 2; }

cat _tmp > "$1" || { 
    echo "Erreur : Impossible de mettre à jour le fichier '$1'."; 
    rm _tmp; 
    exit 2; }

rm _tmp 2> /dev/null

echo "La date a été ajoutée en tête du fichier '$1'."
exit 0
