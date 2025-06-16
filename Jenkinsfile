pipeline{
    triggers{
        pollSCM('* * * * *')
//         githubPush()
    }
     agent any
    stages{
        stage('checkout'){
            steps{
                echo "cat"
                git url: 'https://github.com/s27297/CI_CD_lab13', branch: "main"
            }
        }
    }
}