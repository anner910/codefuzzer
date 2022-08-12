#!/bin/sh

git clone  https://gitee.com/anner910/codefuzzer.git


cd codefuzzer

mkdir build

cd build

cmake ..

make

echo "cp libcodefuzzer.a" 

cp libcodefuzzer.a ../../

echo "cp codefuzzer.h" 

cp ../codefuzzer/codefuzzer.h ../../

cd ../../

rm -rf codefuzzer/