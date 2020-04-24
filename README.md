# Appdev project 2020
This project is for I-IT-1N students to understand what procedure and what tools are needed in an application development.

### General Description of the Application

This application analyzes the first 5s of the given .wav, displaying db datagram, counting peak values an calculataling the maximum db value to send it to the pre-defined server afterwards

### Table of Content
1. Configuration instrusctions
2. Installation inscructions
3. Operating instructions
4. File manifest
5. Copyright and license
6. Contact information
7. Credits and acknowledgements

#### 1. Configuration instructions
In order to use this application, you would need gcc, php and curl-lib installed on your system. You may want to check their availibility running the following commands:

```bash
gcc --version
php --version
[ -f /usr/include/i386-linux-gnu/curl/curl.h ] && echo "OK" || echo "Curl not found"
```

#### 2. Installation instructions
Download zip-file or clone this repository:
```bash
git clone https://github.com/e1900311/appdev.git
```

#### 3. Operating instructions
Build the program:
```bash
make
```
Run the program, passing the filename as the first argument
```bash
./sound ${FILENAME}
```
or run it without arguments
```bash
./sound
```
in that case, the application would use the default filename "test.wav"

#### 4. File manifest
    README.md :     this file
    screen.c :      contains screen manipulation functions  
    screen.h :      contains screen function declaration and related constants  
    comm.c :        contains a function which send a POST-request using curl  
    comm.h :        contains declaration of senddata function  
    makefile :      contains a set of directives used by a make build automation tool  
    testcurl.c :    contains basic implementation of utilizing curl  
    testscreen.c :  contains a small program which draws text animation in the terminal, as well as certain figures and basic information about the student
    main.c  :       contains the application logic and the entry point
    sound.php :     server-side component. handles POST-requests, saves data to file
    
#### 5. Copyright and licence information
This application follows GPLv2 license.
