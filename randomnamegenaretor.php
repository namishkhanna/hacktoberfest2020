<?php



$list = array(); 
$marks= array();
$list_marks=array();
function getRandomName($len = 3) {
    //$word = array_merge(range('a', 'z'), range('A', 'Z'));
    $word = array_merge(range('a', 'z'));
    shuffle($word);
    return substr(implode($word), 0, $len);
}
echo "<pre>";

for ($i = 0; $i < 11; $i++) {
   $list[] = getRandomName();
   $marks[] = rand(10,100);
   $list_marks=array_combine($list, $marks);
}



 
 

echo"++++++++++++++++++++++++++++++++++++++++++++++++++Print the names and their marks sorted by name alphabetically+++++++++++++++++<br/>";

foreach ($list_marks as $key => $value){  
    echo "Student ".$key." got ".$value."<br/>";  
} 


?>
