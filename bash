#!/bin/bash

display_menu() {
    echo "-Keychain-"
    echo
    echo "1. Run"
    echo "2. Print File Tree"
    echo "3. Build File Tree"
    echo "4. Clean File Tree"
    echo "5. Exit"
    echo
}

while true; do

    display_menu
    read -p ">> " choice

    case $choice in
    #** run
    1)
        ./keychain
        ;;
    "run")
        tree
        ;;

    #** print file tree
    2)
        tree
        ;;
    "tree")
        tree
        ;;

    #** build file tree
    3)
        make all
        ;;
    "build")
        make all
        ;;

    #** clean file tree
    4)
        make clean
        ;;
    "clean")
        make clean
        ;;

    #** exit program
    5)
        break
        ;;
    "exit")
        break
        ;;

    #** invalid input handler
    *)
        echo "Invalid option"
        ;;
    esac

    echo

done
