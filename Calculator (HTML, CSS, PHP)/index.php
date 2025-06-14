<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <title>PHP Calculator</title>
    <link rel="stylesheet" href="style.css" />
</head>
<body>
    <div class="container">
        <h1>PHP Calculator</h1>

        <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method="post" class="form">
            <input type="number" name="num01" placeholder="Number one" required />
            
            <select name="operator">
                <option value="add">+</option>
                <option value="substract">-</option>
                <option value="multiply">*</option>
                <option value="divide">/</option>
            </select>
            
            <input type="number" name="num02" placeholder="Number two" required />
            
            <button type="submit">Calculate</button>
        </form>

        <div class="result">
            <?php
                if ($_SERVER["REQUEST_METHOD"] == "POST"){
                    $num01 = filter_input(INPUT_POST, "num01", FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
                    $num02 = filter_input(INPUT_POST, "num02", FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
                    $operator = htmlspecialchars($_POST["operator"]);

                    $errors = false;

                    if (empty($num01) || empty($num02) || empty($operator)){
                        echo "<p class='error'>Error! Fill all the fields.</p>";
                        $errors = true;
                    } else if (!is_numeric($num01) || !is_numeric($num02)){
                        echo "<p class='error'>Error! Inputs must be numeric.</p>";
                        $errors = true;
                    }

                    if (!$errors){
                        $res = 0;
                        switch ($operator){
                            case "add":
                                $res = $num01 + $num02;
                                break;
                            case "substract":
                                $res = $num01 - $num02;
                                break;
                            case "multiply":
                                $res = $num01 * $num02;
                                break;
                            case "divide":
                                $res = $num02 != 0 ? $num01 / $num02 : "Division by zero error!";
                                break;
                            default:
                                echo "<p class='error'>Operator error!</p>";
                                $errors = true;
                        }

                        if (!$errors && is_numeric($res)){
                            echo "<p class='success'>The result is $res</p>";
                        } else if (!$errors){
                            echo "<p class='error'>$res</p>";
                        }
                    }
                }
            ?>
        </div>
    </div>
</body>
</html>
