#!/bin/bash


# demander a l'utilisateur de saisir une suite de mots

#pour les demander a l'utilisateur on utilise la commande read -p 
#pour les stocker dans un tableau on utilise -a 
read -p  "Entrez une suite de mots (d'au moins trois mots): " -a mots

# vérifier le  nombre de mots est inférieur à 3,on affiche un message d'erreur
if [[ ${#mots[*]} < 3 ]]
then
    echo "Il faut saisir au moins 3 mots"
    exit 1
fi

# afficher le premier et le troisième mot
echo "${mots[0]} ${mots[2]}"
