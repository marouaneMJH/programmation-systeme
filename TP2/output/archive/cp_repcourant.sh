#!/bin/bash

mkdir -p output/archive
pwd
for i in $( echo *)
do
    if [[ -f $i ]]
    then
        cat  $i >  output/archive/$i
    fi

done 
