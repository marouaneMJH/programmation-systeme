#!/bin/bash


if [[ $# != 1 ]]
then 
    echo "moins d'argument."
    exit 1
fi

gcc "$*" -Ipthread -o "main" &&  ./main 