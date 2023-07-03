<!DOCTYPE html>
<html>
<head>
  <title>Sensor Data</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
</head>
<body>
  <table id="sensorData" class="table table-striped table-bordered">
    <thead>
      <tr>
        <th>ID</th>
        <th>Sensor</th>
        <th>Location</th>
        <th>TDS Value</th>
        <th>Temperature</th>
        <th>Analog Reading</th>
        <th>Status</th>
        <th>Timestamp</th>
      </tr>
    </thead>
    <tbody>
      <?php
        $servername = "localhost";
        // REPLACE with your Database name
        $dbname = "XXXXXXXXX";
        // REPLACE with Database user
        $username = "XXXXXXXX";
        // REPLACE with Database user password
        $password = "XXXXXXXX";

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
            
            echo '<tr>
              <td>' . $row_id . '</td>
              <td>' . $row_sensor . '</td>
              <td>' . $row_location . '</td>
              <td>' . $row_value1 . '</td>
              <td>' . $row_value2 . '</td>
              <td>' . $row_value3 . '</td>
              <td>' . (($row_value1 > 100) ? "Medium" : (($row_value1 > 300) ? "High" :  "Low")) . '</td>
              <td>' . $row_reading_time . '</td>
            </tr>';
          }
          $result->free();
        }
        $conn->close();
      ?>
    </tbody>
  </table>
  
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>
