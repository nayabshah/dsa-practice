FROM mcr.microsoft.com/devcontainers/base:ubuntu

ARG NODE_VERSION=22

# Prevent interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# --------------------------------------------------
# Basic development tools
# --------------------------------------------------
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        gcc \
        g++ \
        gdb \
        git \
        curl \
        wget \
        unzip \
        zip \
        make \
        cmake \
        pkg-config \
        ca-certificates \
        python3 \
        python3-pip \
        python3-venv \
        openjdk-21-jdk \
    && rm -rf /var/lib/apt/lists/*

# --------------------------------------------------
# Node.js
# --------------------------------------------------
RUN curl -fsSL https://deb.nodesource.com/setup_${NODE_VERSION}.x | bash - \
    && apt-get update \
    && apt-get install -y nodejs \
    && rm -rf /var/lib/apt/lists/*

# --------------------------------------------------
# Useful Python packages
# --------------------------------------------------
RUN python3 -m pip install --break-system-packages \
        ipython \
        pytest

# --------------------------------------------------
# Make Python available as "python"
# --------------------------------------------------
RUN ln -sf /usr/bin/python3 /usr/local/bin/python

# --------------------------------------------------
# Set default shell
# --------------------------------------------------
ENV SHELL=/bin/bash

WORKDIR /workspaces
