<!DOCTYPE html>
<html>

<head>
</head>

<body>
    <?php
    $domain = "localhost";
    $username = "root";
    $password = "";
    $dbname = "task12";
    $a = [];
    $conn = mysqli_connect($domain, $username, $password, $dbname);
    if ($conn->connect_error)
        die("Connection failed: " . $conn->connect_error);
    $sql = "SELECT * FROM rohith";
    $result = $conn->query($sql);
    echo "<br>";
    echo "<h2>BEFORE SORTING</h2>";
    echo "<table border='2'>";
    echo "<tr>";
    echo "<th>rollno</th><th>Name</th><th>sec</th></tr>";
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row["rollno"] . "</td>";
            echo "<td>" . $row["name"] . "</td>";
            echo "<td>" . $row["sec"] . "</td></tr>";
            array_push($a, $row["rollno"]);
        }
    } else
        echo "Table is Empty";
    echo "</table>";
    $n = count($a);
    for ($i = 0; $i < ($n - 1); $i++) {
        $pos = $i;
        for ($j = $i + 1; $j < $n; $j++) {
            if ($a[$pos] > $a[$j])
                $pos = $j;
        }
        if ($pos != $i) {
            $temp = $a[$i];
            $a[$i] = $a[$pos];
            $a[$pos] = $temp;
        }
    }
    $c = [];
    $d = [];
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            for ($i = 0; $i < $n; $i++) {
                if ($row["rollno"] == $a[$i]) {
                    $c[$i] = $row["name"];
                    $d[$i] = $row["sec"];
                }
            }
        }
    }
    echo "<br>";
    echo "<h2>AFTER SORTING</h2>";
    echo "<table border='2'>";
    echo "<tr>";
    echo "<th>rollno</th><th>NAME</th><th>sec</th></tr>";
    for ($i = 0; $i < $n; $i++) {
        echo "<tr>";
        echo "<td>" . $a[$i] . "</td>";
        echo "<td>" . $c[$i] . "</td>";
        echo "<td>" . $d[$i] . "</td></tr>";
    }
    echo "</table>";
    $conn->close();
    ?>
</body>

</html>