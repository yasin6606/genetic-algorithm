FROM czentye/matplotlib-minimal:latest

ENV PROJECT_NAME=genetic-algorithm
ENV USER_HOME=$HOME
ENV CHART_DIR=genetic_result

ARG BRANCH_NAME=multiprocess

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
RUN git pull origin $BRANCH_NAME
RUN gcc main.c -lm -o runner