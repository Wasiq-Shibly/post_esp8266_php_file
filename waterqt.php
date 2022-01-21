<?php


$servername = "localhost";
$username = "root";
$password = "";
$dbname = "waterqt";

if ($_SERVER["REQUEST_METHOD"] == "POST" ) {


// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection  

$temperature=$_POST['temperature'];
$tdsValue=$_POST['tdsValue'];
echo $temperature;
echo $tdsValue;
}
?>