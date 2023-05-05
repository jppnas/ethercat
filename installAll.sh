#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit 1
fi

if [ $# -ne 2 ]; then
    echo "Need arguments: 1) NIC name for ecat, 2) used driver ie. igb or e1000e"
    exit 1
fi

nic=$1
driver=$2

make all modules
make modules_install install
depmod

echo KERNEL==\"EtherCAT[0-9]*\", MODE=\"0777\" | tee -a /etc/udev/rules.d/99-EtherCAT.rules

sed -i 's/MASTER0_DEVICE=""/MASTER0_DEVICE="$nic"/g' /etc/ethercat.conf
sed -i 's/DEVICE_MODULES==""/DEVICE_MODULES=="$driver"/g' /etc/ethercat.conf
