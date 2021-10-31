function hanoi($n, $a,  $b, $c, $d) {
    if($n -eq 1) {
        "$a -> $d"
    } else{    
         hanoi ($n - 1) $a $c $d $b 
         hanoi 1 $a $b $d $c 
         hanoi ($n - 1) $b $a $d $c
    }
}
hanoi 4 "A" "B" "C" "D"