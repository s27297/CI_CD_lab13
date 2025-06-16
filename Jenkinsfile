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
               sh' g++ main.cpp funkcje.cpp -o program'
               sh './program'
            }

        }

         stage('testy z pokryciem') {
            steps {
                echo "🧪 Kompilacja testów z pokryciem i uruchomienie"
                sh '''
                # Kompilacja testów z pokryciem kodu
                g++ -fprofile-arcs -ftest-coverage -O0 tests.cpp funkcje.cpp -o testy

                # Uruchomienie testów (generuje .gcda)
                ./testy

                # Pokazuje wygenerowane pliki
                ls -la

                # Raport pokrycia
                gcov -b -o . testy-funkcje.cpp
                '''
                sh 'ls -la'
            }
        }

        stage('cppcheck') {
            steps {
                echo "🔍 Analiza cppcheck do XML"
                sh '''
                cppcheck --enable=all --inconclusive --xml --xml-version=2 *.cpp *.hpp 2> cppcheck-result.xml
                '''
            }
        }
        stage('SonarQube Analysis') {
            steps {
                withSonarQubeEnv("SonarQube")
                
                {
                 sh 'sonar-scanner -Dsonar.token=$SONAR_AUTH_TOKEN  -Dsonar.host.url=http://sonarqube:9000 -Dsonar.sources=.'

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