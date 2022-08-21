# Projet de Méthode de Ranking - Sujet 3

## Introduction

Ce projet de première année de Master informatique à l'Université de Paris-Saclay a pour objectif de réaliser une étude sur une amélioration de l'algorithme [PageRank](https://en.wikipedia.org/wiki/PageRank) de Google, encadré par le professeur Jean-Michel Fourneau. Ce document détaille l'utilisation du programme, cependant si seul les résultats vous intéressent, ils sont accessibles en français [ici](doc/compte_rendu.pdf).

## Compilation
```bash
make all
```
Génère le binaire du programme en deux exemplaires :
- ranking_debug
- ranking_release

Le premier est uniquement à des fins de débogage, le second est à des fins de production.

## Exécution
```bash
./ranking_release
```
Affiche l'aide du programme.

```bash
make run
```
Est un exemple de son utilisation (nécessite d'avoir décompressé les graphes dans le dossier *data*).

Pour utiliser les options de débogage, il suffit de faire :
```bash
make [ run-gdb | run-valgrind ]
```

## Documentation
```bash
make doc
```
Génère la documentation du programme. La documentation est générée dans le dossier *doc* sous deux formats : LaTeX et web. Pour accéder à la version web en local, il suffit d'ouvrir le fichier [doc/doxygen/html/index.html]() dans un navigateur web.

- 💡Un PDF est déjà disponible [ici](doc/documentation.pdf) si vous ne disposez pas des dépendances nécessaires pour générer la documentation.

## Etude
```bash
./make_study.sh
```

Génère les graphiques de l'étude demandée d'après le sujet en exécutant le programme pour une série de paramètres prévus. Exécuter cette commande peut prendre beaucoup de temps.

- ⚠️ Au moins 2 Go sont requis pour décompresser les graphes !
