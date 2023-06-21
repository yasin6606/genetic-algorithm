#! /bin/bash

chmod 777 run_linux.sh

projectName=genetic-algorithm
chartDir=genetic-result

docker build -t $projectName .
docker run -itd --rm --name $projectName -e USER_HOME="${HOME}" -v "${HOME}"/Desktop/$chartDir:/home/$projectName/$chartDir $projectName
docker exec -it $projectName /bin/sh