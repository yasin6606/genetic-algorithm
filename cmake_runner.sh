#! /bin/bash

clear

fileName="build"

if [ -d "$fileName" ]; then
	rm -rf "$fileName"
fi

mkdir "$fileName"

cd "$fileName" || return

cmake -S .. -B .

make