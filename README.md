# Projet_Ranking_2022
Projet de Methode de Ranking - sujet 3

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

## Documentation
```bash
make doc
```
Génère la documentation du programme. L'ensemble des fichiers sources est documenté. La documentation est générée dans le dossier doc. Pour y accéder, il suffit d'ouvrir le fichier doc/html/index.html dans un navigateur web.
