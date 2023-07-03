<!DOCTYPE html>
<html>
<head>
  <title>Sensor Data</title>
  <link rel="stylesheet" href="https://cdn.datatables.net/1.10.25/css/dataTables.bootstrap5.min.css">
  <script src="https://cdn.datatables.net/1.10.25/js/jquery.dataTables.min.js"></script>
  <script src="https://cdn.datatables.net/1.10.25/js/dataTables.bootstrap5.min.js"></script>
  <script>
    $(document).ready(function() {
      $('#sensorData').DataTable();
    });
  </script>
</head>
<body>
  <table id="sensorData" class="table table-striped">
    <thead>
      <tr>
        <th>ID</th>
        <th>Sensor</th>
        <th>Location</th>
        <th>Value 1</th>
        <th>Value 2</th>
        <th>Value 3</th>
        <th>Timestamp</th>
      </tr>
    </thead>
    <tbody>
      <?php
        $servername = "localhost";
        // REPLACE with your Database name
        $dbname = "";
        // REPLACE with Database user
        $username = "";
        // REPLACE with Database user password
        $password = "";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT id, sensor, location, value1, value2, value3, reading_time FROM SensorData ORDER BY id DESC";

        if ($result = $conn->query($sql)) {
          while ($row = $result->fetch_assoc()) {
            $row_id = $row["id"];
            $row_sensor = $row["sensor"];
            $row_location = $row["location"];
            $row_value1 = $row["value1"];
            $row_value2 = $row["value2"];
            $row_value3 = $row["value3"];
            $row_reading_time = $row["reading_time"];
            // Uncomment to set timezone to -1 hour (you can change 1 to any number)
            //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));

            // Uncomment to set timezone to +4 hours (you can change 4 to any number)
            //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 4 hours"));

            echo '<tr>
                    <td>' . $row_id . '</td>
                    <td>' . $row_sensor . '</td>
                    <td>' . $row_location . '</td>
                    <td>' . $row_value1 . '</td>
                    <td>' . $row_value2 . '</td>
                    <td>' . $row_value3 . '</td>
                    <td>' . $row_reading_time . '</td>
                  </tr>';
          }
          $result->free();
        }
        $conn->close();
      ?>
       
    </tbody>
  </table>
  <script>
    $(document).ready(function() {
      $('#sensorData').DataTable();
    });
  </script>
</body>
</html>
