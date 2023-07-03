-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jul 03, 2023 at 04:13 PM
-- Server version: 10.3.39-MariaDB
-- PHP Version: 8.1.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mpesaacademy_IoT2023`
--

-- --------------------------------------------------------

--
-- Table structure for table `SensorData`
--

CREATE TABLE `SensorData` (
  `id` int(6) UNSIGNED NOT NULL,
  `sensor` varchar(30) NOT NULL,
  `location` varchar(30) NOT NULL,
  `value1` varchar(10) DEFAULT NULL,
  `value2` varchar(10) DEFAULT NULL,
  `value3` varchar(10) DEFAULT NULL,
  `reading_time` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `SensorData`
--

INSERT INTO `SensorData` (`id`, `sensor`, `location`, `value1`, `value2`, `value3`, `reading_time`) VALUES
(1, 'TDS Sensor', 'MFA', '50', '40', '10', '2023-07-03 13:12:51'),
(2, 'TDS Sensor', 'MFA', '50', '40', '10', '2023-07-03 13:12:54'),
(3, 'TDS Sensor', 'MFA', '50', '40', '10', '2023-07-03 13:12:58');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `SensorData`
--
ALTER TABLE `SensorData`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `SensorData`
--
ALTER TABLE `SensorData`
  MODIFY `id` int(6) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
