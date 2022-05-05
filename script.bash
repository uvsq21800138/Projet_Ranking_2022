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
_zero=0
_staticRatio=0.2
_staticAlpha=0.8
_nombreEssais=5
_nbGraphes=6
_intervalle=1
_fifty=50
_end=96
_hundred=100

########################################################## Lancement des études

################################## wb-cs-stanford ##################################
_nom=wb-cs-stanford
_id=1

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

################################## Stanford ##################################
_nom=Stanford
_id=2

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

################################## Stanford_BerkeleyV2 ##################################
_nom=Stanford_BerkeleyV2
_id=3

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

################################## in-2004v2 ##################################
_nom=in-2004v2
_id=4

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

################################## wb-edu ##################################
_nom=wb-edu
_id=5

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

################################## wikipedia-20051105V2 ##################################
_nom=wikipedia-20051105V2
_id=6

printf "/// Etude de %s (%s/%s) ///\n" ${_nom} ${_id} ${_nbGraphes}
printf "Nombre d'itérations avant convergence de chaque algorithme selon le ratio de sommets détruits\n"
for ((c=${_zero}; c < ${_fifty}; c=c + ${_intervalle}))
do
_ratio=$(bc -l <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_ratio.data ${_nombreEssais} 0${_ratio} ${_staticAlpha}
progressBar ${c} ${_fifty}
done

printf "Nombre d'itérations avant convergence de chaque algorithme selon alpha\n"
for ((c=${_fifty}; c < ${_end}; c=c + ${_intervalle}))
do
_alpha=$(bc <<< "scale=2; ${c}/${_hundred}")
./ranking_release data/${_nom}.txt datastudy/${_nom}_alpha.data ${_nombreEssais} ${_staticRatio} 0${_alpha}
progressBar $(((${c} - 50) * 2)) ${_end}
done

########################################################## Génération des graphiques
printf "Génération des graphiques en cours...\n"
R CMD BATCH study.R