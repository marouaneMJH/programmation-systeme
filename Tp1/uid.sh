#!/bin/bash


# execution de la commande id
set $(id) 

Id=$1
IFS='='
set $Id
Id=$2
IFS='('
set $Id
echo $1
