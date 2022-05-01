########################################################## Fonction ProgressBar
function progressBar
{
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done

    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")

	printf "\rProgress : [${_fill// /#}${_empty// /-}] ${_progress}%%\n"
}

########################################################## Compilation du programme et création du répertoire d'étude
make
mkdir datastudy

########################################################## Variables
_start=5
_staticAlpha=0.5
_staticRatio=0.3

########################################################## Lancement des études

### wb-cs-stanford ###
_graphe=wb-cs-stanford
_id=1
_end=100
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c+5))
do
_ratio=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.csv 1 ${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

_end=90

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c+5))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.csv 1 ${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### Stanford ###



### Stanford_BerkeleyV2 ###



### in-2004v2 ###



### wb-edu.txt ###



### wikipedia-20051105V2 ###



########################################################## Génération des graphiques
printf "Génération des graphiques en cours...\n"
R CMD BATCH study.R