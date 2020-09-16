#!/bin/bash
file="integer.txt"	
lock="${file}.lock"	
re='[+-]?[0-9]+$'	
num=0
ln -s $file $lock
while read line
do
	for word in $line
	do
		if [[ $word =~ $re ]]
		then
			num=$word
		fi
	done
done < $file
((num++))
echo $num >> $file
rm $lock
