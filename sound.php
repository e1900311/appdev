<?php
$peaks = $_POST['peaks'];
$maxDB = $_POST['maxDB'];
$today = date("Y-m-d H:i:s");
$record = $today . ", Number of peaks: " . $peaks . ", Max db value: " . $maxDB . "\n";

$file = "sound.log";
if (file_exists($file))
    $fp = fopen($file, "a");
else
    $fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);
?>
