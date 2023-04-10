FROM alpine:edge
RUN apk add --no-cache -X https://dl-cdn.alpinelinux.org/alpine/edge/testing \
    gcc-arm-none-eabi cpputest lcov cpplint
ENV PICO_SDK_PATH /pico-sdk
COPY pico-sdk ${PICO_SDK_PATH}
LABEL 6-player-clock.name="6 Player Clock build environment" \
    6-player-clock.description="Dockerized build environment for using with GitHub Actions"
