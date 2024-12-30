#!/bin/bash




echo "Saisir des lignes, pour arrêter, tapez Ctrl+D:"
# garder les ligne  saisi dans  "lignes " 
cat > output/lignes
# afficher le nombre des lignes saisi
echo "le nombre des ligne est $(wc -l  output/lignes)"


# détruire output/lignes
rm output/lignes &> /dev/null 