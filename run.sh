#!/bin/sh

name=$1
root -b -q ${name} <<EOF 1>test.log 2>&1

EOF