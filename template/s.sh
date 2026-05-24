for((i = 1; i <= 10; i++)); do
    echo $i
    ./a < in > out1
    ./brute < in > out2
    diff out1 out2 || break
done
