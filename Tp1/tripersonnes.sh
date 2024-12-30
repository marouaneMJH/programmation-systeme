#!/bin/bash 




cat personnes | while read nom sexe
do 
    if [[ $sexe == 'm' ]]
    then
        echo $nom >> output/garcons
    elif [[ $sexe == 'f' ]]
    then
        echo $nom >> output/filles
    fi
done


