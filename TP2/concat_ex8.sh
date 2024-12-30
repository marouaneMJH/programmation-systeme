#!/bin/bash





# Code de retour
# 1: Nombre argument n'est pas valide
# 2: L'existence ou le droit de lisibilité du fichier d'entrer
# 3: les permission de fichier sortie n'est pas valide


[[ $# != 3 ]] && echo "nombre d'argument (doit être 3)." && exit 1 

[[ ! -r $1 ]] && echo "$1 n'existe pas ou le fichier n'est pas lisible."&& exit 2

[[ ! -r $2 ]] && echo "$2 n'existe pas ou le fichier n'est pas lisible." && exit 2

[[ ! -f $3 ]]  && [[ ! -w $3 ]] &&  echo "on peut pas éditer le contenue de $3" && exit 3


cat $1 $2 > $3

[[ $? != 0 ]] && echo "Concatène ne fait pas."
