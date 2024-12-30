#!/bin/bash




BD_AGENDA="./output/bd_agenda_telephonique.txt"
# un fichier comme une bade de donnes << output bd_agenda.txt
function ajouter_fiche()
{
    read -p "Entrez le nom:" nom
    read -p "Entrez le numéro de téléphone: " phone
    if [[ $phone != +([0-9]) || ${#phone} < 10 ]]
    then
        echo "$phone n'est pas valide. Le numéro doit contenir uniquement des chiffres et avoir au moins 10 chiffres"
    else
        echo "$nom,$phone" >> $BD_AGENDA
        echo "$nom est ajouté."
    fi
}

function recherche_fiche()
{
    read -p "Entrez le nom du fiche:" nom
    echo "résultat de recherche: "
    grep $nom $BD_AGENDA
}

function detruire_fiche() {
    read -p "Entrez le nom du contact à supprimer : " nom
    if grep -iq "$nom" $BD_AGENDA
    then
        grep -iv "$nom" $BD_AGENDA > temp && mv temp $BD_AGENDA
        echo "Les fiches contenant '$nom' ont été supprimées."
    else
        echo "Aucun contact trouvé avec le nom '$nom'."
    fi
}


echo "** Agenda téléphonique**"
sleep 0.3
echo -e "\nchoisi une fonction:"
echo " 1. Ajouter une nouvelle fiche "
echo " 2. Rechercher une fiche (avec une partie du nom) "
echo " 3. Détruire une fiche  "
echo " 4. Modifier une fiche  "
echo " 5. Lister l’annuaire "
echo -e " 6. Fin \n"


while read rep 
do 
    clear # pour effacer l'écran

    case "$rep" in
        1) ajouter_fiche ;;
        2) recherche_fiche ;;
        3) detruire_fiche ;;
        5) cat $BD_AGENDA ;;
        6) echo "quitter le programme " && exit 0 ;;
        
        *) echo "le nombre n'est pas valide, entrez une nombre entre 1 et 6" ;;
    esac
    echo -e  "\nchoisi une fonction:"
    echo " 1. Ajouter une nouvelle fiche "
    echo " 2. Rechercher une fiche (avec une partie du nom) "
    echo " 3. Détruire une fiche  "
    echo " 4. Modifier une fiche  "
    echo " 5. Lister l’annuaire "
    echo -e " 6. Fin\n "
done
