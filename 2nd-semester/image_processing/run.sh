#!/bin/sh
# rm a.out abraham_lake_gray.bmp
clang image_quard_size_and_flip.c
# ./a.out abraham_lake.bmp abraham_lake_gray.bmp
./a.out abraham_lake abraham_lake_.bmp
# open abraham_lake_gray.bmp
open abraham_lake_reduction.bmp
open abraham_lake_merged.bmp

