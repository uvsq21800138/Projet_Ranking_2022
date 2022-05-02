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
_end=96
_staticAlpha=0.6
_staticRatio=0.3

########################################################## Lancement des études

### wb-cs-stanford ###
_graphe=wb-cs-stanford
_id=1
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### Stanford ###

_graphe=Stanford
_id=2
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### Stanford_BerkeleyV2 ###

_graphe=Stanford_BerkeleyV2
_id=3
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### in-2004v2 ###

_graphe=in-2004v2
_id=4
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### wb-edu ###

_graphe=wb-edu
_id=5
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

### wikipedia-20051105V2 ###

_graphe=wikipedia-20051105V2
_id=6
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_graphe} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_ratio.data 1 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_start}; c < ${_end}; c=c+${_start}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_graphe}.txt datastudy/${_graphe}_alpha.data 1 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done

########################################################## Génération des graphiques
printf "Génération des graphiques en cours...\n"
R CMD BATCH study.R