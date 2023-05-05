#!/bin/bash

./bootstrap
./configure --enable-igb --enable-e1000e --disable-8139too --prefix=/opt/etherlab --sysconfdir=/etc
make
make all modules
