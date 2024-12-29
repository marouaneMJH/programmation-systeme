#!/bin/bash





#
# 1: nombre argument error
# 2: fichier n'est pas valide 
# 3: les permission de fichier sortie n'est pas valide


[[ $# != 3 ]] && echo "Error: nombre d'argument (doit être 3)." && exit 1 

[[ ! -r $1 ]] && echo "Error: $1 n'existe pas ou les permissions de fichier n'est pas valide."&& exit 2

[[ ! -r $2 ]] && echo "Error: $2 n'existe pas ou les permissions de fichier n'est pas valide." && exit 2

[[ ! -f $3 ]]  && [[ ! -w $3 ]]  echo "on peut pas éditer le contenue de $3" && exit 3


cat $1 $2 > $3

[[ $? != 0 ]] && echo "Error: concatène ne fait pas."
