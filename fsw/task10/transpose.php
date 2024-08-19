<html>
    <form method="post">
        <label for="num1">Enter the number of rows</label>
        <input type="text" name="num1">
        <label for="num2">Enter the number of rows</label>
        <input type="text" name="num2">

        <button type="submit" name="submit">submit</button>
    </form>
</html>

<?php
    if(isset($_POST['submit'])) {
        $rows = $_POST['num1'];
        $cols = $_POST['num2'];

        $result = [];
        $k = 0;
        echo "The original matrix is <br>";
        for($i=0; $i<$rows; $i++) {
            for($j=0; $j<$cols; $j++) {
                $result[$i][$j] = $k++;
                echo $result[$i][$j] . " ";
            }
            echo "<br>";
        }
        for($i=0; $i<$cols; $i++) {
            for($j=0; $j<$rows; $j++) {
                echo $result[$i][$j] . " ";
            }
            echo "<br>";
        }
    }
?>
