#!/bin/bash

echo "saisir des lignes, pour arrêter tapez CRTL+d:"
# garder les ligne  saisi dans  "lignes " 
cat > output/lignes
# afficher le nombre des lignes saisi
echo "le nommbre des ligne est $(wc -l  output/lignes)"
