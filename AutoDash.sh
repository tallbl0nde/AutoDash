#!/bin/bash
# Helper script for compiling/installing/updating AutoDash.

### COMPILE ###
compile() {
    # Compile libraries first
    echo Compiling libraries...

    # Then modules
    echo Compiling modules...
    for module in ./modules/*/; do
        pushd $module > /dev/null
        ./build.sh
        popd > /dev/null
    done

    # Then AutoDash itself
    echo Compiling AutoDash...
    mkdir -p build
    pushd ./build > /dev/null
    cmake ..
    make -j$(nproc)
    popd > /dev/null
}

### HELP ###
help() {
    # TODO: Implement properly
    echo ----- AutoDash.sh -----
    echo - compile
    echo - help
    echo - install
}

### INSTALL ###
install() {
    echo TODO: Implement
}

# Fetch first parameter and invoke appropriate function
case $1 in
    "compile")
        compile;;
    "install")
        install;;
    *)
        help;;
esac