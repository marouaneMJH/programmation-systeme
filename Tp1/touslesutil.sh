#!/bin/bash







cat /etc/passwd | grep home | while read user rest  
do
    nom=${user%%:*}
    var=${user##*:x:}
    echo  -e "nom: $nom \t id: ${var%%:*}"
done





