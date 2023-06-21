cls

set "projectName=genetic-algorithm"
set "chartDir=genetic_result"
set "HOME=%userprofile%"

docker build -t %projectName% .
docker run -itd --rm --name %projectName% -e USER_HOME=%HOME% -v %HOME%/Desktop/%chartDir%:/home/%projectName%/%chartDir% %projectName%
docker exec -it %projectName% /bin/sh
pause