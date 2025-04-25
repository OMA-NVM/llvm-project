# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.241.1/containers/ubuntu/.devcontainer/base.Dockerfile

# [Choice] Ubuntu version (use ubuntu-22.04 or ubuntu-18.04 on local arm64/Apple Silicon): ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="jammy"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

SHELL ["/bin/bash", "-c"]

# [Optional] Uncomment this section to install additional OS packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
        && apt-get -y install --no-install-recommends --fix-missing \
        icecc icecream-sundae

RUN echo "set completion-ignore-case on" >> /etc/inputrc

RUN cd /opt ; \
        wget -nv \
        https://packages.gurobi.com/12.0/gurobi12.0.1_armlinux64.tar.gz ; \
        tar xfz *.tar.gz ; \
        mv gurobi1201 gurobi ;
ENV GUROBI_HOME="/opt/gurobi/armlinux64"
ENV PATH="${PATH}:${GUROBI_HOME}/bin"
ENV LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${GUROBI_HOME}/lib"
ENV CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:${GUROBI_HOME}/include"
ENV GRB_LICENSE_FILE=/workspaces/llvmta/dependencies/gurobi.lic
#RUN ln -s $GUROBI_HOME/lib/libgurobi95.so /usr/lib/libgurobi.so

#Seting up icecc (icecream) distributed compiler.
#IceCream uses Ports: TCP: 10245 8765 8766 and for UDP 8765
EXPOSE 10245 8766 8765/TCP 8765/UDP
