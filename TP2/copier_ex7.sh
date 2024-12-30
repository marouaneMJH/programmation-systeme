#!/bin/bash 


# Code de retour
# 1: Nombre de d'argument est incorrect 
# 2: Le fichier source n’existe pas ou il n’est pas copiable
# 3: Le fichier source n’est pas un fichier ordinaire.
# 4: Le fichier destination n'existe pas
# 5: La répertoire destination n'est pas accessible en écriture
# 6: La copie a échoué.


[[ $# != 2 ]] && echo "Le nombre d'argument est incorrect." && exit 1

[[ ! -r $1 ]] && echo "Le fichier source n’existe pas ou il n’est pas copiable." && exit 2

[[ ! -f $1 ]] && echo "Le fichier source n’est pas un fichier ordinaire." && exit 3

[[ ! -f $2 ]] && echo "Le fichier destination n'existe pas." && exit 4

[[ ! -w $(dirname $2) ]] && echo "La répertoire destination n'est pas accessible en écriture" && exit 5

cp $1 $2 2> /dev/null

[[ $? != 0 ]] && echo "La copie a échoué." && exit 6



