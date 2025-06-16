pipeline{
    // triggers{
        // pollSCM('* * * * *')
    // }
     agent any
    stages{
        stage('checkout'){
            steps{
                // sh 'which sonar-scanner'
                echo "cat"
                git url: 'https://github.com/s27297/CI_CD_lab13', branch: "main"
            }
        }
        stage("kompilacja"){
            steps{
                sh 'ls -la'
               sh ' g++ main.cpp funkcje.cpp -o program'
               sh './program'
            }

        }

         stage('testy z pokryciem') {
            steps {
                echo "🧪 Kompilacja testów z pokryciem i uruchomienie"
                sh '''
                # Kompilacja testów z pokryciem kodu
                g++ -fprofile-arcs -ftest-coverage -O0 -g -o testyy main.cpp funkcje.cpp

                # Uruchomienie testów (generuje .gcda)
                ./testyy

                # Pokazuje wygenerowane pliki
                ls -la
                # Raport pokrycia
                gcov -b -o . testyy-funkcje.cpp
                '''
            }
        }

        stage('cppcheck') {
            steps {
                echo "🔍 Analiza cppcheck do XML"
                sh '''
               cppcheck --enable=all --inconclusive --xml --xml-version=2 -I/usr/include -I/usr/local/include *.cpp *.hpp 2> cppcheck-result.xml

                ls -la
                '''
               sh' gcovr -r . --sonarqube  coverage.xml '

                archiveArtifacts artifacts: "cppcheck-result.xml", fingerprint: true
                archiveArtifacts artifacts: "coverage.xml", fingerprint: true
            }
        }
        stage('SonarQube Analysis') {
            steps {
                sh 'cat coverage.xml'
                withSonarQubeEnv("SonarQube")
                
                {
                 sh '''
            sonar-scanner \
              -Dsonar.token=$SONAR_AUTH_TOKEN \
              -Dsonar.host.url=http://sonarqube-lab-13:9000 \
              -Dsonar.sources=. \
              -Dsonar.coverageReportPaths=coverage.xml \
              -Dsonar.cfamily.build-wrapper-output=bw-output
            '''

                }
               
            }
        }
    
    
        
     

    }
}



//    stage('SonarQube'){

//             steps{
//                 withSonarQubeEnv("${SONARQUBE_IN_JENKINS}")
//                 {
//                     echo "sonarqube"
//                     // sh 'npx sonar-scanner -Dsonar.token=$SONAR_AUTH_TOKEN  -Dsonar.host.url=http://sonarqube:9000 -Dsonar.sources=.'

//                 }
//             }
//         }