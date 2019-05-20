#!/bin/bash
echo "Digite seu nome: "
read nome
if [ -z $nome ]
then
    echo "Você não digitou seu nome!"
else
    echo "Olá, $nome"
fi