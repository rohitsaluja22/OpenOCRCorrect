#!/bin/bash
# int-or-string.sh
a=1
#mkdir txtfiles
for i in *.txt ; do
  (cat "page-$a.txt"; echo) >> ../IEROCR;
  let a=a+1
done

