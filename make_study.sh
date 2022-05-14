#!/bin/bash

# Constants
input_dir=data
output_dir=datastudy
alpha_min=0.8
alpha_max=0.95
alpha_static=0.8
r_min=0.01
r_max=0.5
r_static=0.2

function run_study
{
	input="$input_dir/$1.txt"
	output="$output_dir/$2.data"
	./ranking_release $input $output $3 $4 $5 $6 $7 $8 $9
}

function run_batch_alpha
{
	n=$2
	alpha_step=$3
	for name in $1; do
		run_study $name "${name}_alpha" $n $alpha_min $alpha_max $alpha_step $r_static $r_static $r_static 1
	done
}

function run_batch_ratio
{
	n=$2
	r_step=$3
	for name in $1; do
		run_study $name "${name}_ratio" $n $alpha_static $alpha_static 1 $r_min $r_max $r_step
	done
}

# Initialization
if [ ! -d $input_dir ]; then
	echo 'Input directory not found.'
	echo "Please adds graph files to $input_dir directory."
	exit 1
fi
make -j
mkdir -p datastudy

# <= 1M
run_batch_alpha 'wb-cs-stanford' 100 0.01
run_batch_ratio 'wb-cs-stanford' 10 0.01
# <= 50M
run_batch_alpha 'Stanford' 100 0.02
run_batch_ratio 'Stanford' 10 0.02
# <= 150M
run_batch_alpha 'Stanford_BerkeleyV2' 100 0.02
run_batch_ratio 'Stanford_BerkeleyV2' 10 0.02
# <= 500M
run_batch_alpha 'in-2004v2 wikipedia-20051105V2' 50 0.1
run_batch_ratio 'in-2004v2 wikipedia-20051105V2' 10 0.05
# > 500M
run_batch_alpha 'wb-edu' 50 0.5
run_batch_ratio 'wb-edu' 10 0.5

R CMD BATCH study.R
