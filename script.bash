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
make clean
make
mkdir datastudy

########################################################## Variables
_intervalle=3
_end=96
_staticAlpha=0.6
_staticRatio=0.3
_nombreEssais=1

########################################################## Lancement des études

################################## Stanford_BerkeleyV2 ##################################
_nom=Stanford_BerkeleyV2
_id=3
_hundred=100

printf "/// Etude de %s (%s/6) ///\n" ${_nom} ${_id}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c = ${_intervalle}; c < ${_end}; c=c+${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_end}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c = ${_intervalle}; c < ${_end}; c=c+${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} 0${_staticRatio} ${_alpha}
progressBar ${c} ${_end}
done


printf "Génération des graphiques en cours...\n"
R CMD BATCH study.R
