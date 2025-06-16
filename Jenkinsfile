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
    }
}