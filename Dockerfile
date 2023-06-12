FROM alpine:latest
RUN apk add htop
RUN apk add git
RUN apk add build-base
WORKDIR /home/
RUN git clone https://github.com/yasin6606/genetic-algorithm.git
WORKDIR /home/genetic-algorithm
RUN gcc main.c -o runner
ENTRYPOINT ./runner