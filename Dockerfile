FROM jenkins/jenkins:lts

# Przełącz się na root, żeby mieć uprawnienia do instalacji pakietów
USER root

# Zainstaluj wymagane pakiety
RUN apt-get update && apt-get install -y \
    build-essential \
    docker.io \
    git \
    curl \
    unzip \
    sudo \
    cppcheck \
    openjdk-17-jre \
    && apt-get clean

# Zainstaluj sonar-scanner ręcznie (bo `apt install sonar-scanner` nie działa domyślnie!)
RUN curl -sSL https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-5.0.1.3006-linux.zip \
    -o sonar-scanner.zip && \
    unzip sonar-scanner.zip && \
    mv sonar-scanner-* /opt/sonar-scanner && \
    ln -s /opt/sonar-scanner/bin/sonar-scanner /usr/local/bin/sonar-scanner && \
    rm sonar-scanner.zip

# Dodaj jenkins do grupy docker (aby mógł korzystać z dockera w środku kontenera)
RUN usermod -aG docker jenkins

# Przełącz się z powrotem na użytkownika jenkins
USER jenkins
