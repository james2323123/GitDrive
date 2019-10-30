#!/bin/sh
cd output
filenames=`ls -l | awk '{print $9}'`
for filename in ${filenames} ; do
	
	echo -n  "${filename} : "
	cat ${filename}

done
