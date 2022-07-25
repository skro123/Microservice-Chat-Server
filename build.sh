#!/bin/bash

set -e

cd `pwd`/Client &&
    sh build.sh
cd ..

cd `pwd`/FriendService &&
    sh build.sh
cd ..

cd `pwd`/GroupService &&
    sh build.sh
cd ..

cd `pwd`/UserServer &&
    sh build.sh
cd ..