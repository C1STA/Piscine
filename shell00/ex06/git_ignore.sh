#!/bin/bash

git status --ignored -s | grep '!!' | cut -f2 -d ' '
