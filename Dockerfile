FROM --platform=linux/amd64 ubuntu:latest

# ENV DYLD_INSERT_LIBRARIES=./libft_malloc.so
# ENV DYLD_FORCE_FLAT_NAMESPACE=1

RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt install -y gcc make git binutils libc6-dev gdb sudo vim
RUN adduser --disabled-password --gecos '' user
RUN echo 'user ALL=(root) NOPASSWD:ALL' > /etc/sudoers.d/user

USER user
WORKDIR /home/user
