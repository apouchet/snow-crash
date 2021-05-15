# Explication
Ce coup-ci `find / -user flag01` ne donne rien  
On va donc essayer d'acceder à des fichier important comme `/etc/shadow`, `/etc/passwd` ...

```
level01@SnowCrash:~$ cat /etc/passwd
root:x:0:0:root:/root:/bin/bash
...
...
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
...
```

A la ligne concernant flag01 on voit qu'il n'y a pas de `x` mais `42hDRfypTqqnw`  
(le `x` indique que le mot de passe est cyprter dans `/etc/shadow`)

En cherchant un peu sur internet comment decoder `/etc/passwd` je suis tombé sur ce [forum](https://askubuntu.com/questions/383057/how-to-decode-the-hash-password-in-etc-shadow) qui conseil d'utiliser `john the ripper` qu'on peu installer avec `sudo apt install john` (le fichier sur level01 s'appel john)

Sur notre machine :
```
apouchet$ echo "flag01:42hDRfypTqqnw" > level01.passwd
apouchet$ john level01.passwd
```

En quelques seconde john trouve le mot de passe, on peu l'afficher clairement :
```
apouchet$ john --show level02.passwd 
flag01:abcdefg
```

On peu donc ce connecter a `flag01` et récupérer le flag

```
level01@SnowCrash:~$ su flag01
Password:
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```
