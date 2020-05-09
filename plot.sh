set terminal png
set output 'graph.png'

set xlabel "Iteration"
set ylabel "Time [s]"

set yrange [0.0 : 0.0001]



set title "vfork vs fork()"
set grid

set style data line

plot "benchmark.txt" using 1:2 title "fork()", \
     "benchmark.txt"  using 1:3 title "vfork()"