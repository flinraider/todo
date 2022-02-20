#!/bin/bash

mkdir -p /usr/share/doc/qtodo
cp icons/todo.db /usr/share/doc/qtodo/
cp icons/Apply.png /usr/share/pixmaps/todo-apply.png
cp icons/Add.png /usr/share/pixmaps/todo-add.png
cp icons/close.png /usr/share/pixmaps/todo-close.png
cp icons/info.png /usr/share/pixmaps/todo-info.png
cp icons/logo.png /usr/share/pixmaps/todo-logo.png
cp icons/console.png /usr/share/pixmaps/todo-console.png
chmod 777 /usr/share/pixmaps/todo-*

echo "FIM"



