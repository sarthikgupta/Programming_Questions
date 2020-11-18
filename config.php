<?php
$host = "heroassociation.utp.edu.my";
$userName = "root";
$password = "admin";
$dbName = "onlineApps";
// Create database connection
$conn = new mysqli($host, $userName, $password, $dbName);
// Check connection
if ($conn->connect_error) {
die("Connection failed: " . $conn->connect_error);
}
?>
