# Explication

On essaye d'acceder au flag00 donc on va chercher tout les fichier de l'utilisateur flag00.

```
level00@SnowCrash:~$ find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```
On peu lire les deux fichiers qui ont le meme contenu :

```
level00@SnowCrash:~$ cat /usr/sbin/john /rofs/usr/sbin/john 
cdiiddwpgswtgt
cdiiddwpgswtgt
```

"cdiiddwpgswtgt" n'est pas le mot de passe, on peu essayer de faire un rot dessus avec le programme que j'ai joins 

le programme va essayer toutes les possiblilitées si ont ne lui donne pas de valeur en argument.
```
./rot cdiiddwpgswtgt
...
rot: 10 - mnssnngzqcgdqd
rot: 11 - nottoohardhere
rot: 12 - opuuppibseifsf
...
```

Avec le rot11 on obtien "nottoohardhere" avec le quel on arrive a ce connecter a `flag00`
Et on oubli pas de lancer la commande `getflag`

```
level00@SnowCrash:~$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```
