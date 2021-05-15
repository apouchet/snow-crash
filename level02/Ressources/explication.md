# Explication

En arrivant sur le level02 on trouve le fichier `level02.pcap`  
Faire un cat dessus n'est pas tres utlise, en cherchant un peu j'ai vu qu'on pouvait lire les fichier `.pcap` avec `tcpdump -ttttnnr level02.pcap` mais ca n'est pas encore assez.

```
level02@SnowCrash:~$ tcpdump -ttttnnr level02.pcap
reading from file level02.pcap, link-type EN10MB (Ethernet)
2011-07-20 07:23:12.267566 IP 59.233.235.218.39247 > 59.233.235.223.12121: Flags [S], seq 2635601089, win 14600, options [mss 1460,sackOK,TS val 18592800 ecr 0,nop,wscale 7], length 0
2011-07-20 07:23:12.267694 IP 59.233.235.223.12121 > 59.233.235.218.39247: Flags [S.], seq 3131636289, ack 2635601090, win 14480, options [mss 1460,sackOK,TS val 46280417 ecr 18592800,nop,wscale 5], length 0
2011-07-20 07:23:12.267956 IP 59.233.235.218.39247 > 59.233.235.223.12121: Flags [.], ack 1, win 115, options [nop,nop,TS val 18592800 ecr 46280417], length 0
...
```

En continuant à chercher je tombe sur [ce poste](https://serverfault.com/questions/38626/how-can-i-read-pcap-files-in-a-friendly-format) qui conseil d'utiliser :  
`tcpick -C -yP -r tcp_dump.pcap`
- `-C` pour la couleur
- `-y` pour a afficher les données des packets TCP
- `-P` pour remplacer les caracteres invisibles par un '.'
- `-U` pour remplacer les caracteres invisibles par les hexa (il va ramplacer le `-P`)
- `-r` pour lire un fichier

Malheuresement `tcpick` n'est pas installé et nous n'avont pas les droits pour l'installer, on va donc telecharger le fichier sur notre machine  et ce donner les droits:

```
apouchet$ scp -P 4242 level02@192.168.253.129:/home/user/level02/level02.pcap .
apouchet$ chmod 777 level02.cp
apouchet$ tcpick -yU -r level02.pcap
Starting tcpick 0.2.1 at 2021-05-15 20:33 CEST
Timeout for connections is 600
...
...
Password: 
f
t
_
w
a
n
d
r
<7f>
<7f>
<7f>
N
D
R
e
l
<7f>
L
0
L

<00>
<01>
<00>
...
```

on obtient `ft_wandr<7f><7f><7f>NDRel<7f>L0L`, en ascii `<7f>` indique `DEL` on a donc :  
`ft_wa`~~`ndr`~~`NDRe`~~`l`~~`L0L` = `ft_waNDReL0L`

On va donc pouvoir récupérer le flag

```
level02@SnowCrash:~$ su flag02
Password: 
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```
