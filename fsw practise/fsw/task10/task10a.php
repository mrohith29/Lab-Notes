<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

    <style>
        table, td, th {
            border: 1px solid black;
            width: 35%;
            text-align: center;
        }

        table {
            margin: auto;
        }

        input, p {
            text-align: right;
            color: blue;
        }
    </style>
</head>
<body>
    <form method="post"> 
        <table>
            <caption><h2>simple calculator</h2></caption>
            <tr>
                <td>Num1</td>
                <td><input type="text" name="num1" ></td>
            </tr>
            
            <tr>
                <td>Num2</td>
                <td><input type="text" name="num2"></td>
            </tr>

            <tr><td colspan="2">
                <button type="submit" name="submit" value="calculate">calculate</button>
            </td></tr>
        </table>
    </form>
<table>

    <?php
        if(isset($_POST['submit'])) {
            $num1 = $_POST['num1'];
            $num2 = $_POST['num2'];
            if(is_numeric($num1) and is_numeric($num2)) {
                echo ("<tr><td>Addition: </td><td><p>".($num1+$num2)."</p></td></tr>");
                echo ("<tr><td>Subtraction: </td><td><p>".($num1-$num2)."</p></td></tr>");
                echo ("<tr><td>Multiplication: </td><td><p>".($num1*$num2)."</p></td></tr>");
                echo ("<tr><td>Division: </td><td><p>".($num1/$num2)."</p></td></tr>");
            } else {
                echo ("<script>alert('Enter valid number')</script>");
            }
        }
        ?>
        </table>

</body>
</html>