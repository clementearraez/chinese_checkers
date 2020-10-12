pipeline {
    agent any

    stages {
        stage('Test') {
            steps {
                /* `make check` returns non-zero on test failures,
                * using `true` to allow the Pipeline to continue nonetheless
                */
                echo 'Do the testing bro'
                echo 'And say hello'
                sh 'doit' 
            }
        }
    }
}
