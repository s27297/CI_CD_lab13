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
               sh' g++ main.cpp -o program'
               sh './program'
            }

        }
        stage('parallel'){
            parallel{

                stage('Testing'){
                    steps{
                        script{
                            sh '''
                            g++ tests.cpp main.cpp -o testy
                            ./testy
                            '''
                        }
                    }
                }
                stage('Coverage'){
                    steps{
                        script{
                             sh 'cat package.json'
                            sh 'npm run coverage'
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