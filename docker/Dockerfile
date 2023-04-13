# Pico SDK Docker image
# ---------------------
#
# This image provides a dockerized environment for building C/C++ PICO SDK based applications.
# It is target to be used in GitHub Actions.
#
# Requisites
# ----------
# 
# 1. Personal access token (classic)
# https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token
#
# How to update
# -------------
#
# Based on https://docs.github.com/en/packages/working-with-a-github-packages-registry/working-with-the-container-registry
#
# 1. Build the image
# $ docker build -t ghcr.io/user/pico-sdk:1.5.0 -t ghcr.io/user/pico-sdk:latest docker
# 2. Login
# $ export CR_PAT=YOUR_TOKEN; echo $CR_PAT | docker login ghcr.io -u USERNAME --password-stdin
# 3. Push the image
# $ docker push -a ghcr.io/user/pico-sdk:latest
# 4. Allow actions to pull the container
# https://docs.github.com/en/packages/learn-github-packages/configuring-a-packages-access-control-and-visibility
#
# After performing these steps the personal token can be deleted

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
    cpputest \
    g++ \
    g++-arm-none-eabi \
    lcov \
    samurai
