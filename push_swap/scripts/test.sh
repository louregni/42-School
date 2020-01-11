test_for_5_all() {
	min=100000
	max=0
	sum=0
	counter=0
	for a in {1..5}; do
		for b in {1..5}; do
			if [ "$b" != "$a" ]; then
				for c in {1..5}; do
					if [ "$c" != "$a" ] && [ "$c" != "$b" ]; then
						for d in {1..5}; do
							if [ "$d" != "$a" ] && [ "$d" != "$b" ] && [ "$d" != "$c" ]; then
								for e in {1..5}; do
									if [ "$e" != "$a" ] && [ "$e" != "$b" ] && [ "$e" != "$c" ] && [ "$e" != "$d" ]; then
										instruction="$(./push_swap $a $b $c $d $e)"
										nbinstruction=$(./push_swap $a $b $c $d $e | tr ' ' '\n' | wc -l | sed -e "s/[\t ]//g")
										result=$(./push_swap $a $b $c $d $e | tr ' ' '\n' | ./checker $a $b $c $d $e)
										counter=$(($counter + 1))
										sum=$(($sum + $nbinstruction))
										mean=$(($sum / $counter))
										if [ "$nbinstruction" -gt "$max" ]; then
											max=$nbinstruction
										fi
										if [ "$nbinstruction" -lt "$min" ]; then
											min=$nbinstruction
										fi
										if [ "$1" = "-5" ]; then
											printf "$a $b $c $d $e\tinstructions => $instruction\n"
										fi
										if [ "$1" = "-d" ]; then
											printf "$a $b $c $d $e\t$result\tinstructions => %4d\tmin / mean / max => %4d | %4d | %4d\n" $nbinstruction $min $mean $max
										elif [ "$1" = "-i" ]; then
											printf "instructions => %4d\tmin / mean / max\t=>\t%4d | %4d | %4d\n" $nbinstruction $min $mean $max
										fi
									fi
								done
							fi
						done
					fi
				done
			fi
		done
	done
	if [ "$1" != "-d" ] && [ "$1" != "-i" ]; then
		printf "min / mean / max\t=>\t%4d | %4d | %4d\n" $min $mean $max
	fi
}

test_number() {
	min=100000
	max=0
	sum=0
	counter=1
	for a in {1..100}; do
		number=$(./scripts/random.sh $1)
		instruction="$(./push_swap $number)"
		nbinstruction=$(./push_swap $number | tr ' ' '\n' | wc -l | sed -e "s/[\t ]//g")
		result=$(./push_swap $number | tr ' ' '\n' | ./checker $number)
		counter=$(($counter + 1))
		sum=$(($sum + $nbinstruction))
		mean=$(($sum / $counter))
		if [ "$nbinstruction" -gt "$max" ]; then
			max=$nbinstruction
		fi
		if [ "$nbinstruction" -lt "$min" ]; then
			min=$nbinstruction
		fi
		if [ "$2" = "-d" ]; then
			printf "$number\t$result\tinstructions => %4d\tmin / mean / max => %4d | %4d | %4d\n" $nbinstruction $min $mean $max
		elif [ "$2" = "-i" ]; then
			printf "instructions => %4d\tmin / mean / max\t=>\t%4d | %4d | %4d\n" $nbinstruction $min $mean $max
		fi
	done
	if [ "$2" != "-d" ] && [ "$2" != "-i" ]; then
		printf "min / mean / max\t=>\t%4d | %4d | %4d\n" $min $mean $max
	fi
}

if [ "$1" = "5all" ]; then
	test_for_5_all $2
elif [ "$1" != "" ]; then
	test_number $1 $2
else
	echo "usage: $0 [5all | number] [-d | -i]"
fi
