FROM czentye/matplotlib-minimal:latest

ARG PROJECT_NAME=genetic-algorithm
ARG BRANCH_NAME=multiprocess

ENV USER_HOME=$HOME
ENV CHART_DIR=genetic_result

RUN apk add htop
RUN apk add git
RUN apk add build-base
RUN apk add vim
RUN apk add --no-cache openssh
RUN apk add feh
RUN apk add xauth
WORKDIR /home/
RUN git clone https://github.com/yasin6606/${PROJECT_NAME}.git
WORKDIR /home/${PROJECT_NAME}
RUN git checkout ${BRANCH_NAME}
RUN gcc main.c -o runner
#ENTRYPOINT ./runner