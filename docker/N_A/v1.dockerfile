FROM ubuntu:24.04

RUN apt update
RUN apt install -y ncal

RUN groupadd --gid 1000 xmidas
RUN useradd  --uid 1000 --gid 1000 -m xmidas
WORKDIR /home/xmidas
RUN chown xmidas:xmidas /home/xmidas

USER xmidas

CMD ["/bin/cal"]

# docker buildx build -t noble_attempt .
# docker image ls -a






# Use a base image
FROM ubuntu:22.04

# Create a non-root user and group (e.g., 'appuser' with UID/GID 1000)
ARG USER_UID=1000
ARG USER_GID=1000
RUN groupadd --gid $USER_GID appgroup && useradd --uid $USER_UID --gid $USER_GID -m appuser

# Set the working directory and ensure correct permissions
WORKDIR /app
COPY --chown=appuser:appgroup . /app

# Switch to the non-root user
USER appuser

# Define the command to run the application
CMD ["./myapp"]
