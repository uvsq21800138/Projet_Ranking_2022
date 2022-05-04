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
_staticRatio=0.3
_staticAlpha=0.6
_nombreEssais=1
_start=3
_intervalle=3
_end=96
_hundred=100

########################################################## Lancement des études

################################## wb-cs-stanford ##################################
_nom=wb-cs-stanford
_id=1

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

################################## Stanford ##################################
_nom=Stanford
_id=2

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

################################## Stanford_BerkeleyV2 ##################################
_nom=Stanford_BerkeleyV2
_id=3

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

################################## in-2004v2 ##################################
_nom=in-2004v2
_id=4

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

################################## wb-edu ##################################
_nom=wb-edu
_id=5

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

################################## wikipedia-20051105V2 ##################################
_nom=wikipedia-20051105V2
_id=6

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

########################################################## Génération des graphiques
printf "Génération des graphiques en cours...\n"
R CMD BATCH study.R