#!/bin/bash
file1="in.txt"
file2="out.txt"

lines=`cat $file1 | wc -l`

for ((i=1;i<=$lines;i++))
do
  line1=`awk 'NR=="'$i'"{print $0}' $file1`
  line2=`awk 'NR=="'$i'"{print $0}' $file2`

  if [[ $line1 == $line2 ]]
  then
    echo "line $i equal"
  done
done

