for((i = 1; i <= 10; i++)); do
    echo $i
    ./gen $1 > int
    ./a < int > out1
    ./brute < int > out2
    diff out1 out2 || break
done
