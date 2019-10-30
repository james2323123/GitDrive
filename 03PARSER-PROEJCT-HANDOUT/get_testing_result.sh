#!/bin/bash
rm output/*
noErrorFile=($(ls TEST-COMPILER02-FOR-PARSER/no-parsing-error| grep .p))
ErrorFile=($(ls TEST-COMPILER02-FOR-PARSER|grep "\.p"))

for file in ${noErrorFile[@]};do
    filename=$(echo $file|awk -F "." '{print $1}')
    ./a.out <  "TEST-COMPILER02-FOR-PARSER/no-parsing-error/"$file > output/output_$filename.txt
done


for file in ${ErrorFile[@]};do
    filename=$(echo $file|awk -F "." '{print $1}')
    ./a.out <  "TEST-COMPILER02-FOR-PARSER/"$file > output/output_$filename.txt
done

