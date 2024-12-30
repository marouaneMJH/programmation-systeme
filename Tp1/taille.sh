#!/bin/bash


# afficher les droit d'accès et la taille
ls -la $1 | cut -d ' ' -f 1,5
