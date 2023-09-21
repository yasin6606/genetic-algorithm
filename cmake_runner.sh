#! /bin/bash

clear

projectName="genetic-algorithm"
fileName="build"

if [ -d "$fileName" ]; then
	rm -rf "$fileName"
fi

mkdir "$fileName"

cd "$fileName" || return

cmake -S .. -B .

make

./"$projectName"