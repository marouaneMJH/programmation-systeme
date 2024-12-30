#!/bin/bash


[[ $# == 0 ]] &&  echo basenom: marque de messagerie && exit 1
echo ${1##*/}

