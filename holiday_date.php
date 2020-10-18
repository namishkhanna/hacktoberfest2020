<?php
//default time zone
date_default_timezone_set("Asia/Jakarta");
//fungsi check tanggal merah
function tanggalMerah($value)
{
    $array = json_decode(file_get_contents("https://raw.githubusercontent.com/guangrei/Json-Indonesia-holidays/master/calendar.json"), true);

    //check tanggal merah berdasarkan libur nasional
    if (isset($array[$value])) :        echo "tanggal merah " . $array[$value]["deskripsi"];

    //check tanggal merah berdasarkan hari minggu
    elseif (
        date("D", strtotime($value)) === "Sun"
    ) :        echo "tanggal merah hari minggu";

    //bukan tanggal merah
    else : echo "bukan tanggal merah";
    endif;
}

//testing
$hari_ini = date("Ymd");

echo "<b>Check untuk hari ini (" . date("d-m-Y", strtotime($hari_ini)) . ")</b><br>";
tanggalMerah($hari_ini);
