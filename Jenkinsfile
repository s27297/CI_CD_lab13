pipeline{
    triggers{
        pollSCM('* * * * *')
    }
     agent any
    stages{
        stage('checkout'){
            steps{
                echo "cat"
                git url: 'https://github.com/s27297/CI_CD_lab13', branch: "main"
            }
        }
        stage("kompilacja"){
            steps{
                sh 'ls -la'
               sh' g++ main.cpp funkcje.cpp -o program'
               sh './program'
            }

        }
        stage('parallel'){
            parallel{

                stage('Testing'){
                    steps{
                        script{
                            sh '''
                            g++ tests.cpp funkcje.cpp -o testy
                            ./testy
                            '''
                        }
                    }
                }
                stage('Coverage'){
                    steps{
                        script{
                            sh '''g++ -fprofile-arcs -ftest-coverage -O0 tests.cpp funkcje.cpp -o testy
                            ls -la
                            gcov -b funkcje.cpp'''
                        }

                    }
                }
            }
        }
        stage('SonarQube'){

            steps{
                withSonarQubeEnv("${SONARQUBE_IN_JENKINS}")
                {
                    echo "sonarqube"
                    // sh 'npx sonar-scanner -Dsonar.token=$SONAR_AUTH_TOKEN  -Dsonar.host.url=http://sonarqube:9000 -Dsonar.sources=.'

                }
            }
        }

    }
}