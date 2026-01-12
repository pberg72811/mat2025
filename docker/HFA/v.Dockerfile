FROM python:3.12-bookworm AS dev-base

# Install system dependencies
RUN apt-get update -y && \
    apt-get install -y --no-install-recommends \
    apt-utils \
    ca-certificates \
    curl \
    dumb-init \
    git \
    htop \
    ssh \
    nano \
    openssh-client \
    patch \
    procps \
    rsync \
    sudo \
    vim \
    libsecret-1-0 \
    x11-apps \
    libgl1 \
    libglib2.0-0 \
    libegl1 \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install Miniconda
ENV CONDA_DIR=/opt/conda
RUN curl -sSL https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -o /tmp/miniconda.sh && \
    bash /tmp/miniconda.sh -b -p $CONDA_DIR && \
    rm /tmp/miniconda.sh

ENV PATH=$CONDA_DIR/bin:$PATH

# Copy your Conda-style requirements.txt
COPY requirements.txt /tmp/requirements.txt

# Explicitly accept Anaconda Terms of Service for required channels, then create environment
RUN conda tos accept --override-channels --channel https://repo.anaconda.com/pkgs/main && \
    conda tos accept --override-channels --channel https://repo.anaconda.com/pkgs/r && \
    conda create -n myenv --file /tmp/requirements.txt -y -c conda-forge

# Create a test_output directory, video_output, and csv_output
# RUN mkdir -p /opt/project/test_output/video_output /opt/project/test_output/csv_output

# Use bash as default shell and activate environment by default
SHELL ["/bin/bash", "--login", "-c"]
ENV PATH /opt/conda/envs/myenv/bin:$PATH

# Optional: User and workdir setup
#ARG USER_ID=1000
#ARG GROUP_ID=1000
#ARG user=euser
#RUN groupadd "$user" --non-unique -g "$GROUP_ID"
#RUN useradd "$user" --non-unique -m -u "$USER_ID" -g "$GROUP_ID"
#RUN chown $user:$user /home/$user
#RUN echo "$user ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# USER $user
WORKDIR /opt/project

ENV QT_QPA_PLATFORM=offscreen

CMD ["bash", "-c", "source /opt/conda/etc/profile.d/conda.sh && conda activate myenv && exec bash", "conda activate myenv", "python3 -m pip install -e ."]
