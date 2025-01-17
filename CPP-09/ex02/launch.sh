#!/bin/bash

# Générer 10000 nombres aléatoires entre 1 et 100 et les stocker dans une variable
numbers=$(shuf -i 1-100000 -n 3000 | tr "\n" " ")

# Appeler votre programme avec les nombres générés comme argument
./PmergeMe "$numbers"
