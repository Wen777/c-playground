#!/usr/bin/env bash

echo "-------Check Environment------------"

node_path=$(which node)
node_site="https://nodejs.org/en/"

if [ "x$node_path" == "x" ]
then
    echo "*************************************"
    echo "you do not have nodejs"
    echo "please install nodejs by the following command or visit $node_site"
    echo "sudo apt-get install nodejs"
    echo "*************************************"
else
    echo "You have installed nodejs";
fi;

ERLANG_PATH=$(which erl)
ERLANG_SITE="https://www.erlang.org/"

if [ "X$ERLANG_PATH" == "X" ]
then
    echo "*************************************"
    echo "you do not have erlang"
    echo "please install erlang by the following command or visit $ERLANG_SITE"
    echo "sudo apt-get install erlang"
    echo "*************************************"
else
    echo "You have installed erlang";
fi;

PYTHON3_PATH=$(which python3)
PYTHON3_SITE="https://www.python.org/"

if [ "X$PYTHON3_PATH" == "X" ]
then
    echo "*************************************"
    echo "you do not have Python 3"
    echo "please install erlang by the following command or visit $PYTHON3_SITE"
    echo "sudo apt-get install Python 3"
    echo "*************************************"
else
    echo "You have installed Python 3";
fi;

echo "---------------------------------"
echo
echo