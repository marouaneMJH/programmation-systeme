#!/bin/bash


[[ $# == 0 ]] &&  echo basenom: marque de messagerie && exit 1
sufix=${1##*/}
echo ${sufix%$2}

