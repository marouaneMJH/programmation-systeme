#!/bin/bash


# compile all the c files in the current directory 
# and run the executable file
# if the compilation is successful
if [[ $# -eq 0 ]]
then
    echo "this command requires at least one argument"
    exit 1
fi

gcc -o main $* && ./main