FROM alpine:latest

ARG PYTHON_VERSION=3.9
ARG PROJECT_NAME=genetic-algorithm
ARG BRANCH_NAME=multiprocess

RUN apk add htop
RUN apk add --no-cache python3=~${PYTHON_VERSION} py3-pip
RUN pip3 install matplotlib
RUN apk add git
RUN apk add build-base
WORKDIR /home/
RUN git clone https://github.com/yasin6606/${PROJECT_NAME}.git
WORKDIR /home/${PROJECT_NAME}
RUN git checkout ${BRANCH_NAME}
#RUN gcc main.c -o runner
#ENTRYPOINT ./runner