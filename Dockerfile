FROM debian:10

RUN apt-get update -y
RUN apt-get install -y build-essential make
COPY . /abstractvm
WORKDIR /abstractvm
ENV LD_LIBRARY_PATH .
RUN make
CMD bash
