#!/bin/bash

echo "Enter : "
read num

case $num in
    1)
        echo "You choose One"
        ;;
    2)
        echo "You choose Two"
        ;;
    *)
        echo "Invalid !"
        ;;
esac