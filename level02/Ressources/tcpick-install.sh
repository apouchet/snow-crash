#!/bin/bash
mkdir temp
cd temp
wget http://downloads.sourceforge.net/project/tcpick/tcpick/0.2.1/tcpick-0.2.1.tar.gz
tar zxvf tcpick-0.2.1.tar.gz
cd tcpick-0.2.1
CFLAGS="-m32" ./configure
echo "char *lookup();" >> src/lookup.h
make
sudo make install