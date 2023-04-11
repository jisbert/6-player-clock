FROM alpine:edge AS pico-sdk
RUN apk add --no-cache git
ENV PICO_SDK_PATH=/pico-sdk
RUN git clone -b master --depth=1 https://github.com/raspberrypi/pico-sdk.git ${PICO_SDK_PATH}
RUN git -C ${PICO_SDK_PATH}/lib submodule update --init --depth=1
RUN git -C ${PICO_SDK_PATH}/lib/tinyusb submodule update --init --depth=1 hw/mcu/raspberry_pi

FROM alpine:edge AS toolchain
LABEL es.gont.name="Pico SDK 1.5.0"
LABEL es.gont.description="Dockerized environment for building C/C++ PICO SDK based applications. Targeted for GitHub Actions."
LABEL org.opencontainers.image.source="https://github.com/jisbert/6-player-clock"
ENV PICO_SDK_PATH=/pico-sdk
ENV CMAKE_GENERATOR=Ninja
COPY --from=pico-sdk /pico-sdk /pico-sdk
RUN apk add --no-cache \
    -X https://dl-cdn.alpinelinux.org/alpine/edge/testing \
    cmake \
    cpplint \
    cpputest \
    g++ \
    g++-arm-none-eabi \
    lcov \
    samurai
