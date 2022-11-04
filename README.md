<h1 align ="center">simple_shell</h1><br>
<p align ="center">
    <img width="400" height="400" src="https://miro.medium.com/max/720/1*2DeyDPxAICKbpV9Iyo_EHQ.jpeg">
</p>

------------



## Description

This repository contains the files to simulate a basic **Unix Shell** with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell.

This simple shell is a Shell interface written in C programming language that gives to the user a prompt *Hell_Shell>> *, after it accepts, it executes a user inputted command in a separate process called child process.

## This shell provides the following features:

* This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when user push *ENTER* key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, *Hell shell* will end and returns the status 0.
* When the user enters exit *[status]*, *Hell Shell* will end and returns the inputted status, where *status* is a value from 0 to 255.
* The user could stop the program using *Ctrl+D* (end of file).
* The shell handles the command lines with arguments and pathways.
* The program does not quit when the user imputs ^C (Ctrl+C).
* The program prints the current enviroment when the user types *env*.
* This program executes the most common shell commands as *ls*, *grep*, *find*, *pwd*, *rm*, *cp*, *mv*, *exit*, *env*, *history*, etc... with arguments.
* If an executable cannot be found, It prints an error message and displays the prompt again.
* This Shell supports commentaries using *#*,
* The *Hell Shell* does NOT support wildcard characters such as ls \*.dat in parameters (or commands).
* This shell does NOT support pipes *|*, shell logical operators as *&& or ||*, neither commands separator *;*.

## Authors:

- *Kelvin Maccarthy* - [@Captncarty](https://github.com/Captncarty)
- *Kelly Oteri* - [@kayzspace29](https://github.com/kayzspace29)
