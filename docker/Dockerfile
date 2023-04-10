FROM alpine:edge
ENV PICO_SDK_PATH /pico-sdk
COPY pico-sdk ${PICO_SDK_PATH}
RUN apk add --no-cache -X https://dl-cdn.alpinelinux.org/alpine/edge/testing \
    cmake ninja-build g++-arm-none-eabi gcc-arm-none-eabi gcc g++ cpputest lcov cpplint
LABEL 6-player-clock.name="6 Player Clock build environment" \
    6-player-clock.description="Dockerized build environment for using with GitHub Actions" \
    org.opencontainers.image.source="https://github.com/jisbert/6-player-clock"
