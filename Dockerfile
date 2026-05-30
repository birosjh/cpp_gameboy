FROM gcc:13.2.0

ENV TZ="Japan"
RUN date

RUN apt update && apt -y install cmake clang-format libsdl2-dev

WORKDIR /code