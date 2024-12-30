#!/bin/bash


# répéter 6 fois
for i in {1..6} 
do
    # afficher une nombre entre 1 et 49
    echo $(( ( $RANDOM % 49 )  + 1 )) 
done
