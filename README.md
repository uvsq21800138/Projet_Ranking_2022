# Projet_Ranking_2022
Projet de Methode de Ranking - Sujet 3

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
Est un exemple de son utilisation.

Remarque : Il faut ajouter le dossier _data/_ au dossier de travail avec les bases de données pour pouvoir les utiliser.

Pour utiliser les options de débogage, il suffit de faire :
```bash
make [ run-gdb | run-valgrind ]
```

## Documentation
```bash
make doc
```
Génère la documentation du programme. L'ensemble des fichiers sources est documenté. La documentation est générée dans le dossier doc. Pour y accéder, il suffit d'ouvrir le fichier doc/doxygen/html/index.html dans un navigateur web.

## Etude
```bash
./make_study.sh
```

Génère les graphiques de l'étude demandée d'après le sujet en exécutant le programme pour une série de paramètres prévus. Exécuter cette commande peut prendre beaucoup de temps.
